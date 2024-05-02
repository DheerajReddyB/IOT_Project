
#include <ArduinoBLE.h>

#define IrPin 13
//#include "ThingspeakMine.h"
//#include "WIFIMine.h"

void IrInit()
{
  pinMode(IrPin,INPUT);
  Serial.begin(9600);
}
int IR_sensor()
{
  if (digitalRead(IrPin)== LOW)
  {
    return 0;
    //IR does not detect floor
  }

  return 1;
  //IR detects floor
  
  /*
  if (CheckWIFI()) {
    Serial.println("----------------WIFI ALREADY CONNECTED TO IR SENSOR MODULE, CONNECT TO THINGSPEAK-----------------------------");
    ConnectToThingSpeakForDistance(distance);
  } else {
    Serial.println("----------------WIFI CONNECTION FAILED TO IR SENSOR, TELEMETERY DATA NOT SENT TO THINGSPEAK-----------------------------");
  }*/

}