#include <WiFi.h>

#define WIFI_SSID "sweethome-JioFiber-24_2.4G"
#define WIFI_PASS "2success2"

void WIFIInit() {
  WiFi.mode(WIFI_STA);  //Optional
  WiFi.begin(WIFI_SSID, WIFI_PASS);
}

boolean CheckWIFI() {
  WIFIInit();
  Serial.println("Connecting status ::" + String(WiFi.status()));
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("---------------------------------------------");
    Serial.println("Already Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.println("---------------------------------------------");

    return true;
  } else {

    int attempts = 1;
    while (WiFi.status() != WL_CONNECTED) {
//      delay(500);
      Serial.println("Connecting to WIFI." + String(attempts));
      attempts++;
      if (attempts >= 3) {
        Serial.println("Not able to Connection to WIFI ");
        return false;
        //ESP.restart();
      }
    }
    Serial.println("---------------------------------------------");
    Serial.println("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.println("---------------------------------------------");

    return true;
  }
}