/* 
 * TimeSerial.pde
 * example code illustrating Time library set through serial port messages.
 *
 * Messages consist of the letter T followed by ten digit time (as seconds since Jan 1 1970)
 * you can send the text on the next line using Serial Monitor to set the clock to noon Jan 1 2013
 T1357002000  
 *
 * A Processing example sketch to automatically send the messages is included in the download
 * On Linux, you can use "date +T%s\n > /dev/ttyACM0" (UTC time zone)
 */ 
 
#include <TimeLib.h>


const unsigned long DEFAULT_TIME = 1356998400; // Jan 1 2013
void setup()  {
  Serial.begin(9600);
  setTime(DEFAULT_TIME);
 // while (!Serial) ; // Needed for Leonardo only
//  pinMode(13, OUTPUT);
//  setSyncProvider( requestSync);  //set function to call when sync required
 // Serial.println("Waiting for sync message");
}

void loop(){ 
        
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.println();
  

  delay(1000);
}



void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}




