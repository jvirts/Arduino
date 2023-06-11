
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  
}

void loop() {
  // if there's any serial available, read it:
  while (1) {
    int zz = Serial.parseInt();
    Serial.println(zz);
  }
    
    

  
}
