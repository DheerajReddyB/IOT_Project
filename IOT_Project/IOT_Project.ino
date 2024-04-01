//defining each digital pin to motor controller
#define IN1 6
#define IN2 5
#define IN3 4
#define IN4 3

#define ENA 7
#define ENB 2

#define Speed 180

#define ledPin 13
#define LEDB 14
#define LEDG 15
#define LEDR 16

 #include <ArduinoBLE.h>
// Bluetooth® Low Energy LED Service
BLEService ledService("19b10000-e8f2-537e-4f6c-d104768a1214"); 

// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19b10000-e8f2-537e-4f6c-d104768a1214", BLERead | BLEWrite);

//internal LED pin
//const int ledPin = LED_BUILTIN;

void setup() {
  Serial.begin(9600);
  
  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);
  
  // BLE initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }
  
  // set advertised local name and service UUID:
  BLE.setLocalName("LED");
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
      int value = switchCharacteristic.value();
      if (switchCharacteristic.written()) 
      {
        if (value == 1) {
          digitalWrite(ledPin, HIGH);         // will turn the builtin LED on
        } 
        else if(value == 2)
        {
          digitalWrite(ledPin, LOW);          // will turn the builtin LED off
        }
        else if(value == 3){                        
          for (int i=0;i<3;i++){
            digitalWrite(ledPin, HIGH);
            delay(4000);
            digitalWrite(ledPin, LOW);
            }
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
