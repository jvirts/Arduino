#define LED_PIN1 7
#define LED_PIN2 6
#define LED_PIN3 5

void setup() {
  // put your setup code here, to run once:
    pinMode(LED_PIN1,OUTPUT);
    pinMode(LED_PIN2,OUTPUT);
    pinMode(LED_PIN3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(LED_PIN1,HIGH);
   delay(1000);
   digitalWrite(LED_PIN1,LOW);
   digitalWrite(LED_PIN2,HIGH);
   delay(1000);
   digitalWrite(LED_PIN2,LOW);
   digitalWrite(LED_PIN3,HIGH);
   delay(1000);
   digitalWrite(LED_PIN3,LOW);
}
