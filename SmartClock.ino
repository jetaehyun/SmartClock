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

int h = 0, m = 0, s = 0;
int alarmH = 0, alarmM = 0;
bool isWeather = true;
long unsigned int startTime = 0;
String hS, mS, sS;
int wID[8];
int alarmBuf[4];

state st = normal;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

void setup() {
  MCUSR = 0;
  Serial.begin(115200);
  int timeBuf[6];
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
  s = (timeBuf[4] * 10 + timeBuf[5]) + 4; // 4 is the offset based on the delays
  m = timeBuf[2] * 10 + timeBuf[3];
  h = timeBuf[0] * 10 + timeBuf[1];
  matrix.begin();
  matrix.setTextWrap(false);
}

void loop() {
  delay(1000);
  updateTime();
  checkMessage();
  
  switch(st) {
    case normal:
      printTime();
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

void checkMessage() {
  if(Serial.available() > 0) { 
    int data = 0;
    byte recData = Serial.read();
    systemDelay(200);
    if(recData == 0x3C && isWeather) { // weather information
      while(Serial.available() > 0) {
        wID[data++] = (int)Serial.read();
      }
      isWeather = false;
      printWeather();
      startTime = millis();
      st = checkWeather;
    } else if(recData == 0x3F) { // alarm state
      while(Serial.available() > 0) {
        alarmBuf[data++] = Serial.read() - '0';
      }
      // isAlarm = true;
      setAlarm();
    } else if(recData == 0x2B) { // reset system
      resetClock();
    }
    flushBuffer();

  }
}

void exitWeather() {
  if(!isWeather) {
    long unsigned int currentTime = millis();
    if(currentTime - startTime > 8000) {
      isWeather = true;
      st = normal;
    }
  }
}

void setAlarm() {
  alarmH = alarmBuf[0] * 10 + alarmBuf[1];
  alarmM = alarmBuf[2] * 10 + alarmBuf[3];
  Serial.println(alarmH);
  Serial.println(alarmM);
}

void printWeather() {
  matrix.setTextWrap(false);
  matrix.setCursor(0, 0);
  matrix.fillRect(0, 0, 64, 32, matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.ColorHSV(0, 1, 150, true));
  drawWeather(wID[0], 0, 0);
  drawWeather(wID[1], 15, 16);
  drawWeather(wID[2], 32, 0);
  drawWeather(wID[3], 48, 16);
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

void printTime() {
  matrix.setCursor(0, 0);
  matrix.fillRect(0, 0, 64, 32, matrix.Color333(0, 0, 0));
  matrix.setCursor(0, 0);
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

void updateTime() {
  s++;
  if(s == 60) {
    s = 0;
    m++;
    if(m == 60) {
      m = 0;
      h++;
      if(h == 24) {
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

