#include "Motor.h"

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
  Serial.println("Run Car");
  Motor();


 
}
