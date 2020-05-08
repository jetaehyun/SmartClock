#include <Arduino.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <JsonListener.h>
#include <TwitterWebAPI.h>
#include <OpenWeatherMapForecast.h>

#define twiTimeout 2000

// Replace with your network credentials
const char* ssid     = "";
const char* password = "";

// NTP 
const char* ntpServer = "pool.ntp.org";
const long utcOffsetInSeconds = -4 * 60 * 60;

// Twitter Cred
const char* twi_key = "";
const char* twi_key_sec = "";
const char* twi_token = "";
const char* twi_token_sec = "";
char trendingTweet[64];

// OpenWeatherMap Cred/Data
const String API = "a697a406b377b5a3c6c25ac287a60bde";
const String LOCATION_ID = "4956184";
const String LANGUAGE = "en";
boolean isMETRIC = false;
const uint8_t MAX_FORECASTS = 4;
int tempData[4]; 
int weatherList[4];
OpenWeatherMapForecast weatherClient;

// Set web server port number to 80
WiFiServer server(80);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, utcOffsetInSeconds);
TwitterClient tc(timeClient, twi_key, twi_key_sec, twi_token, twi_token_sec);
 
void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to WiFi network
  // Serial.println();
  // Serial.print("Connecting to ");
  // Serial.println(ssid);
   
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

  delay(1);
  timeClient.update();
  tc.startNTP();
  sendTime(timeClient.getFormattedTime(), timeClient.getEpochTime());
  delay(500);
  sendTrendingTweets();
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
  client.println("<input type=time id='ALARM' name='ALARM'><br><br>");
  client.println("<input type=submit style='height:50px;width:100px;background-color:Orange'>");
  client.println("</FORM>");

  client.println("</body>");
  client.println("</html>");

 
  delay(1);
  // Serial.println("Client disconnected");
  // Serial.println("");
  if(req.indexOf("ALARM") > 0) {
    Serial.write(0x3F); // DEC = 63, Chr = ?
    Serial.write((int)req[12]); 
    Serial.write((int)req[13]);
    Serial.write((int)req[17]);
    Serial.write((int)req[18]);
  } else if(req.indexOf("WEATHER") > 0) {
    Serial.write(0x3C); // DEC = 60, Chr = <
    retrieveWeather();
    for(int i = 0; i < 4; i++) {
      Serial.write(weatherList[i]); 
    }
    // Serial.write(0x3A); // DEC = 58, Chr = :
    for(int i = 0; i < 4; i++) {
      Serial.write(tempData[i]); // send byte of tempInfo
    }
    // for(int i = 0; i < 4; i++) Serial.printf("weatherID: %d, tempData: %d\n", weatherList[i], tempData[i]);
    
  } else if(req.indexOf("RESET") > 0) {
    Serial.write(0x2B); // DEC = 43, Chr = +
  }
}

/**
 * @brief function to send data to Clock on time HHMMSS and the day of the week based on the EPOCH since Jan 1, 1970
 * 
 * @param time HH:MM:SS
 * @param epochTime long indicating time since Jan 1, 1970
 */
void sendTime(String time, unsigned long epochTime) {
  long day = epochTime / 86400L; // calc number of days since then
  int weekDay = day % 7; // get the day of the week
  Serial.write('&');
  for(int i = 0; i < time.length(); i++) {
    if(time[i] == ':') continue;
    Serial.print(time[i]);
  }
  Serial.print(weekDay);
}

/**
 * @brief function that gets weather data and stores unique ID for transmission
 * 
 */
void retrieveWeather() {
  OpenWeatherMapForecastData data[MAX_FORECASTS];
  weatherClient.setMetric(isMETRIC);
  weatherClient.setLanguage(LANGUAGE);
  uint8_t allowedHours[] = {12};
  weatherClient.setAllowedHours(allowedHours, 2);
  uint8_t foundForecasts = weatherClient.updateForecastsById(data, API, LOCATION_ID, MAX_FORECASTS);
  for(uint8_t i = 0; i < foundForecasts; i++) {
    tempData[i] = (int)data[i].temp;
    weatherList[i] = getWeatherID(data[i].main.c_str());
  }

}

/**
 * @brief function to transmit the top 3 trending # on twitter
 * 
 */
void sendTrendingTweets() {
  String trend = tc.searchTwitter(); // API function call was modifed to return trending data
  // Serial.println(trend);

  String trending = "";
  int end = 0;
  for(int i = 0; i < 3; i++) {
    int hashTag = trend.indexOf('#', end + i);
    int hashTagEnd = trend.indexOf(',', hashTag + 1) - 1;
    end = hashTagEnd;
    trending += trend.indexOf(hashTag, hashTagEnd);
  }
  // int first = trend.indexOf('#');
  // int firstEnd = trend.indexOf(',', first + 1) - 1;

  // int sec = trend.indexOf('#', first + 1);
  // int secEnd = trend.indexOf(',', sec + 1) - 1;

  // int third = trend.indexOf('#', sec + 1);
  // int thirdEnd = trend.indexOf(',', third + 1) - 1;
  // String trending = trend.substring(first, firstEnd) + trend.substring(sec, secEnd) + trend.substring(third, thirdEnd);
  trending.toCharArray(trendingTweet, trending.length() + 1);
  Serial.write(0x5E); // DEC = 43, Chr = ^
  for(int i = 0; i < trending.length(); i++) {
    delay(1); // needs time to process data, without this, the data will not be transmitted well to the clock
    Serial.write(trendingTweet[i]);
  }
}

/**
 * @brief function to return a corresponding ID to the group id returned by OpenWeatherMap
 * 
 * @param wID Main weather group ID returned by OpenWeatherMap
 * @return int ID indicating what the condition is
 */
int getWeatherID(String wID) {
  if     (wID.equals("ThunderStorm")) return 0;
  else if(wID.equals("Drizzle")) return 1;
  else if(wID.equals("Rain")) return 2;
  else if(wID.equals("Snow")) return 3;
  else if(wID.equals("Mist")) return 4;
  else if(wID.equals("Clear")) return 5;
  else if(wID.equals("Tornado")) return 6;
  else if(wID.equals("Clouds")) return 7;
  else if(wID.equals("Fog")) return 8;
  else return 9;
}