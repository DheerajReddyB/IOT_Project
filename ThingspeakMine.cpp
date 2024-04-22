#include <WiFi.h>
#include <WiFiClient.h>
#include "ThingSpeak.h"

#define WRITE_API_KEY "BNFKO2CURC1S7EWZ"
#define WIFI_SSID "sweethome-JioFiber-24_5G"
#define WIFI_PASS "2success2"

void connectWIFI()
{
   WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

}