#include <HCSR04.h>
#include "ThingspeakMine.h"
#include "WIFIMine.h"

#define echoPin 2             // Echo Pin
#define trigPin 9             // Trigger Pin
#define LEDPin 13             // Onboard LED
HCSR04 hc(trigPin, echoPin);  //initialisation class HCSR04 (trig pin , echo pin)

long duration, distance;  // Duration used to calculate distance

void UltraSInit() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long Ultrasonic() {

  distance = hc.dist();

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