// 버튼이 연결된 핀 번호 정의
#define BUTTON 2
// LED가 연결된 핀 번호 정의
#define LED 13

// 현재 버튼 상태 저장 변수 (HIGH: 눌림, LOW: 안 눌림)
int button_state = 0;
// 직전 반복(loop)에서의 버튼 상태 저장 변수
int last_button_state = 0;
// LED의 현재 상태 저장 변수 (HIGH: 켜짐, LOW: 꺼짐)
int led_state = 0;


// 디바운스 처리를 위한 마지막 상태 변경 시간 저장 변수
unsigned long last_debounce_time = 0;
// 디바운스 딜레이(버튼 떨림 무시 시간, ms 단위)
const unsigned long debounce_delay = 50;

// 이전 루프에서의 시간 저장 변수
unsigned long prev_time = 0;
// LED가 토글(ON/OFF)될 때마다 걸린 시간(밀리초)을 저장하는 배열
unsigned long loop_duration[10] = {0};
// loop_duration 배열의 인덱스
int loop_index = 0;

void setup() {
  Serial.begin(9600);          // 시리얼 통신 시작 (속도: 9600bps)
  pinMode(LED, OUTPUT);        // LED 핀을 출력 모드로 설정
  pinMode(BUTTON, INPUT);      // 버튼 핀을 입력 모드로 설정
  prev_time = millis();        // 현재 시간(밀리초) 저장
}

void loop() 
{
  unsigned long current_time = millis(); // 현재 시간(밀리초) 읽기
  int reading = digitalRead(BUTTON);     // 버튼 핀의 현재 상태 읽기

  // 버튼 상태가 직전 상태와 다르면(변화가 감지되면) 
  if (reading != last_button_state) 
  {
    last_debounce_time = current_time;   // 마지막 변화 시간 갱신 (디바운스 시작)
  }

  // 디바운스 딜레이가 지났는지 확인
  if ((current_time - last_debounce_time) > debounce_delay) 
  {
    // 버튼 상태가 이전에 저장한 버튼 상태와 다르면(진짜 변화라면) 변화 없으면 밑에 코드 실행 X
    if (reading != button_state) 
    {
      button_state = reading;  // 버튼 상태 갱신

      // 버튼이 눌렸을 때(HIGH)
      if (button_state == HIGH) 
      {
        // LED 상태를 반전시킴 (켜짐<->꺼짐)
        led_state = !led_state;
        Serial.print("led_state : ");
        Serial.println(led_state);
        digitalWrite(LED, led_state);

        // LED가 토글되는 순간의 루프 시간(이전 토글 이후 경과 시간) 측정
        unsigned long loopTime = current_time - prev_time;
        loop_duration[loop_index] = loopTime; // 배열에 저장
        loop_index++;                         // 인덱스 증가
        Serial.print("count : ");
        Serial.println(loop_index);

        // 10번 측정이 끝나면 시리얼로 출력
        if (loop_index == 10) {
          Serial.print("millis(): ");
          for (int i = 0; i < 10; i++) 
          {
            Serial.print(loop_duration[i]); // 각 측정값 출력
            Serial.print(" ");
          }
          Serial.print("\n"); // 줄바꿈
          loop_index = 0;     // 인덱스 초기화
        }
      }
    }
  }

  last_button_state = reading;   // 다음 루프를 위해 현재 버튼 상태 저장
  prev_time = current_time;      // 다음 루프를 위해 현재 시간 저장
}
