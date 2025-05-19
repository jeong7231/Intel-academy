#define motorPin 9
#define BUTTON_OFF 0
#define BUTTON1_ON 1
#define BUTTON2_ON 2
const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;
int motorPWM = 0;
volatile int buttonState;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(motorPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button1Isr, RISING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button2Isr, RISING);

  Serial.begin(9600);
  Serial.println("start setup()");
}

void loop() {
  if(buttonState != BUTTON_OFF)
  {
    if(buttonState == BUTTON1_ON) {
      if(motorPWM > 0)
      {
        motorPWM -= 25;
      }
    }
    else if(buttonState == BUTTON2_ON) {
        if(motorPWM < 250)
        {
          motorPWM += 25;
        }
    }
    analogWrite(motorPin, motorPWM);
    Serial.println(motorPWM);
    delay(100);
    buttonState = BUTTON_OFF;
    //attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button1Isr, FALLING);
    //attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button2Isr, FALLING);
  }
}

  void button1Isr()
  {
      buttonState = BUTTON1_ON;
      //detachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN));
  }
  void button2Isr()
  {
      buttonState = BUTTON2_ON;
      //detachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN));
  }

