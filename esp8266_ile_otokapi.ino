
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "******"
#define FIREBASE_AUTH "********"
#define WIFI_SSID "******"
#define WIFI_PASSWORD "*****"

int dur  = 0;
int a = 0;
void setup() {
Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  Firebase.setString("message", "hello world");
  String roleDurum = Firebase.getString("durum");
  Serial.print("roleDurum");
  Serial.print(roleDurum);

  a = digitalRead(0);
  Firebase.setInt("messa", a);
  
  if(roleDurum == "1" && dur == 0){
     digitalWrite(LED_BUILTIN, HIGH);
     delay(300);
     digitalWrite(LED_BUILTIN, LOW);
     dur = 1;
  }else if(roleDurum == "0" && dur == 1){
     digitalWrite(LED_BUILTIN, HIGH);
     delay(300);
     digitalWrite(LED_BUILTIN, LOW);
     dur = 0;
  }
}
