#include <TM1638.h>
#include <TimeLib.h>


//choose digital pins compatibles with your board
#define STB 7 // Strobe digital pin
#define CLK 9 // clock digital pin
#define DIO 8 // data digital pin
const unsigned long DEFAULT_TIME = 1356998400; // Jan 1 2013
TM1638 tm(CLK,DIO,STB);

void setup() {
  Serial.begin(115200);
  setTime(DEFAULT_TIME);
  tm.reset();
  tm.test();
}



void loop() {
                       /*0*/ /*1*/ /*2*/ /*3*/ /*4*/ /*5*/ /*6*/ /*7*/ /*8*/ /*9*/
  uint8_t digits[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };

  static uint8_t digit = 0;
  int sec = second();
  int sec_hi = sec/10;
  int sec_lo = sec - sec_hi*10;
  int min = minute();
  int min_hi = min/10;
  int min_lo = min - min_hi*10;
  int hr = hour();
  int hr_hi = hr/10;
  int hr_lo = hr - hr_hi*10;
  tm.displayDig(0,digits[sec_lo]);
  tm.displayDig(1,digits[sec_hi]);
  tm.displayDig(2,digits[min_lo]);
  tm.displayDig(3,digits[min_hi]);
  tm.displayDig(4,digits[hr_lo]);
  tm.displayDig(5,digits[hr_hi]);

  

  uint8_t buttons = tm.getButtons();
  tm.writeLeds(buttons);


  
}