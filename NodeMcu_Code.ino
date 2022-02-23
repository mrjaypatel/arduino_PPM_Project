#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "hotspot";   // Your Network SSID
const char* password = "87654321";       // Your Network Password

int val;
int pin = A0; //LM53 Pin Connected at A0 Pin

WiFiClient client;

unsigned long myChannelNumber = 1659891; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "XMWGF0QSNF51XPFC"; //Your Write API Key

void setup()
{
  Serial.begin(9600);
  delay(1000);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{
  val = analogRead(pin); // Read Analog values and Store in val variable
  Serial.print("Air moli: ");
  Serial.print(val/2);                 // Print on Serial Monitor
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,(val/2), myWriteAPIKey); //Update in ThingSpeak
  delay(1000);
}
