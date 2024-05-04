#include <HCSR04.h>
#include "ThingspeakMine.h"
#include "WIFIMine.h"

#define echoPin 2             // Echo Pin
#define trigPin 9             // Trigger Pin
//#define LEDPin 13             // Onboard LED
HCSR04 hc(trigPin, echoPin);  //initialisation class HCSR04 (trig pin , echo pin)

unsigned long previousMillis = 0; // Variable to store the previous timestamp
unsigned long interval = 1000; // Interval in milliseconds between each sensor reading

long duration, distance;  // Duration used to calculate distance

void UltraSInit() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long Ultrasonic() {

  //unsigned long currentMillis = millis(); // Get the current timestamp

  distance = hc.dist();

  /*if (currentMillis - previousMillis >= interval) { // Check if it's time to take a new reading
    previousMillis = currentMillis; // Update the previous timestamp

    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echo pin
    long duration = pulseIn(echoPin, HIGH);

    // Calculate distance based on the speed of sound (340 m/s)
    // and the formula: distance = (duration / 2) * speed_of_sound
    float distance = duration * 0.034 / 2;*/

  Serial.print("Ultrasonic distance: ");
  Serial.println(distance);
    

  if (CheckWIFI()) {
    Serial.println("----------------WIFI ALREADY CONNECTED TO ULTRASONIC MODULE, CONNECT TO THINGSPEAK-----------------------------");
    ConnectToThingSpeakForDistance(distance);
  } else {
    Serial.println("----------------WIFI CONNECTION FAILED TO ULTRASONIC MODULE, TELEMETERY DATA NOT SENT TO THINGSPEAK-----------------------------");
  }

  return distance;
}