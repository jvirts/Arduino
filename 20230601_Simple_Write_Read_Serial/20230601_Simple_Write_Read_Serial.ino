
#include <SoftwareSerial.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <math.h>



SoftwareSerial mySerialData = SoftwareSerial(A2,A3);

float a,b,c;

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

int x_norm;



void setup() {
  Serial.begin(9600);
  mySerialData.begin(9600);
  Serial.println("program start");

  // put your setup code here, to run once:

  int incomingByte = 0;
  while (mySerialData.available()==0)
  {
    delay(1000);
    Serial.println("mySerialData not available");
  }
    incomingByte = mySerialData.read();
  Serial.print("first instance incomingByte ");
  Serial.println(incomingByte);

  Serial.println(incomingByte);

 // while(incomingByte != 1)
 // {
 //   delay(1000);
 //   incomingByte = mySerialData.read();
 //   Serial.print('incoming Byte ');
 //   Serial.println(incomingByte);
 // }
  
    //mySerialMotor.write(194); //194 = C2.  Set motor 1 forward
   // mySerialMotor.write(60); // 127 is full speed
   // delay(500);
    //mySerialMotor.write(201); //202 = C9.  Set motor 2 forward.  Note motor is wired backward
    //mySerialMotor.write(202);
    //mySerialMotor.write(60);
    int ikount = 0;
    x_norm = 3.2;
       Serial.println(x_norm);
      while ((ikount < 10000 ) ) {
        ikount = ikount + 1;
        myInt.intPoint = ikount;
        mySerialData.write(myInt.binary,4);
       
        myFloat.floatingPoint = x_norm;
        mySerialData.write(myFloat.binary,4);
       


      
 /*       Serial.print(x_norm);
        Serial.print(" ");
        Serial.print(y_norm);
        Serial.print(" ");
        Serial.println(z_norm); */
    }

   // delay(5000);
    /* mySerialMotor.write(193); //193 = C1.  Set motor 1 reverse
    mySerialMotor.write(60);
    delay(750);
    mySerialMotor.write(194); // set motor 1 forward
    mySerialMotor.write(60); 
    delay(10000);  */
   // mySerialMotor.write(194);
   // mySerialMotor.write(1);
    //mySerialMotor.write(202);
   // mySerialMotor.write(1);
}

void loop() {
  // put your main code here, to run repeatedly:
 

}


