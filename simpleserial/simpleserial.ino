#include "printf.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial.println("hello");
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("hello there");
delay(1000);
}
