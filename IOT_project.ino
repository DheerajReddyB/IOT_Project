#include "Motor.h"
#include "ThingspeakMine.h"
#include "WIFIMine.h"

void setup() {
  Serial.begin(9600);
  PinMode();
  DigitalWrite();
  AnalogWrite();
  BLEInit();
  SetMotorService();
  BLEAdvertise();
}

void loop() {
  
  // wait for a Bluetooth®️ Low Energy central
  Serial.println("Motor Calling");
  Motor();

  if (CheckWIFI()) { 
    Serial.println("----------------WIFI ALREADY CONNECTED , CONNECT TO THINGSPEAK-----------------------------");
    ConnectToThingSpeak();
  } else {
    Serial.println("----------------WIFI CONNECTION FAILED, TELEMETERY DATA NOT SENT TO THINGSPEAK-----------------------------");
  }
}
