#define SENSOR_PIN 10
#include <ArduinoBLE.h>
#include "ThingspeakMine.h"
#include "WIFIMine.h"

void TiltInit() 
{
  pinMode(SENSOR_PIN, INPUT_PULLUP);
}

long Tilt()
{
  if (CheckWIFI()) {
    //Serial.println("----------------WIFI ALREADY CONNECTED TO TILT SENSOR MODULE, CONNECT TO THINGSPEAK-----------------------------");
    ConnectToThingSpeakForTilt(digitalRead(SENSOR_PIN));
  }// else {
    //Serial.println("----------------WIFI CONNECTION FAILED TO TILT SENSOR , TELEMETERY DATA NOT SENT TO THINGSPEAK-----------------------------");
  //}
  Serial.println(digitalRead(SENSOR_PIN));
  return digitalRead(SENSOR_PIN); 
  /*if (digitalRead(SENSOR_PIN) == LOW)
  {
    //value = 0
    //both led light up
    return 0;
  }
  else
  {
    //value = 1
    //one led light up
    return 1;
  }*/
}