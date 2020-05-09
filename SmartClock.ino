#include <RGBmatrixPanel.h>
#include <avr/wdt.h>
#include "WeatherIcons.h"

#define CLK 11 
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3


/**
 * TODO: Things still needed
 * - Make weather display better
 *  - Display rgb value of the temp???
 * 
 * 
 * TODO: Things to worry about later
 * - Clean up code
 * 
 */

enum state {
  normal,
  checkWeather,
  alarm
};
state st = normal;

volatile int h = 0, m = 0, s = 0;
volatile bool getTweet = false;
int alarmH = -1, alarmM = -1;
int dayOfWeek = 0;
int dayOfMonth = 0;
int monthN = 0;
long unsigned int startTime = 0;
String hS, mS, sS;


int weatherBuf[8];
int alarmBuf[4];
char messageBuf[64];

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);
int16_t textX = matrix.width(), textMin = 0;

void setup() {
  MCUSR = 0; // set for WatchdogTimer

  // Enable timer5 interrupt; timer5 is 16bits
  cli();
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT5 = 0; //set counter value to 0
  OCR5A = 15624; // set compare match register for 1Hz, output compare register
  TCCR5B |= (1 << WGM12); // set timer to CTC mode
  TCCR5B |= (1 << CS12) | (1 << CS10); // set to 1024 prescalar mode
  TIMSK5 |= (1 << OCIE5A); // enable timer compare interrupt
  sei();

  Serial.begin(115200);
  delay(10);
  int timeBuf[9];
  int tCount = 0;

  while(1) {
    if(Serial.read() == '&') {
      systemDelay(100);
      while(Serial.available() > 0) {
        timeBuf[tCount++] = Serial.read() - '0';  // receiving the decimal value of the char number.. so 51 - 48 = 3
      }
      break; 
    }
  }

  s = (timeBuf[4] * 10 + timeBuf[5]);
  m = timeBuf[2] * 10 + timeBuf[3];
  h = timeBuf[0] * 10 + timeBuf[1];
  dayOfWeek = timeBuf[6];
  dayOfMonth = timeBuf[8];
  monthN = timeBuf[7];

  matrix.begin();
  matrix.setTextWrap(false);
}

void loop() {
  if(getTweet) { // at every hour, this condition will run.
    Serial.write(0x7E);
    getTweet = false;
  }

  if(Serial.available() > 0) {
    // Baud rate is very high, so without a long delay, 
    // the system ignores an incoming msg because it has not arrived yet
    systemDelay(800);
    checkMessage();
  }
  switch(st) {
    case normal:
      if(dayOfWeek >= 7) dayOfWeek = 0;
      if(monthN >= 12) monthN = 1;  
      printTime();
      displayNews();
      break;
    case checkWeather:
      exitWeather();
      break;
    case alarm:
      Serial.println("WAKE UP");
      st = normal;
      break;
  }
  matrix.swapBuffers(true);
}

void displayNews() {
  if((--textX) < textMin) textX = matrix.width();
  matrix.setTextColor(matrix.ColorHSV(45, 255, 255, true));
  matrix.setCursor(textX, 25);
  matrix.print(messageBuf);
}

/**
 * @brief function reads data and stores them into their appropriate buffers
 *   **Could be updated to include a single buffer**
 */
void checkMessage() {
  int data = 0;
  byte recData = Serial.read();
  // Serial.println(recData);
  if(recData == 0x3C) { // weather information
    while(Serial.available() > 0) {
      weatherBuf[data++] = (int)Serial.read(); // coming in as byte
    }
    printWeather();
    startTime = millis();
    st = checkWeather;
  } else if(recData == 0x3F) { // alarm state
    while(Serial.available() > 0) {
      alarmBuf[data++] = Serial.read() - '0';
    }
    setAlarm();
  } else if(recData == 0x2B) { // reset system
    resetClock();
  } else if(recData == 0x5E) {
    while(Serial.available() > 0 && data < 64) {
      char m = (char)Serial.read();
      if(m == '#' && data != 0) messageBuf[data++] = ' ';
      messageBuf[data++] = m;
    }
    textMin = -1 * (sizeof(messageBuf) * 5);
  }
  flushBuffer();
}

/**
 * @brief print out weather information
 * 
 */
void printWeather() {
  matrix.setCursor(0, 0);
  matrix.fillScreen(0);
  matrix.setTextColor(matrix.ColorHSV(0, 1, 150, true));
  matrix.setTextSize(1);

  // PRINT WEATHER ICONS
  drawWeather(weatherBuf[0], 0, 0);
  drawWeather(weatherBuf[1], 15, 16);
  drawWeather(weatherBuf[2], 32, 0);
  drawWeather(weatherBuf[3], 48, 16);

  // PRINT DAY OF WEEK 
  matrix.setCursor(2, 24);
  matrix.print(nameOfDay(dayOfWeek % 7));
  matrix.setCursor(19, 8);
  matrix.print(nameOfDay((dayOfWeek + 1) % 7));
  matrix.setCursor(34, 24);
  matrix.print(nameOfDay((dayOfWeek + 2) % 7)); 
  matrix.setCursor(51, 8);
  matrix.print(nameOfDay((dayOfWeek + 3) % 7)); 

  // PRINT TEMP IN F
  matrix.setCursor(2, 16);
  matrix.print(weatherBuf[4]);
  matrix.setCursor(19, 0);
  matrix.print(weatherBuf[5]);
  matrix.setCursor(34, 16);
  matrix.print(weatherBuf[6]);
  matrix.setCursor(51, 0);
  matrix.print(weatherBuf[7]); 
 
}

/**
 * @brief function to print weather icon based on weather code
 * Weather Code:
 * 0 = thunderstorm
 * 1 = Drizzle
 * 2 = Rain
 * 3 = Snow
 * 4 = Mist
 * 5 = Clear
 * 6 = Tornado
 * 7 = Clouds
 * 8 = Fog
 * 9 = IGNORE
 * @param code unique weather id
 * @param x x position of the image
 * @param y y position of the image
 */
void drawWeather(int code, int x, int y) {
  if     (code == 0) matrix.drawRGBBitmap(x, y, thunderstorms, 16, 16);
  else if(code == 1) matrix.drawRGBBitmap(x, y, light_rain, 16, 16);
  else if(code == 2) matrix.drawRGBBitmap(x, y, rain, 16, 16);
  else if(code == 3) matrix.drawRGBBitmap(x, y, snow, 16, 16);
  else if(code == 4) matrix.drawRGBBitmap(x, y, showers, 16, 16);
  else if(code == 5) matrix.drawRGBBitmap(x, y, sunny_period, 16, 16);
  else if(code == 6) matrix.drawRGBBitmap(x, y, storm, 16, 16);
  else if(code == 7) matrix.drawRGBBitmap(x, y, cloudy, 16, 16);
  else if(code == 8) matrix.drawRGBBitmap(x, y, foggy, 16, 16);
}

/**
 * @brief helper function to print out the time on the matrix
 * 
 */
void printTime() {
  mS = String(m);
  hS = String(h);
  sS = String(s);
  if(s < 10) sS = '0' + sS;
  if(m < 10) mS = '0' + mS;
  if(h < 10) hS = '0' + hS;
  matrix.setCursor(0, 0);
  matrix.fillScreen(0);
  matrix.setTextColor(matrix.Color333(255, 255, 255));
  matrix.setTextSize(2);
  matrix.print(hS);
  matrix.setCursor(19, 0);
  matrix.print(":");
  matrix.setCursor(26, 0);
  matrix.print(mS);
  matrix.setTextSize(1);
  matrix.setCursor(49, 7);
  matrix.print(sS);
  matrix.setCursor(0, 16);
  matrix.print(nameOfDay(dayOfWeek));
  matrix.print(nameOfMonth(monthN));
  matrix.print(dayOfMonth);
}

/**
 * @brief function to get the name of the day
 * 
 * @param dayWeek 0 - Sun
 * @return String returns the string of the day
 */
String nameOfDay(int dayWeek) {
  if     (dayWeek == 0) return "SU";
  else if(dayWeek == 1) return "MO";
  else if(dayWeek == 2) return "TU";
  else if(dayWeek == 3) return "WE";
  else if(dayWeek == 4) return "TH";
  else if(dayWeek == 5) return "FR";
  else if(dayWeek == 6) return "SA";
  else return "EMPTY";
}

/**
 * @brief function to get the name of the month
 * 
 * @param m int correlating with the month number
 * @return String 1 - January
 */
String nameOfMonth(int m) {
  if     (m == 1) return " January ";
  else if(m == 2) return " February ";
  else if(m == 3) return " March ";
  else if(m == 4) return " April ";
  else if(m == 5) return " May ";
  else if(m == 6) return " June ";
  else if(m == 7) return " July ";
  else if(m == 8) return " August ";
  else if(m == 9) return " September ";
  else if(m == 10) return " Octber ";
  else if(m == 11) return " November ";
  else if(m == 12) return " December ";
  else return "EMPTY";
}

/**
 * @brief function to exit weather state after 8 secs since state change elapsed
 * 
 */
void exitWeather() {
  long unsigned int currentTime = millis();
  if(currentTime - startTime > 8000) {
    st = normal;
  }
}

/**
 * @brief helper function that sets the global variables based on the data from alarmBuf
 * 
 */
void setAlarm() {
  alarmH = alarmBuf[0] * 10 + alarmBuf[1];
  alarmM = alarmBuf[2] * 10 + alarmBuf[3];
  // Serial.println(alarmH);
  // Serial.println(alarmM);
}

/**
 * @brief deprecated code
 * 
 */
void updateTime() {
  s++;
  if(s >= 60) {
    s = 0;
    m++;
    if(m >= 60) {
      m = 0;
      h++;
      if(h >= 24) {
        h = 0;
      } 
    }
  } 
  if(alarmH == h && alarmM == m) st = alarm;  
  mS = String(m);
  hS = String(h);
  sS = String(s);
  if(s < 10) sS = '0' + sS;
  if(m < 10) mS = '0' + mS;
  if(h < 10) hS = '0' + hS;
}

/**
 * @brief function to empty out the data buffer
 * 
 */
void flushBuffer() {
  while(Serial.available() > 0) Serial.read();
}

/**
 * @brief enables WatchDogTimer and idles system to trigger it - causing reset
 * 
 */
void resetClock() {
  wdt_enable(WDTO_30MS);
  while(1) {}
}

/*
    function is used to pause system. Purpose is to avoid using Delay()
    @param int wait, 1000 = 1 sec
    @return nothing
*/
void systemDelay(int wait) {
  long unsigned int timeStamp = millis();
  while ((millis() - timeStamp) < wait) { // wait designated time
    // do nothing
  }
}

/**
 * @brief Construct a new ISR object, increments s, m, h and changes st to alarm if triggered
 * 
 */
ISR(TIMER5_COMPA_vect) {
  s++;
  if(s >= 60) {
    s = 0;
    m++;
    if(m >= 60) {
      m = 0;
      h++;
      getTweet = true;
      if(h >= 24) {
        h = 0;
        dayOfMonth++;
        dayOfWeek++;
      } 
    }
  } 
  if(alarmH == h && alarmM == m && s == 0) st = alarm;
}

