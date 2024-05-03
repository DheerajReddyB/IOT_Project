#include "Motor.h"
#include "Ultrasonic.h"
#include "IrSensor.h"
#include "TiltSensor.h"

void setup() {

  // Initalisation data transfer rate in baud
  // The Baud rate refers to the total number of signal units transmitted in one second. 
  // The Bit rate refers to the total Bits transmitted in one unit time. 
  // Baud rate indicates the total number of times the overall state of a given signal changes/ alters. 
  // Bit rate indicates the total bits that travel per second.
 
  Serial.begin(9600);
  
  // Initalisation for a Bluetooth®️ Low Energy central
  
  BLEInit();
  
  // Initalisation for a Ultrasonic sensor
  
  UltraSInit();

  // Initalisation for a Infrared sensor

  IrInit();

  // Initalisation for a Tilt sensor

  TiltInit();
}

void loop() { 
  // wait for a Bluetooth®️ Low Energy central
  Motor();
}
