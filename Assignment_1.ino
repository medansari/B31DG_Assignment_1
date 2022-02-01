#define button_1 22
#define button_2 23
#define signal_A 15
#define signal_B 21

#define b 1300

#define d 500

static int a = 100;

int Signal_A()
{
  digitalWrite(signal_A, HIGH);
  delay(a);
  digitalWrite(signal_A, LOW);
  delay(b);
  a += 50;
  Serial.print(a);
  Serial.print("\t");
}

int mode_2()
{
  digitalWrite(signal_A, HIGH);
  delay(a);
  digitalWrite(signal_A, LOW);
  delay(b);
  a -= 50;
  Serial.print(a);
  Serial.print("\t"); 
}

void setup() {
  pinMode(signal_A, OUTPUT);
  pinMode(signal_B, OUTPUT);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  Serial.begin(9600);
}

void loop() {
  while (digitalRead(button_1)== HIGH)
  {
    digitalWrite(signal_A, LOW);
    digitalWrite(signal_B, LOW);
  }
  while (digitalRead(button_1)==LOW && digitalRead(button_2)==LOW)
  {
    a =100;
    for (int c = 12;  c >= 0;    c--)
    {
      Signal_A();
      Serial.print(c);
      Serial.print("\t"); 
    }
    delay(d);
  }
  while (digitalRead(button_2)==HIGH)
  {
    Signal_B();
    a =750;
    for (int c = 12;  c >= 0;    c--)
    {
      mode_2();
      Serial.print(c);
      Serial.print("\t"); 
    }
    delay(d);
  }
}
