void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(1,OUTPUT);
pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int zz = 0;
  while(1)
  {
   String zstr = String(zz);
   Serial.println(zstr);
   zz = zz + 1;
   delay(1000);

  }
}
