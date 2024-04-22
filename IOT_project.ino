#include "Motor.h"
void setup() {
  Serial.begin(9600);



  DigitalWrite();

  AnalogWrite();

  PinMode();


  BLEInit();

  setMotorService();
  BLEAdvertise();
  Serial.println("BLE Peripheral");
}

void loop() {
  // wait for a Bluetooth®️ Low Energy central
  Motor();
}
