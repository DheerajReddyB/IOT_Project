  //#include "IOT_project/include/ThingspeakMine/ThingspeakMine.h"
#include "Motor.h"


 
void setup() {
  Serial.begin(9600);
 
  // motor controls
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

  analogWrite(ENA,Speed);
  analogWrite(ENB,Speed);

  
  // BLE initialization
  if (!BLE.begin()) { 
    Serial.println("Starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setDeviceName("IOT_Project");
  BLE.setLocalName("IOT_Project");
  BLE.setAdvertisedService(MotorService);

  // add the characteristic to the service
  MotorService.addCharacteristic(switchCharacteristic);

  // add service
  BLE.addService(MotorService);

  // set the initial value for the characeristic:
  switchCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();
  Serial.println("BLE Peripheral");
  Motor();
}

void loop() {
  // wait for a Bluetooth®️ Low Energy central
  //Motor();
}
