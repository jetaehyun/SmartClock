#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid     = "NETWORKID";
const char* password = "PASSWORD";


// Set web server port number to 80
// int ledPin = 2; // GPIO2 of ESP8266
WiFiServer server(80);
 
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
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
   
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");    
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("New Client...");
  
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

  // HTML code for GET requests
  client.println("<br><br>");
  client.println("<HEAD>SmartClock</HEAD><br><br>");

  client.println("<FORM ACTION='/' method=get >"); 
  client.println("<input type=submit name='WEATHER' value='Weather'><br><br>");
  client.println("</FORM>");  
  
  client.println("<FORM ACTION='/' method=get >"); 
  client.println("<input type=submit name='RESET' value='Reset'><br><br>");
  client.println("</FORM>");

  client.println("<FORM ACTION='/' method=get >"); 
  client.println("<input type=submit for='t'> Set the alarm");
  client.println("<input type=time name='TIME' value='' id='t'><br><br>");
  client.println("</FORM>");
  client.println("</html>");

 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");

  if(req.indexOf("TIME") > 0) {
    Serial.println("TIME");
  } else if( req.indexOf("WEATHER") > 0) {
    Serial.println("WEATHER");
  } else if(req.indexOf("RESET") > 0) {
    Serial.println("RESET");
  }
}