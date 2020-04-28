#include <Arduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <JsonListener.h>
// #include <time.h>
#include "OpenWeatherMapForecast.h"

// Replace with your network credentials
const char* ssid     = "";
const char* password = "";

// ntp, API key, etc...
const char* ntpServer = "pool.ntp.org";
const long utcOffsetInSeconds = -4 * 60 * 60;
const String API = "";
const String LOCATION_ID = "4956184";
const String LANGUAGE = "en";
boolean isMETRIC = false;
const uint8_t MAX_FORECASTS = 4;
int weatherList[4];


OpenWeatherMapForecast weatherClient;

// Set web server port number to 80
WiFiServer server(80);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, utcOffsetInSeconds);
 
void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    // Serial.print(".");
  }
  // Serial.println("");
  // Serial.println("WiFi connected");

  timeClient.begin();
   
  // Start the server
  server.begin();
  // Serial.println("Server started");
 
  // Print the IP address
  // Serial.print("Use this URL to connect: ");
  // Serial.print("http://");
  // Serial.print(WiFi.localIP());
  // Serial.println("/");    

  timeClient.update();
  sendTime(timeClient.getFormattedTime());
  delay(1000);
}
 
void loop() {

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  // Serial.println("New Client...");
  
  while(!client.available()){
    delay(1);
  }
   
  // read GET request 
  String req = client.readStringUntil('\n');
  // Serial.println(req);  //print request
  client.flush();
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<body>");
  client.println("<body style='background-color:rgb(229, 255, 223)'>");

  // HTML code for GET requests
  client.println("<br><br>");
  client.println("<HEAD><center><font size=+2><b>SmartClock</b></font></center></HEAD><br><br>");

  client.println("<FORM ACTION='/' method=get ><center>"); 
  client.println("<input type=submit style='height:50px;width:100px;background-color:Orange' name='WEATHER' value='Weather'>");
  client.println("</HEAD></FORM><br><br>");  
  
  client.println("<FORM ACTION='/' method=get >"); 
  client.println("<input type=submit style='height:50px;width:100px;background-color:Orange' name='RESET' value='Reset'><br><br>");
  client.println("</FORM>");

  client.println("<FORM ACTION='/' method=get >"); 
  client.println("<input type=submit name='ALARM' value='Alarm' style='height:50px;width:100px;background-color:Orange' for='t'>");
  client.println("<input type=time id='t'><br><br>");
  client.println("</FORM>");

  client.println("</body>");
  client.println("</html>");

 
  delay(1);
  // Serial.println("Client disconnected");
  // Serial.println("");

  if(req.indexOf("ALARM") > 0) {
    Serial.write("t");
  } else if( req.indexOf("WEATHER") > 0) {
    // int* idOfWeather = retrieveWeather();
    Serial.write('w');
    retrieveWeather();
    for(int i = 0; i < 4; i++) {
      Serial.print(weatherList[i]);
    }
  } else if(req.indexOf("RESET") > 0) {
    Serial.println("r");
  }
}

void sendTime(String time) {
  Serial.write('&');
  for(int i = 0; i < time.length(); i++) {
    if(time[i] == ':') continue;
    Serial.print(time[i]);
  }
}

/**
 * @brief function that returns a pointer to an array of weather IDs
 * 
 * @return int* pointer to an int array
 */
void retrieveWeather() {
  OpenWeatherMapForecastData data[MAX_FORECASTS];
  weatherClient.setMetric(isMETRIC);
  weatherClient.setLanguage(LANGUAGE);
  uint8_t allowedHours[] = {0, 12};
  weatherClient.setAllowedHours(allowedHours, 2);
  uint8_t foundForecasts = weatherClient.updateForecastsById(data, API, LOCATION_ID, MAX_FORECASTS);

  for(uint8_t i = 0; i < foundForecasts; i++) {
    // Serial.printf("temp: %f\n", data[i].temp);
    // Serial.printf("tempMin: %f\n", data[i].tempMin);
    // Serial.printf("tempMax: %f\n", data[i].tempMax);
    // Serial.printf("description: %s\n", data[i].description.c_str());
    // Serial.printf("icon: %s\n", data[i].icon.c_str());
    // Serial.printf("weatherId: %d\n", data[i].weatherId);
    String w = data[i].main.c_str();
    weatherList[i] = getWeatherID(w);
  }
  // return weatherList;
}

/**
 * @brief function to return a corresponding ID to the group id returned by OpenWeatherMap
 * 
 * @param wMain Main weather group ID returned by OpenWeatherMap
 * @return int ID indicating what the condition is
 */
int getWeatherID(String wMain) {
  if(wMain.equals("ThunderStorm")) return 0;
  else if(wMain.equals("Drizzle")) return 1;
  else if(wMain.equals("Rain")) return 2;
  else if(wMain.equals("Snow")) return 3;
  else if(wMain.equals("Mist")) return 4;
  else if(wMain.equals("Clear")) return 5;
  else if(wMain.equals("Tornado")) return 6;
  else if(wMain.equals("Clouds")) return 7;
  else if(wMain.equals("Fog")) return 8;
  else return 9;
}