
#include <SoftwareSerial.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <math.h>

HMC5883L compass;
const byte rxPin = 2;
const byte txPin = 3;

SoftwareSerial mySerialData = SoftwareSerial(A0,A1);
SoftwareSerial mySerialMotor = SoftwareSerial(rxPin, txPin);
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





void setup() {
  Serial.begin(9600);
  mySerialData.begin(9600);
  mySerialMotor.begin(9600);
  Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println("Could not find a valid HMC5883L sensor, check wiring!");
    delay(500);
  }
  Serial.println("found HMC5883L");
  compass.setRange(HMC5883L_RANGE_1_3GA);
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
  compass.setDataRate(HMC5883L_DATARATE_15HZ);
  compass.setSamples(HMC5883L_SAMPLES_1);
  checkSettings();

  Vector raw = compass.readRaw();
  Vector norm = compass.readNormalize();
  float x_norm = norm.XAxis;
  x_norm = abs(fmod(x_norm,360));
  float y_norm = norm.YAxis;
  float z_norm = norm.ZAxis;
  // put your setup code here, to run once:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  
    //mySerialMotor.write(194); //194 = C2.  Set motor 1 forward
   // mySerialMotor.write(60); // 127 is full speed
   // delay(500);
    //mySerialMotor.write(201); //202 = C9.  Set motor 2 forward.  Note motor is wired backward
    //mySerialMotor.write(202);
    //mySerialMotor.write(60);
    int ikount = 0;
    Serial.println(x_norm);
      while ((ikount < 10000 ) ) {
        ikount = ikount + 1;
        myInt.intPoint = ikount;
        mySerialData.write(myInt.binary,4);
        norm = compass.readNormalize();
        x_norm = norm.XAxis;
        x_norm = abs(fmod(x_norm,360));
        y_norm = abs(fmod(norm.YAxis,360));
        z_norm = abs(fmod(norm.ZAxis,360));
        myFloat.floatingPoint = x_norm;
        mySerialData.write(myFloat.binary,4);
        myFloat.floatingPoint = y_norm;
        mySerialData.write(myFloat.binary,4);
        myFloat.floatingPoint = z_norm;
        mySerialData.write(myFloat.binary,4);


      
        Serial.print(x_norm);
        Serial.print(" ");
        Serial.print(y_norm);
        Serial.print(" ");
        Serial.println(z_norm);
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

void checkSettings()
{
  Serial.print("Selected range: ");
  
  switch (compass.getRange())
  {
    case HMC5883L_RANGE_0_88GA: Serial.println("0.88 Ga"); break;
    case HMC5883L_RANGE_1_3GA:  Serial.println("1.3 Ga"); break;
    case HMC5883L_RANGE_1_9GA:  Serial.println("1.9 Ga"); break;
    case HMC5883L_RANGE_2_5GA:  Serial.println("2.5 Ga"); break;
    case HMC5883L_RANGE_4GA:    Serial.println("4 Ga"); break;
    case HMC5883L_RANGE_4_7GA:  Serial.println("4.7 Ga"); break;
    case HMC5883L_RANGE_5_6GA:  Serial.println("5.6 Ga"); break;
    case HMC5883L_RANGE_8_1GA:  Serial.println("8.1 Ga"); break;
    default: Serial.println("Bad range!");
  }
  
  Serial.print("Selected Measurement Mode: ");
  switch (compass.getMeasurementMode())
  {  
    case HMC5883L_IDLE: Serial.println("Idle mode"); break;
    case HMC5883L_SINGLE:  Serial.println("Single-Measurement"); break;
    case HMC5883L_CONTINOUS:  Serial.println("Continuous-Measurement"); break;
    default: Serial.println("Bad mode!");
  }

  Serial.print("Selected Data Rate: ");
  switch (compass.getDataRate())
  {  
    case HMC5883L_DATARATE_0_75_HZ: Serial.println("0.75 Hz"); break;
    case HMC5883L_DATARATE_1_5HZ:  Serial.println("1.5 Hz"); break;
    case HMC5883L_DATARATE_3HZ:  Serial.println("3 Hz"); break;
    case HMC5883L_DATARATE_7_5HZ: Serial.println("7.5 Hz"); break;
    case HMC5883L_DATARATE_15HZ:  Serial.println("15 Hz"); break;
    case HMC5883L_DATARATE_30HZ: Serial.println("30 Hz"); break;
    case HMC5883L_DATARATE_75HZ:  Serial.println("75 Hz"); break;
    default: Serial.println("Bad data rate!");
  }
  
  Serial.print("Selected number of samples: ");
  switch (compass.getSamples())
  {  
    case HMC5883L_SAMPLES_1: Serial.println("1"); break;
    case HMC5883L_SAMPLES_2: Serial.println("2"); break;
    case HMC5883L_SAMPLES_4: Serial.println("4"); break;
    case HMC5883L_SAMPLES_8: Serial.println("8"); break;
    default: Serial.println("Bad number of samples!");
  }

}
