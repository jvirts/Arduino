#include <TM1638.h>
#include <TimeLib.h>
#include <DS3231.h>
#include <Wire.h>

DS3231 myRTC;

//choose digital pins compatibles with your board
#define STB 7 // Strobe digital pin
#define CLK 9 // clock digital pin
#define DIO 8 // data digital pin
byte init_hour;
byte init_minute;
byte init_second;
bool h12Flag;
bool pmFlag;
const unsigned long DEFAULT_TIME = 1356998400; // Jan 1 2013
TM1638 tm(CLK,DIO,STB);
int pause_sec = 0;
int pause_min = 0;
int pause_hr = 0;

void setup() {
  h12Flag = false;
  pmFlag = false;
  init_hour = 0;
  init_minute = 0;
  init_second = 0;
  Wire.begin();
  Serial.begin(115200);
  setTime(DEFAULT_TIME);
  tm.reset();
  //tm.test();
  myRTC.setHour(init_hour);
  myRTC.setMinute(init_minute);
  myRTC.setSecond(init_second);
}
void loop() {
                       /*0*/ /*1*/ /*2*/ /*3*/ /*4*/ /*5*/ /*6*/ /*7*/ /*8*/ /*9*/
  uint8_t digits[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };

  static uint8_t digit = 0;

  int sec = myRTC.getSecond() - pause_sec;
  int sec_hi = sec/10;
  int sec_lo = sec - sec_hi*10;
  
  int min = myRTC.getMinute() - pause_min;
  int min_hi = min/10;
  int min_lo = min - min_hi*10;
  int hr = myRTC.getHour(h12Flag,pmFlag) - pause_hr;
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
  if (buttons==1){
    while(buttons!=2){
    pause_sec = pause_sec + 1;
    delay(1000);
    if (pause_sec == 60){
      pause_sec = 0;
      pause_min = pause_min + 1;
    }
    if (pause_min == 60){
       pause_min = 0;
       pause_hr = pause_hr + 1;
    }
    buttons = tm.getButtons();
 //  Serial.println(buttons);
   }
 //  Serial.println("outside of buttons==1");
  }
  //Serial.println(buttons);
delay(1000);

  
}