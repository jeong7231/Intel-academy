#include <ezButton.h>
#define motorPin 9
const int BUTTON_NUM = 2;
const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;


// 255의 10% 는 25.5
int motorPwm = 0; 



ezButton buttonArray[] = {
  ezButton(BUTTON_1_PIN),
  ezButton(BUTTON_2_PIN),
};

void setup() {
  // put your setup code here, to run once:
  for (byte i = 0; i < BUTTON_NUM; i++) {
    buttonArray[i].setDebounceTime(50); // set debounce time to 50 milliseconds
  }
  pinMode(motorPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("start setup()");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  for (byte i = 0; i < BUTTON_NUM; i++)
    buttonArray[i].loop(); // MUST call the loop() function first

  if (buttonArray[0].isPressed()) 
  {
    if(motorPwm>0)
    {
      motorPwm-=25;
      Serial.println(motorPwm);
    }

  }
  else if(buttonArray[1].isPressed())
  {
    if(motorPwm<250)
    {
      motorPwm+=25;
      Serial.println(motorPwm);
    }

  }

  analogWrite(motorPin, motorPwm);

  // for (byte i = 0; i < BUTTON_NUM; i++) {
  //   // 눌리는시점
  //   if (buttonArray[i].isPressed()) {
  //     Serial.print("The button ");
  //     Serial.print(i + 1);
  //     Serial.println(" is pressed");
  //   }

  //   // 떼는 시점
  //   if (buttonArray[i].isReleased()) {
  //     Serial.print("The button ");
  //     Serial.print(i + 1);
  //     Serial.println(" is released");
  //   }
  // }
}


