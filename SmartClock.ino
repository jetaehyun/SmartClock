#include <RGBmatrixPanel.h>
#include "WeatherIcons.h"

#define CLK 11 
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

enum state {
  normal,
  weather,
  alarm
};

byte incoming;

int h = 0, m = 0, s = 0;
String hS, mS, sS;
int tCount = 0;
int tInt[6];
char wID[4];

state st = normal;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

void setup() {
  Serial.begin(115200);

  while(1) {
    if(Serial.available() > 0) {
      if(Serial.read() == '&') break;
    }
  }

  systemDelay(100);
  while(Serial.available()) {
    incoming = Serial.read();
    tInt[tCount++] = incoming - '0';
  } 

  matrix.begin();
  convertTime();

}

void loop() {
  systemDelay(1000);
  if(Serial.available() > 0) {
    char SystemChange = Serial.read();
    delay(1);
    if(SystemChange == 'w') {
      st = weather;
      for(int i = 0; i < 4; i++) {
          wID[i] = Serial.read();
      }
      printWeather();
    }
    else if(SystemChange == '1') st == alarm;
  }
  
  switch(st) {
    case normal:
      printTime();
      break;
    case weather:
      // printWeather();
      break;
    case alarm:
      break;
  }


}

void printWeather() {
  matrix.setTextWrap(false);
  matrix.setCursor(0, 0);
  matrix.fillRect(0, 0, 63, 14, matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.ColorHSV(0, 1, 150, true));
  ptrToWeather(wID[0], 0, 16);
  ptrToWeather(wID[1], 15, 16);
  ptrToWeather(wID[2], 32, 16);
  ptrToWeather(wID[3], 48, 16);
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
void ptrToWeather(char code, int x, int y) {
  if(code == '0') matrix.drawRGBBitmap(x, y, thunderstorms, 16, 16);
  else if(code == '1') matrix.drawRGBBitmap(x, y, light_rain, 16, 16);
  else if(code == '2') matrix.drawRGBBitmap(x, y, rain, 16, 16);
  else if(code == '3') matrix.drawRGBBitmap(x, y, snow, 16, 16);
  else if(code == '4') matrix.drawRGBBitmap(x, y, showers, 16, 16);
  else if(code == '5') matrix.drawRGBBitmap(x, y, sunny_period, 16, 16);
  else if(code == '6') matrix.drawRGBBitmap(x, y, storm, 16, 16);
  else if(code == '7') matrix.drawRGBBitmap(x, y, cloudy, 16, 16);
  else if(code == '8') matrix.drawRGBBitmap(x, y, foggy, 16, 16);
}

void printTime() {
  updateTime();
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
  s = (tInt[4] * 10 + tInt[5]) + 3; // 3 is the offset based on the delays from clock and server
  m = tInt[2] * 10 + tInt[3];
  h = tInt[0] * 10 + tInt[1];
  // Serial.println(s);
  // Serial.println(m);
  // Serial.println(h);
}

void updateTime() {
  s++;
  if(s >= 60) {
    s = 0;
    m++;
  }
  if(m >= 60) {
    m = 0;
    h++;
  }
  if(h >= 24) {
    h = 0;
    s++;
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

