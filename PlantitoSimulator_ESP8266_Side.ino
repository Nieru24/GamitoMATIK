
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

//Replace with your Wifi Name
const char* ssid     = "ssid";
// Replace with your wifi Password
const char* password = "password";
//This is channelID
unsigned long channel3 =2104010;
//This is channel field
unsigned int led3 = 1;
WiFiClient  client;


void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(D3, OUTPUT);//Pin
  digitalWrite(D3, HIGH);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  //Making connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  //Display in Serial Monitor for Debug
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

void loop() {
 
  //get the last data of the fields
  int led_3 = ThingSpeak.readFloatField(channel3, led3);
 
  if(led_3 == 1){
    digitalWrite(D3, LOW);
    Serial.println("D3 is On..!");
  }
  else if(led_3 == 0){
    digitalWrite(D3, HIGH);
    Serial.println("D3 is Off..!");
  }
    
  Serial.println(led_3);
  delay(5000);
 
}
