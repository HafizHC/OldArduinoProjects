#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int motora = 6;
int motorb = 7;
int motorc = 8;
int motord = 9;

int kumanda_deger = 0;

float mesafe;
int sure;

const int trigger = 11;
const int echo = 10;

IRrecv alici(2);
decode_results results;

void setup() {
pinMode(echo, INPUT);
pinMode(trigger, OUTPUT);
  
pinMode(motora, OUTPUT);
pinMode(motorb, OUTPUT);
pinMode(motorc, OUTPUT);
pinMode(motord, OUTPUT);

pinMode(3, OUTPUT);
pinMode(4, OUTPUT);

digitalWrite(3, LOW);
digitalWrite(4, HIGH);

Serial.begin(9600);
//alici.enableIRIn();
}

void loop() {
digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = (sure / 2) / 28, 9;

  Serial.print(" Mesafe = ");
  Serial.println(mesafe);

  if(mesafe <= 10){
  //  geri();
  donme();
  }
  if(mesafe > 10){
  digitalWrite(motora, 1);
  digitalWrite(motorb, 0);
  digitalWrite(motorc, 0);
  digitalWrite(motord, 0);
  }

 if(alici.decode(&results)){
    Serial.println(results.value);
      kumanda_deger = results.value;
      alici.resume();
  }

  if(kumanda_deger == 2067 || kumanda_deger == 19){
    digitalWrite(motora, HIGH);
    digitalWrite(motorb, LOW);
    digitalWrite(motorc, LOW);
    digitalWrite(motord, LOW);
  }
  if(kumanda_deger == 2066 || kumanda_deger == 18){
    digitalWrite(motora, LOW);
    digitalWrite(motorb, LOW);
    digitalWrite(motorc, HIGH);
    digitalWrite(motord, LOW);
  }
  if(kumanda_deger == 1101 || kumanda_deger == 53){
    digitalWrite(motora, LOW);
    digitalWrite(motorb, LOW);
    digitalWrite(motorc, LOW);
    digitalWrite(motord, HIGH);
  }
  if(kumanda_deger == 9999 || kumanda_deger == 9999){
    digitalWrite(motora, LOW);
    digitalWrite(motorb, HIGH);
    digitalWrite(motorc, LOW);
    digitalWrite(motord, LOW);
  }
  if(kumanda_deger == 9999 || kumanda_deger == 9999){

  }

  void geri() {
      digitalWrite(motora, 0);
      digitalWrite(motorb, 1);
      digitalWrite(motorc, 0);
      digitalWrite(motord, 0);
      delay(350);
  }
  void donme() {
      digitalWrite(motora, 1);
      digitalWrite(motorb, 0);
      digitalWrite(motorc, 1);
      digitalWrite(motord, 0);
      delay(150);
  }
}
