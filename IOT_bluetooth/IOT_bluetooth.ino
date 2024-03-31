
//defining each digital pin to motor controller
#define IN1 6
#define IN2 5
#define IN3 4
#define IN4 3

#define ENA 7
#define ENB 2

#define ledPin 13
#define LEDB 14
#define LEDG 15
#define LEDR 16

#define Speed 180

//#include <WiFiNINA.h>

#include <ArduinoBLE.h>
//custom 128-bit UUID, read and writable by central
BLEService ledService("19b10000-e8f2-537e-4f6c-d104768a1214");

//setting read and write characteristics 
BLEByteCharacteristic switchCharacteristic("19b10000-e8f2-537e-4f6c-d104768a1214", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDR, OUTPUT);
  
  // BLE initialization
  if (!BLE.begin()) { 
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1)
      ;
  }

  // set advertised local name and service UUID:
  BLE.setLocalName("IOT_Project");
  BLE.setAdvertisedService(ledService);

  // add the characteristic to the service
  ledService.addCharacteristic(switchCharacteristic);

  // add service
  BLE.addService(ledService);

  // set the initial value for the characeristic:
  switchCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();
  Serial.println("BLE LED Peripheral");
}

void loop() {
  // wait for a Bluetooth® Low Energy central
  BLEDevice central = BLE.central();

  // check if a central is connected to this peripheral
  if (central) {
    Serial.print("Connected to central: ");

    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {

      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      int value = switchCharacteristic.written();
      if (value) {

        if (value==1) {  // light turns on when 1
          Serial.println(value);
          //Forward();

          Serial.println("LED on");
          digitalWrite(ledPin, HIGH);  // will turn the LED on
        } 
        else if (value == 2) {

          //Backward();

          Serial.println(F("LED off"));
          digitalWrite(ledPin, LOW);  // will turn the LED off
        }
        else if (value == 3) {
          //Stop();
          digitalWrite(LEDB, HIGH);
          delay(1000);
          digitalWrite(LEDB, LOW);
        }
        else if (value == 4) {
          //Left();
          digitalWrite(LEDG, HIGH);
          delay(1000);
          digitalWrite(LEDG, LOW);
        } 
        else if (value == 5) {
          //Right();
          digitalWrite(LEDR, HIGH);
          delay(1000);
          digitalWrite(LEDR, LOW);
        }
      }
    }

    // the central has disconnected
    Serial.println("Disconnected from central: ");
  }
}

void Forward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Backward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void Left() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Right() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}