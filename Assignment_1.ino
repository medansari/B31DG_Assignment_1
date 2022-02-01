#define button_1 22
#define button_2 23
#define signal_A 15
#define signal_B 21

#define b 1300
#define c 12

static int a = 100;

int Signal_A()
{
  digitalWrite(signal_A, HIGH);
  delay(a);
  digitalWrite(signal_A, LOW);
  delay(b);
  a += 50;
}

void setup() {
  pinMode(signal_A, OUTPUT);
  pinMode(signal_B, OUTPUT);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
}

void loop() {
for (int c = 12;  c >= 0;    c--)
   {
    Signal_A();
   }
}
