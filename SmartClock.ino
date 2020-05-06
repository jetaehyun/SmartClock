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
 * - alarm information
 *  - Ability to disable/enable alarm
 * - Make weather display better
 *  - Display rgb value of the temp???
 * 
 * 
 * TODO: Things to worry about later
 * - Clock is still inaccurate, by a few seconds
 * - Clean up code
 * - The clock has a lot of empty room initially, should I add in a news API?
 * 
 */

enum state {
  normal,
  checkWeather,
  alarm
};

char incoming;

volatile int h = 0, m = 0, s = 0;
int alarmH = -1, alarmM = -1;
int dayOfWeekID = 0;
long unsigned int startTime = 0;
String hS, mS, sS;
int wID[8];
int alarmBuf[4];

state st = normal;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);
char message[] = "HELLO WORLD I AM BOI";
int16_t textX = matrix.width(), textMin = sizeof(message) * -12;

void setup() {
  MCUSR = 0; // set for WatchdogTimer

  // Enable timer5 interrupt; timer5 is 16bits
  noInterrupts();    
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT5 = 0; //set counter value to 0
  OCR5A = 15624; // set compare match register for 1Hz, output compare register
  TCCR5B |= (1 << WGM12); // set timer to CTC mode
  TCCR5B |= (1 << CS12) | (1 << CS10); // set to 1024 prescalar mode
  TIMSK5 |= (1 << OCIE5A); // enable timer compare interrupt
  interrupts();

  Serial.begin(115200);
  delay(10);
  int timeBuf[7];
  int tCount = 0;

  while(1) {
    if(Serial.read() == '&') {
      systemDelay(100);
      while(Serial.available() > 0) {
        incoming = Serial.read();
        timeBuf[tCount++] = incoming - '0';  // receiving the decimal value of the char number.. so 51 - 48 = 3
      } 
      break;
    }
  }
  s = (timeBuf[4] * 10 + timeBuf[5]);
  m = timeBuf[2] * 10 + timeBuf[3];
  h = timeBuf[0] * 10 + timeBuf[1];
  dayOfWeekID = timeBuf[6];

  matrix.begin();
  matrix.setTextWrap(false);
}

void loop() {
  if(Serial.available() > 0) {
    // Baud rate is very high, so without a long delay, 
    // the system ignores an incoming msg because it has not arrived yet
    systemDelay(800); 
    checkMessage();
  }
  switch(st) {
    case normal:
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
  matrix.setTextColor(matrix.ColorHSV(45, 255, 255, true));
  matrix.setCursor(textX, 20);
  matrix.print(message);
  if((--textX) < textMin) textX = matrix.width();

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
      wID[data++] = (int)Serial.read(); // coming in as byte
    }
    // for(int i = 0; i < 8; i++) Serial.println(wID[i]);
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
  drawWeather(wID[0], 0, 0);
  drawWeather(wID[1], 15, 16);
  drawWeather(wID[2], 32, 0);
  drawWeather(wID[3], 48, 16);

  // PRINT DAY OF WEEK 
  matrix.setCursor(2, 24);
  matrix.print(nameOfDay(dayOfWeekID % 7));
  matrix.setCursor(19, 8);
  matrix.print(nameOfDay((dayOfWeekID + 1) % 7));
  matrix.setCursor(34, 24);
  matrix.print(nameOfDay((dayOfWeekID + 2) % 7)); 
  matrix.setCursor(51, 8);
  matrix.print(nameOfDay((dayOfWeekID + 3) % 7)); 

  // PRINT TEMP IN F
  matrix.setCursor(2, 16);
  matrix.print(wID[4]);
  matrix.setCursor(19, 0);
  matrix.print(wID[5]);
  matrix.setCursor(34, 16);
  matrix.print(wID[6]);
  matrix.setCursor(51, 0);
  matrix.print(wID[7]); 
 
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
  matrix.setCursor(0, 0);
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
}

/**
 * @brief function to get the name of the day
 * 
 * @param day days since Jan 1, 1970. Day is obtained from EPOCH since then, obtained from ESP module
 * @return String returns the string of the day
 */
String nameOfDay(int day) {
  if(day == 0) return "TH";
  else if(day == 1) return "FR";
  else if(day == 2) return "SA";
  else if(day == 3) return "SU";
  else if(day == 4) return "MO";
  else if(day == 5) return "TU";
  else if(day == 6) return "WE";
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
      if(h >= 24) {
        h = 0;
      } 
    }
  } 

  if(alarmH == h && alarmM == m) st = alarm; 
}

