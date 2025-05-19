// 버튼 토글식 led on/off
#define buttonPin 2
#define ledPin 13

int buttonState = 0; 
int buttonState2 = 0;
int ledState = 0;


void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  buttonState = digitalRead(buttonPin);

  if(buttonState)
  {
    if(buttonState2 != buttonState)
    {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);

      Serial.print("ledState : ");
      Serial.println(ledState);
    }
    
  }
  buttonState2 = buttonState;
}



