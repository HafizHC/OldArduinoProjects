#include <SPI.h>
#include <MFRC522.h>
#include <IRremote.h>

iNt RST_PIN = 9;
int SS_PIN = 10;

int buzz = A0;
int role = 5;

int deger = 0;

MFRC522 rfid(SS_PIN, RST_PIN);

IRrecv alici(2);
decode_results results;


void setup() {

pinMode(buzz, OUTPUT);
pinMode(role, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
 digitalWrite(role, HIGH);

Serial.begin(9600);
alici.enableIRIn();

Serial.begin(9600);
SPI.begin();
rfid.PCD_Init();
}

void loop() {
 digitalWrite(3, LOW);
 digitalWrite(4, HIGH);
  if(alici.decode(&results)){
    Serial.println(results.value, HEX);
      deger = results.value;
      Serial.println(deger);
      alici.resume();
  }

  if(deger == 1101 || deger == 53 || deger == 835 || deger == 2101){
    deger = 0;
    digitalWrite(role, LOW);
    delay(150);
    digitalWrite(role, HIGH); 
    }  
  byte user1[4] = {115,220,40,38};
  byte user2[4] = {154,92,41,69};
  if(! rfid.PICC_IsNewCardPresent())
    return;
  if(! rfid.PICC_ReadCardSerial())
    return;
  if( rfid.uid.uidByte[0] == user1[0] &&
    rfid.uid.uidByte[1] == user1[1] &&
    rfid.uid.uidByte[2] == user1[2] &&
    rfid.uid.uidByte[3] == user1[3] || 
    rfid.uid.uidByte[0] == user2[0] &&
    rfid.uid.uidByte[1] == user2[1] &&
    rfid.uid.uidByte[2] == user2[2] &&
    rfid.uid.uidByte[3] == user2[3]){
      digitalWrite(role, LOW);
      delay(150);
      digitalWrite(role, HIGH);
      delay(1000);
      }
      else if(rfid.uid.uidByte[0] != user1[0] &&
    rfid.uid.uidByte[1] != user1[1] &&
    rfid.uid.uidByte[2] != user1[2] &&
    rfid.uid.uidByte[3] != user1[3] || 
    rfid.uid.uidByte[0] != user2[0] &&
    rfid.uid.uidByte[1] != user2[1] &&
    rfid.uid.uidByte[2] != user2[2] &&
    rfid.uid.uidByte[3] != user2[3]){
     digitalWrite(buzz, HIGH); 
     delay(500);
     digitalWrite(buzz, LOW);        
    }else{
    }
}
