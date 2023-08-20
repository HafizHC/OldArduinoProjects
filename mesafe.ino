const int trigger = 9;
const int echo = 8;
const int ysl = 13;
const int sr = 12;
const int krmz = 11;
const int bzr = 10;
//const int kabloIN = 5;
//const int green = 5;
//const int red = 3;

float mesafe;
int sure;
int alarm;
//int Red;
//int Green;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(bzr, OUTPUT);
  pinMode(krmz, OUTPUT);
  pinMode(sr, OUTPUT);
  pinMode(ysl, OUTPUT);
  //pinMode(kabloIN, INPUT);
 // pinMode(red, OUTPUT);
 // pinMode(green, OUTPUT);

  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = (sure / 2) / 28, 9;

 Serial.print(" Mesafe = ");
 Serial.println(mesafe);
 Serial.println("____________________");
  
  
  if ((3 >= mesafe) && (mesafe > -1)) {
    digitalWrite(ysl, HIGH);
    digitalWrite(sr, HIGH);
    digitalWrite(krmz, HIGH);
    digitalWrite(bzr, HIGH);
  }
  else if (15 > mesafe) {
    digitalWrite(bzr, LOW);
    digitalWrite(ysl, LOW);
    digitalWrite(sr, LOW);
    digitalWrite(krmz, HIGH);
    delay(250);
    digitalWrite(krmz, LOW);
    delay(250);
  }
  else if (30 > mesafe) {
    digitalWrite(bzr, LOW);
    digitalWrite(krmz, LOW);
    digitalWrite(ysl, LOW);
    digitalWrite(sr, HIGH);
    delay(500);
    digitalWrite(sr, LOW);
    delay(500);
  }
  else if (mesafe > 50) {
    digitalWrite(bzr, LOW);
    digitalWrite(sr, LOW);
    digitalWrite(krmz, LOW);
    digitalWrite(ysl, HIGH);
    delay(750);
    digitalWrite(ysl, LOW);
    delay(750);
  }
 }
