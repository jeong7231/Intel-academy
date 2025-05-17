// 버튼 토글식 led on/off
#define buttonPin 2
#define ledPin 13

int buttonState = 0; 
int buttonState2 = 0;
int ledState = 0;
int cnt = 0;


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
    if(buttonState != buttonState2)
    {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);

      Serial.print("ledState : ");
      Serial.println(ledState);

      cnt++;
      Serial.print("count : ");
      Serial.println(cnt);

      delay(100);
      
    }
    
    
  }
  buttonState2 = buttonState;
}

// high 들어올때만 카운트

