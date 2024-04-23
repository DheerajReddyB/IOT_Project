#include "Motor.h"

#include "Ultrasonic.h"

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


  // Invoke Ultrasonic
  Serial.println("Invoke Ultrasonic ");
  Ultrasonic();

  // wait for a Bluetooth®️ Low Energy central
  Serial.println("Run Car");
  Motor();

  
 
}
