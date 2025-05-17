#define buttonPin 2
#define ledPin 13

int buttonState = 0;
int buttonState2 = 0;
int ledState = 0;
int cnt = 0;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

unsigned long prevTime = 0;
unsigned long loopDurations[10] = {0};
int loopIdx = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  prevTime = millis();
}

void loop() 
{
  unsigned long currentTime = millis();
  int reading = digitalRead(buttonPin);

  if (reading != buttonState2) 
  {
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceDelay) 
  {
    if (reading != buttonState) 
    {
      buttonState = reading;

      if (buttonState == HIGH) 
      {
        // LED 상태 변경
        ledState = !ledState;
        digitalWrite(ledPin, ledState);


        // 루프 시간 기록 (LED 상태 바뀌는 순간만)
        unsigned long loopTime = currentTime - prevTime;
        loopDurations[loopIdx] = loopTime;
        loopIdx++;

        if (loopIdx == 10) {
          Serial.print("millis: ");
          for (int i = 0; i < 10; i++) 
          {
            Serial.print(loopDurations[i]);
            Serial.print(" ");
          }
          Serial.print("\n");
          loopIdx = 0;
        }
      }
    }
  }

  buttonState2 = reading;
  prevTime = currentTime; // loop 한 바퀴 끝나고 시간 갱신
}
