/*
* Arduino LCD Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/


#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(10, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 




unsigned long secondCounter = 0;
unsigned long minuteCounter = 0;
unsigned long hourCounter = 0;
unsigned long delayStart = 0;
String secCounterStr, minCounterStr, hrCounterStr,timeStr;
String rtMin,rtSec,rtHour,rtDoW;
String rtTime;
String myDist,myDist2,myDist3;
const int trigPin = 9;
const int echoPin = 8;
const int trigPin2 = 12;
const int echoPin2 = 11;
const int trigPin3 = 3;
const int echoPin3 = 13;
long duration,duration2,duration3;
int distance,distance2,distance3;
String myString;


void setup() { 
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
 
 
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(trigPin3,OUTPUT);
  pinMode(echoPin3,INPUT);
}

void loop() { 
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*.034/2;
  myDist = String(distance);

  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  duration2 = pulseIn(echoPin2,HIGH);
  distance2 = duration2*.034/2;
  myDist2 = String(distance2);

  digitalWrite(trigPin3,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3,LOW);
  duration3 = pulseIn(echoPin3,HIGH);
  distance3 = duration3*.034/2;
  myDist3 = String(distance3);

  myString = myDist + "   " + myDist2 + "   " + myDist3;



 lcd.print(myString); // Prints "Arduino" on the LCD 
 delay(1000); // 3 seconds delay 
 
 lcd.clear(); // Clears the LCD screen 
}