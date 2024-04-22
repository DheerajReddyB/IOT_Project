#include <ArduinoBLE.h>

 #include "BLEDevice.h"

#define IN1 6
#define IN2 5
#define IN3 4
#define IN4 3

#define ENA 7
#define ENB 2

#define Speed 200

//custom 128-bit UUID, read and writable by central
BLEService MotorService("19b10000-e8f2-537e-4f6c-d104768a1214");
BLEService UltraSonicService("19b10000-e8f2-537e-4f6c-d104768a1215");

//setting read and write characteristics 
//BLEByteCharacteristic switchCharacteristic("19b10000-e8f2-537e-4f6c-d104768a1214", BLERead | BLEWrite);
BLEIntCharacteristic switchCharacteristic("19b10000-e8f2-537e-4f6c-d104768a1214", BLERead | BLEWrite);

void Motor();
void Backward();
void Forward();
void Stop();
void Left();
void Right();