#include <WiFiManager.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "*****"
#define FIREBASE_AUTH "*****"

#define button D5
#define led D8

WiFiManager wm;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
 
  WiFi.mode(WIFI_STA);
  wm.autoConnect("Cicek","123456789"); 
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

boolean n = 0;

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    Firebase.setBool("led", digitalRead(button));
    delay(1000);
    n = Firebase.getBool("led");
    Serial.println(digitalRead(button));
    digitalWrite(led,n);
    Firebase.remove("led");
  }
  if(Firebase.getBool("resetWifi")){
    Firebase.setBool("resetWifi", false);
    digitalWrite(led,LOW );
    Serial.println("resetWifi");
    delay(1000);
    WiFi.disconnect(true);
    delay(1000);
    wm.resetSettings();
    delay(3000);
    ESP.reset();
    delay(5000);
  }
  delay(1000);
}
