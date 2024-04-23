#include <ArduinoBLE.h>
#include "BLEDevice.h"

#define echoPin 4 // Echo Pin
#define trigPin 5 // Trigger Pin
#define LEDPin 13 // Onboard LED

unsigned long previousMillis = 0; // Stores the last time the LED was updated
const long interval = 100; // Interval at which to trigger the ultrasonic sensor (milliseconds)

long duration, distance; // Duration used to calculate distance
bool trigState = false; // Trigger state

void PinMode(){
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(LEDPin, OUTPUT); // Sets the LEDPin as an OUTPUT
  Serial.begin(9600); // Starts the serial communication
}

void ultrasonic_faster() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Triggering the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    trigState = true;
  }

  // Check if there is a response from the ultrasonic sensor
  if (trigState && digitalRead(echoPin) == HIGH) {
    unsigned long startTime = micros();
    while (digitalRead(echoPin) == HIGH) {
      if (micros() - startTime > 23200) {
        break; // Break the loop if no echo is received within 400 cm
      }
    }
    duration = micros() - startTime;
    distance = duration * 0.034 / 2; // Converts the pulse width to distance in cm
    Serial.print("Distance: ");
    Serial.println(distance);
    trigState = false;
  }
}