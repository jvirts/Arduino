
#include <SoftwareSerial.h>
const byte rxPin = 10;
const byte txPin = 11;

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);
long randNumber;
int ikount =0;
float a,b,c;
float printme;
unsigned long time;

typedef union {
  float floatingPoint;
  byte binary[4];
} binaryFloat;
binaryFloat myFloat;

typedef union {
  long intPoint;
  byte binary[4];
} binaryInt;
binaryInt myInt;

void setup() {
  // put your setup code here, to run once:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  randomSeed(1234);
}

void loop() {

  while(ikount < 1000){
  ikount = ikount + 1;
  myInt.intPoint = ikount;
  mySerial.write(myInt.binary,4);
  randNumber = random(100000);
  a = (float)randNumber/100.;
  myFloat.floatingPoint = a;
  memcpy(&printme,myFloat.binary,4);
  Serial.print(ikount);
  Serial.print(" ");
  Serial.print(millis()/100);
  Serial.print(" ");
  Serial.print(printme);
  mySerial.write(myFloat.binary,4);

  randNumber = random(100000);
  b = (float)randNumber/100;
  myFloat.floatingPoint = b;
  mySerial.write(myFloat.binary,4);
  memcpy(&printme,myFloat.binary,4);
  Serial.print(" ");
  Serial.print(printme);
  randNumber = random(100000);
  c = (float) randNumber/100.;
  myFloat.floatingPoint = c;
  mySerial.write(myFloat.binary,4);
  memcpy(&printme,myFloat.binary,4);
  Serial.print(" ");
  Serial.println(printme);

  }

  //mySerial.write(1);
  //mySerial.write(2);
  //mySerial.write(3);
  //mySerial.write(4);
  //mySerial.write(5);
  // put your main code here, to run repeatedly:
 

}
