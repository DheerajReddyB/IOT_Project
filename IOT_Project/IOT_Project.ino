    //defining each digital pin to motor controller
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

#define ENA 2
#define ENB 7

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
        Stop();
        switch(value){
          case '1':
            forward();
          case '2':
            backward();
          case '3':
            left();
          case '4':
            right();
        }
      }
    }
    // the central has disconnected
    Serial.println("Disconnected from central: ");
  }
}

void forward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void backward() {
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
void left() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void right() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
