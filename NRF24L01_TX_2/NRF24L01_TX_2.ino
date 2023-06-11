#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define buttonPin1 3

int buttonState1 = 0;
RF24 radio(9,8); // CE, CSN   
const byte address[6] = "00002";
 //buttonState1 = 1;
void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(10,OUTPUT);  //added by JV
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  //radio.printDetails();
  radio.setChannel(10);
  radio.setPALevel(RF24_PA_HIGH);  //was PA_MIN
  radio.powerUp();  //added by JV
  radio.stopListening();
 // radio.printDetails();
}
void loop() {

  delay(1000);
  Serial.println(buttonState1);
   buttonState1 = buttonState1 + 1;
  radio.write(&buttonState1, sizeof(buttonState1));
}
