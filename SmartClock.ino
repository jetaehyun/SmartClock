#include <RGBmatrixPanel.h>
#include "WeatherIcons.h"

#define CLK 11 
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

int h, m, s;
String hS, mS, sS;
char timeBuf[9];   // HH:MM:SS
int charCount = 0;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);

void setup() {
  Serial.begin(115200);

  while(1) {
    if(Serial.available() > 0) {
      if(Serial.read() == '&') break;
    }
  }

  systemDelay(1000);
  while(Serial.available() > 0 && charCount < 6) {
    timeBuf[charCount++] = Serial.read();
  }
  timeBuf[charCount++] = '\0'; 
  charCount = 0;
  Serial.println(timeBuf);
  systemDelay(100);

  matrix.begin();
  matrix.setTextColor(matrix.ColorHSV(0, 1, 150, true));
  matrix.setTextWrap(false);
  matrix.drawRGBBitmap(0, 16, thunderstorms, 16, 16);
  matrix.drawRGBBitmap(15, 16, light_showers, 16, 16);
  matrix.drawRGBBitmap(32, 16, showers, 16, 16);
  matrix.drawRGBBitmap(48, 16, sunny_period, 16, 16);

  h = 0;
  m = 0;
  s = 0;
}

void loop() {
  systemDelay(1000);
  printTime();

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
        s++;
      }
    }
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