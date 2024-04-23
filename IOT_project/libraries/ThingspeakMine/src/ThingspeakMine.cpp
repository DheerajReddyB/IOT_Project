#include <WiFi.h>
#include <WiFiClient.h>
#include "ThingSpeak.h"

#define USER_API_KEY "BNFKO2CURC1S7EWZ"
#define WIFI_SSID "sweethome-JioFiber-24_2.4G"
#define WIFI_PASS "2success2"
#define ALERT_API_KEY "TAKmmw9DRVrWNKo7YE9"

#define WRITE_API_KEY "BIDKCSP43TP553K4"


WiFiClient client;

void ConnectToThingSpeak() {

  unsigned long MY_CHANNEL_NUMBER = 1;
  unsigned long MY_FIELD_NUMBER = 1;

  // Timer variables
  unsigned long lastTime = 0;
  unsigned long timerDelay = 30000;
  Serial.println("Connecting to ThingSpeak");

  ThingSpeak.begin(client);  // Initialize ThingSpeak
  // Variable to hold engine heat readings
  float temperatureC = 10.01;

  // Variable to hold speed readings
  float speed = 1000.01;

  // Variable to hold speed readings
  float tilt = 6000.01;

  // set the fields with the values
  ThingSpeak.setField(1, temperatureC);
  //ThingSpeak.setField(1, temperatureF);
  ThingSpeak.setField(2, speed);
  ThingSpeak.setField(3, tilt);


  int httpstatuscode = ThingSpeak.writeFields(MY_CHANNEL_NUMBER, WRITE_API_KEY);
  if (httpstatuscode == 200) {
    Serial.println("Channel update successful." + String(httpstatuscode));

    Serial.println("After update waiting for 15 seconds ");
    delay(15000);


  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(httpstatuscode));
  }
  lastTime = millis();
}
