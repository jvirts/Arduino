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
String myDist;
const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance;


void setup() { 
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
 
 
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
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

 lcd.print(myDist); // Prints "Arduino" on the LCD 
 delay(1000); // 3 seconds delay 
 
 lcd.clear(); // Clears the LCD screen 
}