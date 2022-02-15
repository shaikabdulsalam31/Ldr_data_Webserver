#include <ESP8266WiFi.h>

#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "Net 2.0";
const char* password = "Error1234asdf#";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
double data; 
void setup(){
 
  pinMode(A0, INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid,password );
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMcu connected to wifi...");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
server.begin();
server.on("/", [](){
    page = "<h1>Sensor to Node MCU Web Server</h1><h3>Data:</h3> <h4>"+String(data)+"</h4>";
    server.send(200, "text/html", page);
  });
  Serial.println("Web server started!");
}
 
void loop(){
    
  data = analogRead(A0);
  delay(1000);
  server.handleClient();
}
