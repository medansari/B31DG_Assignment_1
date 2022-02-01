#define button_1 22       //Assigning button 1 Pin 22
#define button_2 23       //Assigning button 2 Pin 23
#define signal_A 15       //Assigning signal A Pin 15
#define signal_B 21       //Assigning signal B Pin 21

#define b 1300      //defining the time between each pulse 
#define d 500       //defining the time between each waveform

static int a = 100;   //assigning the time for each pulse

int Signal_A()      //starting a function for Signal A
{
  digitalWrite(signal_A, HIGH);       // setting signal high to output a pulse
  delayMicroseconds(a);               // adding delay for the size of the pulse
  digitalWrite(signal_A, LOW);        // setting signal low
  delayMicroseconds(b);               // adding a delay for the time between each pulse
  a += 50;                            // adding 50us to variable a to increase the size of the pulse
  Serial.print(a);                    // testing the value of variable a
  Serial.print("\t");                 // adding a tab 
}

int Signal_B()        //starting a function for Signal B
{
  digitalWrite(signal_B, HIGH);   // setting signal high to output a pulse for oscilloscope trigger
  delayMicroseconds(50);          // setting the delay
  digitalWrite(signal_B, LOW);    // setting the signal low
}

int mode_2()        //starting a function for mode 2
{
  digitalWrite(signal_A, HIGH);         // setting signal high to output a pulse
  delayMicroseconds(a);                 // adding delay for the size of the pulse
  digitalWrite(signal_A, LOW);          // setting signal low
  delayMicroseconds(b);                 // adding a delay for the time between each pulse
  a -= 50;                              // subtracting 50us to variable a to increase the size of the pulse
  Serial.print(a);                      // testing the value of variable a
  Serial.print("\t");                   // adding a tab 
}

void setup() {
  pinMode(signal_A, OUTPUT);        //initialising signal A as output
  pinMode(signal_B, OUTPUT);        //initialising signal B as output
  pinMode(button_1, INPUT);         //initialising button 1 as input
  pinMode(button_2, INPUT);         //initialising button 2 as input
  Serial.begin(9600);               //setting baud rate for serial communication
}

void loop() {
  // while the button 1 is pressed, set signal a and b LOW
  while (digitalRead(button_1)== HIGH)
  {
    digitalWrite(signal_A, LOW);
    digitalWrite(signal_B, LOW);
  }
  // while the button 1 and 2 are not pressed: 
  while (digitalRead(button_1)==LOW && digitalRead(button_2)==LOW)
  {
    a =100;                   //set a = 100
    Signal_B();               // call signal B function
    //loop from the highest value to the lowest:
    for (int c = 12;  c >= 0;    c--)
    {
      Signal_A();           //call signal A function
      Serial.print(c);      //checking the value c 
      Serial.print("\t");   // adding a tab 
    }
    delayMicroseconds(d);   // adding delay between waveforms
  }
  // while the button 2 is pressed:
  while (digitalRead(button_2)==HIGH)
  {
    Signal_B();    // call signal B function
    a =750;        //set a = 750
    //loop from the highest value to the lowest:
    for (int c = 12;  c >= 0;    c--)
    {
      mode_2();              //call mode 2 function
      Serial.print(c);       //checking the value c 
      Serial.print("\t");    // adding a tab
    }
    delayMicroseconds(d);    // adding delay between waveforms
  }
}
