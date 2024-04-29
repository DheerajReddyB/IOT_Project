#include <HCSR04.h>
#include "ThingspeakMine.h"
#include "WIFIMine.h"

#define echoPin 8             // Echo Pin
#define trigPin 9             // Trigger Pin
#define LEDPin 13             // Onboard LED
HCSR04 hc(trigPin, echoPin);  //initialisation class HCSR04 (trig pin , echo pin)

/*
unsigned long previousMillis = 0; // Stores the last time the LED was updated
const long interval = 100; // Interval at which to trigger the ultrasonic sensor (milliseconds)
*/
long duration, distance;  // Duration used to calculate distance
//bool trigState = false; // Trigger state


void UltraSInit() {
  /*pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(LEDPin, OUTPUT); // Sets the LEDPin as an OUTPUT
  Serial.begin(9600); // Starts the serial communication*/
 // Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long Ultrasonic() {
  Serial.println("Ultrasonic ");
  /* unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Triggering the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);

    digitalWrite(13,HIGH);

    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    trigState = true;

    digitalWrite(13,HIGH);
  }

  // Check if there is a response from the ultrasonic sensor
  if (trigState && digitalRead(echoPin) == HIGH) {
    unsigned long startTime = micros();
    while (digitalRead(echoPin) == HIGH) {
      if (micros() - startTime > 23200) {
        break; // Break the loop if no echo is received within 400 cm
      }
    }
    digitalWrite(13,HIGH);
    duration = micros() - startTime;
    distance = duration * 0.034 / 2; // Converts the pulse width to distance in cm
    Serial.print("Distance: ");
    Serial.println(distance);
    trigState = false;
  }*/
  /* digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  */

  distance = hc.dist();

  Serial.print("distance: ");
  Serial.println(distance);

  /*
  Serial.print("duration: ");
  Serial.println(duration);

  distance = (duration * .0343) / 2;


  Serial.print("Distance: ");
  Serial.println(distance);
*/

  if (CheckWIFI()) {
    Serial.println("----------------WIFI ALREADY CONNECTED TO ULTRASONIC MODULE, CONNECT TO THINGSPEAK-----------------------------");
    ConnectToThingSpeakForDistance(distance);
  } else {
    Serial.println("----------------WIFI CONNECTION FAILED TO ULTRASONIC MODULE, TELEMETERY DATA NOT SENT TO THINGSPEAK-----------------------------");
  }


  delay(100);
  return distance;
}