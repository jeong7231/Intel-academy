/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/digital/Button/
*/

// constants won't change. They're used here to set pin numbers:
//const int buttonPin = 2;  // the number of the pushbutton pin
//const int ledPin = 13;    // the number of the LED pin
#define buttonPin 3
#define ledPin 13

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int buttonStateOld = 0; 
int buttonFlag = 0;
int cnt=0;
void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if(buttonState != buttonStateOld)
  {
    if(buttonState)
    {
      buttonFlag = !buttonFlag;
      Serial.print("buttonFlag : ");
      Serial.println(buttonFlag);
      // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
      if (buttonFlag == HIGH) {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
      } else {
        // turn LED off:
        digitalWrite(ledPin, LOW);
      }
      Serial.print("cnt : ");
      Serial.println(cnt++);
    }
    buttonStateOld = buttonState;
  }
}
