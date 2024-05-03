#include <WiFiClient.h>
#include "ThingSpeak.h"

#define USER_API_KEY "BNFKO2CURC1S7EWZ"
#define ALERT_API_KEY "TAKmmw9DRVrWNKo7YE9"

#define WRITE_API_KEY "BIDKCSP43TP553K4"


WiFiClient client;

void ConnectToThingSpeak() {

  unsigned long MY_CHANNEL_NUMBER = 1;
  unsigned long MY_FIELD_NUMBER = 1;



  ThingSpeak.begin(client);  // Initialize ThingSpeak
  // Variable to hold engine heat readings
  float temperatureC = random(500);

  // Variable to hold speed readings
  float speed = random(1000);

  // Variable to hold speed readings
  float tilt = random(10);

  // set the fields with the values
  ThingSpeak.setField(1, temperatureC);
  //ThingSpeak.setField(1, temperatureF);
  ThingSpeak.setField(2, speed);
  ThingSpeak.setField(3, tilt);


  int httpstatuscode = ThingSpeak.writeFields(MY_CHANNEL_NUMBER, WRITE_API_KEY);
  if (httpstatuscode == 200) {
    Serial.println("Channel update successful." + String(httpstatuscode));

 //   Serial.println("After update waiting for 5 seconds ");
//    delay(5000);


  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(httpstatuscode));
  }
}


void ConnectToThingSpeakForSpeed(long speed) {
  unsigned long MY_CHANNEL_NUMBER = 1;
  unsigned long MY_FIELD_NUMBER = 4;

  //Logic to scale add here before senting to ThingSpeak

  // set the fields with the values
  ThingSpeak.setField(MY_FIELD_NUMBER, speed);

  int httpstatuscode = ThingSpeak.writeFields(MY_CHANNEL_NUMBER, WRITE_API_KEY);
  if (httpstatuscode == 200) {
    Serial.println("Channel update successful." + String(httpstatuscode));

 //   Serial.println("After update waiting for 5 seconds ");
//    delay(5000);


  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(httpstatuscode));
  }
}
void ConnectToThingSpeakForTilt(long tilt) {
  unsigned long MY_CHANNEL_NUMBER = 1;
  unsigned long MY_FIELD_NUMBER = 3;

  //Logic to scale add here before senting to ThingSpeak

  // set the fields with the values
  ThingSpeak.setField(MY_FIELD_NUMBER, tilt);


  int httpstatuscode = ThingSpeak.writeFields(MY_CHANNEL_NUMBER, WRITE_API_KEY);
  if (httpstatuscode == 200) {
    Serial.println("Channel update successful." + String(httpstatuscode));

   // Serial.println("After update waiting for 5 seconds ");
  //  delay(5000);


  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(httpstatuscode));
  }
}
void ConnectToThingSpeakForDistance(long distance) {
  unsigned long MY_CHANNEL_NUMBER = 1;
  unsigned long MY_FIELD_NUMBER = 1;
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  //Logic to scale add here before senting to ThingSpeak

  // set the fields with the values
  ThingSpeak.setField(MY_FIELD_NUMBER, distance);

  int httpstatuscode = ThingSpeak.writeFields(MY_CHANNEL_NUMBER, WRITE_API_KEY);
  if (httpstatuscode == 200) {
    Serial.println("Channel update successful." + String(httpstatuscode));

   // Serial.println("After update waiting for 5 seconds ");
  //  delay(5000);


  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(httpstatuscode));
  }
}

void ConnectToThingSpeakForTilt(long tilt) {
  unsigned long MY_CHANNEL_NUMBER = 1;
  unsigned long MY_FIELD_NUMBER = 2;
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  //Logic to scale add here before senting to ThingSpeak

  // set the fields with the values
  ThingSpeak.setField(MY_FIELD_NUMBER, tilt);
  //when normal : tilt = 1 (one light light up)
  //when robot flips : tilt = 0 (both lights light up)

  int httpstatuscode = ThingSpeak.writeFields(MY_CHANNEL_NUMBER, WRITE_API_KEY);
  if (httpstatuscode == 200) {
    Serial.println("Channel update successful." + String(httpstatuscode));

   // Serial.println("After update waiting for 5 seconds ");
  //  delay(5000);


  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(httpstatuscode));
  }
}
void ConnectToThingSpeakForTemperature(long temperatureC) {
  unsigned long MY_CHANNEL_NUMBER = 1;
  unsigned long MY_FIELD_NUMBER = 2;

  //Logic to scale add here before senting to ThingSpeak

  // set the fields with the values
  ThingSpeak.setField(MY_FIELD_NUMBER, temperatureC);

  int httpstatuscode = ThingSpeak.writeFields(MY_CHANNEL_NUMBER, WRITE_API_KEY);
  if (httpstatuscode == 200) {
    Serial.println("Channel update successful." + String(httpstatuscode));

   // Serial.println("After update waiting for 5 seconds ");
  //  delay(5000);

  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(httpstatuscode));
  }
}
