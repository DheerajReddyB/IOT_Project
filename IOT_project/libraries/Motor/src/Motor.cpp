#include <ArduinoBLE.h>
#include "BLEDevice.h"
#include "Ultrasonic.h"
#include "IrSensor.h"
#include "TiltSensor.h"

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

#define ENA 8
#define ENB 3


#define Speed 200


//custom 128-bit UUID, read and writable by central
BLEService MotorService("19b10000-e8f2-537e-4f6c-d104768a1214");
BLEService TiltService("19b10000-e8f2-537e-4f6c-d104768a1215");
BLEService IrSensorService("19b10000-e8f2-537e-4f6c-d104768a1216");
//setting read and write characteristics
//BLEByteCharacteristic switchCharacteristic("19b10000-e8f2-537e-4f6c-d104768a1214", BLERead | BLEWrite);
BLEIntCharacteristic switchCharacteristic("19b10000-e8f2-537e-4f6c-d104768a1214", BLERead | BLEWrite);
BLEIntCharacteristic switchCharacteristicTilt("19b10000-e8f2-537e-4f6c-d104768a1215", BLERead | BLENotify);
BLEIntCharacteristic switchCharacteristicIrSensor("19b10000-e8f2-537e-4f6c-d104768a1216", BLERead | BLENotify);

void DigitalWrite() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void AnalogWrite() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
}

void PinMode() {
  // motor controls
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void Backward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Forward() {
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

void BLEAdvertise() {
  // start advertising
  BLE.advertise();
  Serial.println("BLE Peripheral");
}

void BluetoothServices() {
  // set advertised local name and service UUID:
  BLE.setDeviceName("IOT_Project");
  BLE.setLocalName("IOT_Project");
  BLE.setAdvertisedService(MotorService);

  // add the characteristic to the service
  MotorService.addCharacteristic(switchCharacteristic);
  TiltService.addCharacteristic(switchCharacteristicTilt);
  IrSensorService.addCharacteristic(switchCharacteristicIrSensor);

  // add service
  BLE.addService(MotorService);
  BLE.addService(TiltService);
  BLE.addService(IrSensorService);

  // set the initial value for the characeristic:
  switchCharacteristic.writeValue(0);

 BLEAdvertise();

}


void BLEInit() {

  PinMode();
  DigitalWrite();
  AnalogWrite();
  // BLE initialization
  if (!BLE.begin()) {
    Serial.println("Starting Bluetooth® Low Energy module failed!");
    while (1) ;
  }
  BluetoothServices();

}


void Motor() {
  // wait for a Bluetooth®️ Low Energy central
  BLEDevice central = BLE.central();
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {

      Stop();
      if (switchCharacteristic.written()) {
        int value = switchCharacteristic.value();
        Serial.println(value);
        if (value > 0) {
          Serial.println("========================" );
          switchCharacteristicTilt.writeValue(Tilt());


          switch (value) {
            case 49:
              {
                switchCharacteristicTilt.writeValue(IR_sensor());
                if (IR_sensor()){
                  
                  Forward();
                  Serial.println("Forward");
                  delay(150);
                }
                else
                {
                  Stop();
                  Serial.println("Ledge detected");
                }
                break;
              }
            case 50:
              {
                Backward();
                delay(150);
				        /*Serial.println("Invoke Ultrasonic ");

				        if(Ultrasonic()<20)
                {
                  Serial.println("TOOOOO CLOSE!!!!!!");
                  Stop();
                }
                else
	              {
		              Backward();
		              Serial.println("Backward");
		              delay(150);
			            // Invoke Ultrasonic
	              }*/
                break;
              }
            case 51:
              {
                Left();
                Serial.println("Left");
                delay(150);
                break;
              }
            case 52:
              {
                Right();
                Serial.println("Right");
                delay(150);
                break;
              }
            default:
              {
                Stop();
                Serial.println("Default Stop");
                break;
              }
          }
        }
      }
    }
  }
}
