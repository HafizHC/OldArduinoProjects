const int trigger = 10;
const int echo = 11;

const int moti = 12;
const int motg = 13; 

const int gr = 2;
const int ilr = 9;
const int tam = A5;

const int ysl1 = 3;
const int ysl2 = 4;
const int ysl3 = 5;
const int sr1 = 6;
const int sr2 = 7;
const int krmz = 8;
const int bzrP = A4;
const int bzrN = A1;

float mesafe;
int sure;
int alarm;
int turL = 0;
int turM = 0;
int gv = 0;
int grr = 0;
int ilrr = 0;
int star = 0;
int a = 0;
int ledS = 2;
int d = 1;
int h = 1;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(bzrP, OUTPUT);
  pinMode(bzrN, OUTPUT);
  pinMode(ysl1, OUTPUT);
  pinMode(ysl2, OUTPUT);
  pinMode(ysl3, OUTPUT);
  pinMode(sr1, OUTPUT);
  pinMode(sr2, OUTPUT);
  pinMode(krmz, OUTPUT);
  pinMode(moti, OUTPUT);
  pinMode(motg, OUTPUT);
  
  pinMode(gr, INPUT);
  pinMode(ilr, INPUT);

 /* digitalWrite(ysl1, LOW);
  digitalWrite(ysl2, LOW);
  digitalWrite(ysl3, LOW);
  digitalWrite(sr1, HIGH);
  digitalWrite(sr2, HIGH);
  digitalWrite(krmz, HIGH);*/
  digitalWrite(ysl1, HIGH);
  digitalWrite(ysl2, HIGH);
  digitalWrite(ysl3, HIGH);
  digitalWrite(sr1, HIGH);
  digitalWrite(sr2, HIGH);
  digitalWrite(krmz, HIGH);
  digitalWrite(bzrP, HIGH);
  digitalWrite(bzrN, HIGH);
  digitalWrite(moti, LOW);
  digitalWrite(motg, LOW);

  Serial.begin(9600);
}
void loop() {
        Serial.println(star);
  if(star == 0){
    if(digitalRead(tam) == HIGH){
      star++;
    }
    if(digitalRead(gr) == HIGH){
      digitalWrite(motg, LOW);
      digitalWrite(moti, HIGH);
    }else if(digitalRead(ilr) == HIGH){
      digitalWrite(moti, LOW);
      digitalWrite(motg, HIGH); 
    }else{
      digitalWrite(moti, LOW);
      digitalWrite(motg, LOW);
    }
  }
  /*if(star == 1){
    if(d == 1){
      delay(1000);
      d++;
    }
    if(digitalRead(tam) == HIGH){
      star++;
    }
    if(digitalRead(ilr) == HIGH && ledS < 8) {
      delay(300);
      digitalWrite(ledS, LOW);
      ledS++;
      digitalWrite(ledS, LOW);
    }
    if(digitalRead(gr) == HIGH && ledS >= 2) {
      delay(300);
      digitalWrite(ledS, HIGH);
      ledS--;
      digitalWrite(ledS, HIGH);
    }   
  }*/
  if(star == 1){
    if(d == 1){
      delay(1000);
      d++;
    }
    if(digitalRead(tam) == HIGH){
      star--;
    }
    if(a == 0){
      a++;
      digitalWrite(moti, LOW);
      digitalWrite(motg, LOW);
    }
    digitalWrite(trigger, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigger, LOW);
    sure = pulseIn(echo, HIGH);
    mesafe = (sure / 2) / 28, 9;
  
    Serial.print(" Mesafe = ");
    Serial.println(mesafe);
    Serial.println("____________________");
    turL++;
    if (turL == 15 || h == 1){
      h = 3754;
      if (turM == 0){
       ////////////////////////////////// delayMicroseconds(10);
        digitalWrite(motg, HIGH);
        digitalWrite(moti, LOW);
      }
      if (turM == 1){
        digitalWrite(motg, LOW);
        digitalWrite(moti, HIGH);
      }
      if(gv == 0){
        turM = 1;
        gv = 1;
      }else{
        turM = 0;
        gv = 0;
      }
      turL=0;
    }
    if(mesafe < 0){   
  }else if(mesafe < 10){
    for(int i = 3;i <= 8;i++)
    digitalWrite(i, LOW);
  }else if(mesafe < 20){
    for(int i = 3;i <= 7;i++)
    digitalWrite(i, LOW);
    digitalWrite(8, HIGH);
  }else if(mesafe < 30){
    for(int i = 3;i <= 6;i++)
    digitalWrite(i, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
  }else if(mesafe < 40){
    for(int i = 3;i <= 5;i++)
    digitalWrite(i, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
  }else if(mesafe < 80){
    for(int i = 3;i <= 4;i++)
    digitalWrite(i, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }else if(mesafe > 79){
    for(int i = 3;i <= 3;i++)
    digitalWrite(i, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(200);
  }
}
