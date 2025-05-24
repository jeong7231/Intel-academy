/*
 WiFiEsp test: ClientTest with Motor Control
http://www.kccistc.net/
작성일 : 2019.12.17 (모터 제어 추가: 2025.05.19)
작성자 : IoT 임베디드 KSH (모터 제어 기능 추가)
*/

#define DEBUG
//#define DEBUG_WIFI
#define AP_SSID "embA"
#define AP_PASS "embA1234"
#define SERVER_NAME "10.10.141.84"
#define SERVER_PORT 5000
#define LOGID "JTY_ARD"
#define PASSWD "PASSWD"

#define WIFITX 7  //7:TX -->ESP8266 RX
#define WIFIRX 6  //6:RX-->ESP8266 TX
#define LED_TEST_PIN 12
#define LED_BUILTIN_PIN 13
#define MOTOR_PIN 11  // PWM 모터 제어 핀

#define CMD_SIZE 50
#define ARR_CNT 5 // 포인트 배열 5개

#include "WiFiEsp.h"
#include "SoftwareSerial.h"
#include <TimerOne.h>

char sendBuf[CMD_SIZE];
volatile bool timerIsrFlag = false; // 타이머 인터럽트 플래그
volatile unsigned long secCount = 0;
int sensorTime;

SoftwareSerial wifiSerial(WIFIRX, WIFITX);
WiFiEspClient client;

void setup() {
  pinMode(LED_TEST_PIN, OUTPUT);     //D12
  pinMode(LED_BUILTIN_PIN, OUTPUT);  //D13
  pinMode(MOTOR_PIN, OUTPUT);        //D9 - PWM 모터 제어핀
  Serial.begin(115200);              // DEBUG
  wifi_Setup();

  Timer1.initialize(1000000); // us 단위 -> 1초
  Timer1.attachInterrupt(timerIsr);
}

void loop() {
  if (client.available()) {
    socketEvent();
  }

  if (timerIsrFlag) {
    timerIsrFlag = false;
    if (!(secCount % 5)) {
      if (!client.connected()) {
        if (!server_Connect()) {
          Serial.println("Reconnection failed.");
        }
      }
    }
  }
}

void socketEvent() {
  int i = 0;
  char* pToken;
  char* pArray[ARR_CNT] = { 0 };
  char recvBuf[CMD_SIZE] = { 0 };
  int len;

  len = client.readBytesUntil('\n', recvBuf, CMD_SIZE - 1); // CMD_SIZE-1 to leave room for '\0'
  recvBuf[len] = '\0'; // 명시적 종료

  while (client.available()) client.read(); // 입력 버퍼 비우기

#ifdef DEBUG
  Serial.print("recv : ");
  Serial.println(recvBuf);
#endif

  pToken = strtok(recvBuf, "[@]");
  while (pToken != NULL && i < ARR_CNT) {
    pArray[i++] = pToken;
    pToken = strtok(NULL, "[@]");
  }

  // pArray[1], [2] 사용 전에 NULL 체크
  if (!pArray[1]) return;

  if (!strncmp(pArray[1], " New", 4)) {
    Serial.write('\n');
    return;
  } else if (!strncmp(pArray[1], " Alr", 4)) {
    Serial.write('\n');
    client.stop();
    server_Connect();
    return;
  } else if (!strcmp(pArray[1], "LED") && pArray[2]) {
    digitalWrite(LED_BUILTIN_PIN, !strcmp(pArray[2], "ON") ? HIGH : LOW);
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  } else if (!strcmp(pArray[1], "LAMP") && pArray[2]) {
    digitalWrite(LED_TEST_PIN, !strcmp(pArray[2], "ON") ? HIGH : LOW);
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  } else if (!strcmp(pArray[1], "GETSTATE") && pArray[2] && !strcmp(pArray[2], "DEV")) {
    sprintf(sendBuf, "[%s]DEV@%s@%s\n", pArray[0],
      digitalRead(LED_BUILTIN_PIN) ? "ON" : "OFF",
      digitalRead(LED_TEST_PIN) ? "ON" : "OFF");
  } else if (!strcmp(pArray[1], "MOTOR") && pArray[2]) {
    int duty = atoi(pArray[2]);  // 문자열을 정수로 변환
  

    int pwm = map(duty, 0, 100, 0, 255);
  
    // 모터 PWM 설정
    analogWrite(MOTOR_PIN, pwm);
  
    // 서버에 응답 전송
    sprintf(sendBuf, "[%s]%s@%d\n", pArray[0], pArray[1], duty);
  } else {
    return; // 예외적인 명령 무시
  }

  client.write(sendBuf, strlen(sendBuf));

#ifdef DEBUG
  Serial.print(", send : ");
  Serial.print(sendBuf);
#endif
}

void timerIsr() {
  timerIsrFlag = true;
  secCount++;
}

void wifi_Setup() {
  wifiSerial.begin(38400);
  wifi_Init();
  server_Connect();
}

void wifi_Init() {
  while (true) {
    WiFi.init(&wifiSerial);
    if (WiFi.status() == WL_NO_SHIELD) {
#ifdef DEBUG_WIFI
      Serial.println("WiFi shield not present");
#endif
    } else {
      break;
    }
  }

#ifdef DEBUG_WIFI
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(AP_SSID);
#endif

  int retry = 0;
  while (WiFi.begin(AP_SSID, AP_PASS) != WL_CONNECTED && retry++ < 10) {
    delay(1000);
#ifdef DEBUG_WIFI
    Serial.print("Retry ");
    Serial.println(retry);
#endif
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection failed. Restart required.");
    while (1); // 또는 software reset
  }

#ifdef DEBUG_WIFI
  Serial.println("Connected to network");
  printWifiStatus();
#endif
}

int server_Connect() {
#ifdef DEBUG_WIFI
  Serial.println("Starting connection to server...");
#endif

  if (client.connect(SERVER_NAME, SERVER_PORT)) {
#ifdef DEBUG_WIFI
    Serial.println("Connected to server");
#endif
    client.print("[" LOGID ":" PASSWD "]");
    return 1;
  } else {
#ifdef DEBUG_WIFI
    Serial.println("Server connection failure");
#endif
    return 0;
  }
}

void printWifiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}