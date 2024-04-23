#include <WiFi.h>
#include <WiFiClient.h>
#include "ThingSpeak.h"

const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance;
 //custom 128-bit UUID, read and writable by central
 BLEService UltraSonicService("19b10000-e8f2-537e-4f6c-d104768a1215");



void ultraSonic()
{

}