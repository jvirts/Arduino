#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>




int buttonState = 0;

RF24 radio(9,8); // CE, CSN  
const byte address[6] = "00002";

void setup() {
  Serial.begin(9600);
  Serial.println("receive program starts here");
  pinMode(10,OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setChannel(10);   //added by JV
  radio.setPALevel(RF24_PA_HIGH);   //was PA_MIN
  radio.powerUp(); // added by JV
}
void loop() {
  radio.startListening();
  //Serial.println("in loop");
  while (radio.available());
  radio.read(&buttonState, sizeof(buttonState));
  Serial.println(buttonState);
  //Serial.println("radio available");
  delay (100);


}
