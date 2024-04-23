#include "Motor.h"
#include "ThingspeakMine.h"

void setup() {
  Serial.begin(9600);

  CheckWIFI();

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
}
