  //#include "IOT_project/include/ThingspeakMine/ThingspeakMine.h"
#include "Motor.h"


 


void setup() {
  Serial.begin(9600);
 
 

  DigitalWrite();

  AnalogWrite();

  PinMode() ;
 

 
  // BLE initialization
  if (!BLE.begin()) { 
    Serial.println("Starting Bluetooth® Low Energy module failed!");
    while (1);
  }

    setMotorService();
  // start advertising
  BLE.advertise();
  Serial.println("BLE Peripheral");

}

void loop() {
  // wait for a Bluetooth®️ Low Energy central
  Motor();
}
