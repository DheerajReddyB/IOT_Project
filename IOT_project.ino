#include "Motor.h"
#include "ThingspeakMine.h"

void setup() {
  Serial.begin(9600);

 // connectWIFI();

  PinMode();

  DigitalWrite();

  AnalogWrite();



  BLEInit();

  SetMotorService();
  BLEAdvertise();
  Serial.println("BLE Peripheral");
}

void loop() {
  // wait for a Bluetooth®️ Low Energy central
  Motor();
}
