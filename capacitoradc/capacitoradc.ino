#define LED_PIN1 7
#define LED_PIN2 6

int analogPin = A0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(LED_PIN1,OUTPUT);
    pinMode(LED_PIN2,OUTPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(LED_PIN1,HIGH);
   delay(1000);
   digitalWrite(LED_PIN1,LOW);
   digitalWrite(LED_PIN2,HIGH);
   delay(3000);
   val = analogRead(analogPin);
   Serial.println(val);
     digitalWrite(LED_PIN2,LOW);
   val = analogRead(analogPin);
   Serial.println(val);
   
 
}
