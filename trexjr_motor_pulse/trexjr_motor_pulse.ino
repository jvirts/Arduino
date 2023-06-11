
#include <SoftwareSerial.h>
const byte rxPin = 2;
const byte txPin = 3;

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);


void setup() {
  // put your setup code here, to run once:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.listen();
  mySerial.begin(19200);

}

void loop() {
  // put your main code here, to run repeatedly:
    mySerial.write(194); //194 = C2.  Set motor 1 forward
    mySerial.write(60); // 127 is full speed
   //mySerial.write(201); //202 = C9.  Set motor 2 forward.  Note motor is wired backward
    mySerial.write(202);
    mySerial.write(60);
    delay(500);
    
    /* mySerial.write(193); //193 = C1.  Set motor 1 reverse
    mySerial.write(60);
    delay(750);
    mySerial.write(194); // set motor 1 forward
    mySerial.write(60); 
    delay(10000);  */
    mySerial.write(194);
    mySerial.write(1);
    mySerial.write(202);
    mySerial.write(1);
    delay(2000);

}
