//This sketch shows how to connect to a bluetooth device
// Arduino -> bluetooth
// Used with Android BlueTerm app
//google play : bluetooth terminal HC-05 앱 설치
#include <SoftwareSerial.h> //Serial library

/**
 * Arduino connection HC-06 connection: 
 * HC-06  | Arduino
 * TX     | 2
 * RX     | 3
*/
// Here, we exchange them -
SoftwareSerial bt (2,3);  //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
#define BUTTON 4       // 버튼은 2번 핀에 연결
#define LED 12       // LED는 9번 핀에 연결
#define LEDPin 13 //LED PIN on Arduino
int btdata; // the data given from the computer
boolean lastButton = LOW;     // 버튼의 이전 상태 저장
boolean currentButton = LOW;    // 버튼의 현재 상태 저장
boolean ledOn = false;      // LED의 현재 상태 (on/off)
void setup() {
    Serial.begin(9600);
    bt.begin(9600); //Open the serial port
    bt.println ("Bluetooth ON. Press 1 or 0 to blink LED.."); //write to serial->App에전송
    pinMode (LEDPin, OUTPUT);
    pinMode (LED, OUTPUT);    // LED 핀을 출력으로 설정
    pinMode (BUTTON, INPUT);    // 버튼 핀을 입력으로 설정 (생략 가능)
    Serial.println(__FILE__);
    
}

void loop() {
    //  delay (100); //prepare for data
    if (bt.available()) { //if serial is available
        btdata = bt.read(); //read from the serial connection
        Serial.println(btdata);

        if (btdata == '1') {
            digitalWrite (LEDPin, HIGH); //if we get 1, turn on the LED
            bt.println("LED ON!!");
            Serial.println("LED_ON!!");
        }
        if (btdata == '0') { //if we received 0, turn off the led
            digitalWrite (LEDPin, LOW);
            bt.println("LED OFF!!");
            Serial.println("LED_OFF!!");
        }
    }
    currentButton = debounce(lastButton);   // 디바운싱된 버튼 상태 읽기
    if (lastButton == LOW && currentButton == HIGH)  // 버튼을 누르면...
    {
      ledOn = !ledOn;       // LED 상태 값 반전
      digitalWrite(LED, ledOn);     // LED 상태 변경 
      if(ledOn) 
        bt.println("BUTTON ON!!");
      else
        bt.println("BUTTON OFF!!");
    }
    lastButton = currentButton;     // 이전 버튼 상태를 현재 버튼 상태로 설정
 
//    delay (100); //prepare for data
}
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);  // 버튼 상태 읽기
  if (last != current)      // 이전 상태와 현재 상태가 다르면...
  {
    delay(5);         // 5ms 대기
    current = digitalRead(BUTTON);  // 버튼 상태 다시 읽기
  }
  return current;       // 버튼의 현재 상태 반환
}
