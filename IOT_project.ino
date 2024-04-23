#include "Motor.h"
#include "ThingspeakMine.h"

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
  // Serial.println("Motor Calling");
  if (CheckWIFI()) {
    Serial.println("----------------WIFI CONNECTED , NOT CONNECT TO THINGSPEAK-----------------------------");
    ConnectToThingSpeak();
  }

  //Motor();
}
