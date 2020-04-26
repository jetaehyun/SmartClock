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

int h = 0, m = 0, s = 0;
String hS, mS, sS;
// char timeBuf[7];   // HH:MM:SS  ;  {H, H, M, M, S, S, \0}
byte incoming;
int tCount = 0;
int tInt[6];
state s = normal;

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
  matrix.setTextColor(matrix.ColorHSV(0, 1, 150, true));
  matrix.setTextWrap(false);
  matrix.drawRGBBitmap(0, 16, thunderstorms, 16, 16);
  matrix.drawRGBBitmap(15, 16, light_showers, 16, 16);
  matrix.drawRGBBitmap(32, 16, showers, 16, 16);
  matrix.drawRGBBitmap(48, 16, sunny_period, 16, 16);
  convertTime();

}

void loop() {
  if(Serial.available() > 0) {
    char SystemChange = Serial.read();
    if(SystemChange == '0') s = weather;
    else if(SystemChange == '1') s == alarm;
  }
  
  switch(s) {
    case normal:
      systemDelay(1000);
      printTime();
      break;
    case weather:
      break;
    case alarm:
      break;
  }


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

void convertTime() {  
  s = (tInt[4] * 10 + tInt[5]) + 3;
  m = tInt[2] * 10 + tInt[3];
  h = tInt[0] * 10 + tInt[1];
  Serial.println(s);
  Serial.println(m);
  Serial.println(h);
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