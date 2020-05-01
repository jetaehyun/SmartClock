#include <RGBmatrixPanel.h>
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
 *  - set values for alarm
 *  - Ability to disable/enable alarm
 *  - make the system go off at designated time
 * - Make weather display better
 *  - Icons indicating temperature???
 *  - Display rgb value of the temp???
 * - System needs to be able to return to clock display
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
  alarm
};

byte incoming;

int h = 0, m = 0, s = 0;
int alarmH = 0, alarmM = 0, alarmS = 0;
bool isAlarm = false;
String hS, mS, sS;
int tCount = 0;
int tInt[6];
int wID[4];

state st = normal;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

void setup() {
  Serial.begin(115200);

  while(1) {
    if(Serial.available() > 0) {
      if(Serial.read() == '&') break;
    }
  }

  systemDelay(100); // wait for data to come in
  while(Serial.available() > 0) {
    incoming = Serial.read();
    tInt[tCount++] = incoming - '0';
    if(tCount == 4) break;
  } 

  matrix.begin();
  convertTime();

}

void loop() {
  systemDelay(1000);
  updateTime();
  checkMessage();
  
  switch(st) {
    case normal:
      printTime();
      break;
    case alarm:
      break;
  }
}

void checkMessage() {
  int data = 0;
  if(Serial.available() > 0) { // only thing coming in after char check is int
    char SystemChange = Serial.read();
    systemDelay(1);
    while(Serial.available() > 0) { 
        wID[data++] = Serial.read() - '0';
    }
    if(SystemChange == 'w') {
      printWeather();
    } else if(SystemChange == 't') {
      alarm = true;
      setAlarm();
    }
    st = alarm;
  }
}

void setAlarm() {

}

void printWeather() {
  matrix.setTextWrap(false);
  matrix.setCursor(0, 0);
  matrix.fillRect(0, 0, 63, 14, matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.ColorHSV(0, 1, 150, true));
  drawWeather(wID[0], 0, 0);
  drawWeather(wID[1], 15, 16);
  drawWeather(wID[2], 32, 0);
  drawWeather(wID[3], 48, 16);
  // for(int i = 0; i < 4; i++) {
  //   Serial.println(wID[i]);
  // }
  matrix.swapBuffers(true);
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
  if(code == 0) matrix.drawRGBBitmap(x, y, thunderstorms, 16, 16);
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
  matrix.fillRect(0, 0, 63, 14, matrix.Color333(0, 0, 0));
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
  matrix.swapBuffers(true);
}

void convertTime() {  
  s = (tInt[4] * 10 + tInt[5]) + 4; // 4 is the offset based on the delays
  m = tInt[2] * 10 + tInt[3];
  h = tInt[0] * 10 + tInt[1];
  // Serial.println(s);
  // Serial.println(m);
  // Serial.println(h);
}

void updateTime() {
  s++;
  if(s == 60) {
    s = 0;
    m++;
  }
  if(m == 60) {
    m = 0;
    h++;
  }
  if(h == 24) {
    h = 0;
  }  
    
  mS = String(m);
  hS = String(h);
  sS = String(s);
  if(s < 10) sS = '0' + sS;
  if(m < 10) mS = '0' + mS;
  if(h < 10) hS = '0' + hS;
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

