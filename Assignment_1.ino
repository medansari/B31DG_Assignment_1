#define button_1 22
#define button_2 23
#define signal_A 15
#define signal_B 21
#define a 100
#define b 1300
#define c 12
#define d 500

void setup() {
  pinMode(signal_A, OUTPUT);
  pinMode(signal_B, OUTPUT);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
}

void loop() {
  digitalWrite(21, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(21, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);   

}
