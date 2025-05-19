/*
 WiFiEsp test: ClientTest
 http://www.kccistc.net/
 작성일 : 2019.12.17 
 작성자 : IoT 임베디드 KSH
*/
#define DEBUG
//#define DEBUG_WIFI
#define AP_SSID "embA"
#define AP_PASS "embA1234"
#define SERVER_NAME "10.10.141.84"
#define SERVER_PORT 5000
#define LOGID "JTY_ARD"
#define PASSWD "PASSWD"

#define DHT_PIN 4  //dht11
#define WIFIRX 6   //6:RX-->ESP8266 TX
#define WIFITX 7   //7:TX -->ESP8266 RX
#define MOTOR_PIN 11
#define LED_TEST_PIN 12
#define LED_BUILTIN_PIN 13
#define CDS_PIN A0

#define CMD_SIZE 50
#define ARR_CNT 5
#define DHTTYPE DHT11  //dht11

#include "WiFiEsp.h"
#include "SoftwareSerial.h"
#include <TimerOne.h>
#include <DHT.h>

// 함수 원형 선언
void wifi_Setup();
void wifi_Init();
int server_Connect();
void printWifiStatus();
void timerIsr();
void socketEvent();

char sendBuf[CMD_SIZE];
bool timerIsrFlag = false;

unsigned long secCount = 0;
int sensorPeriod = 0;  // 초기 센서 주기
int cds;
float humi;
float temp;
SoftwareSerial wifiSerial(WIFIRX, WIFITX);
WiFiEspClient client;
DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(LED_TEST_PIN, OUTPUT);     //D12
  pinMode(LED_BUILTIN_PIN, OUTPUT);  //D13
  pinMode(CDS_PIN, INPUT);           //A0 CDS
  Serial.begin(115200);              //DEBUG
  wifi_Setup();
  Timer1.initialize(1000000);        //1000000uS ==> 1Sec
  Timer1.attachInterrupt(timerIsr);  // timerIsr to run every 1 seconds
  dht.begin();
}

void loop() {
  if (client.available()) {
    socketEvent();
  }
  if (timerIsrFlag) {
    timerIsrFlag = false;
    if (sensorPeriod > 0 && !(secCount % sensorPeriod)) {
      cds = analogRead(CDS_PIN);
      cds = map(cds, 0, 1023, 0, 100);
      humi = dht.readHumidity();
      temp = dht.readTemperature();
#ifdef DEBUG
      Serial.print("cds : ");
      Serial.print(cds);
      Serial.print(", temp : ");
      Serial.print(temp);
      Serial.print(", humi : ");
      Serial.println(humi);
      /************************************************************************/
      char tempStr[5];
      char humiStr[5];
      dtostrf(humi, 4, 1, humiStr);  //50.0   4:전체자리수,1:소수이하 자리수
      dtostrf(temp, 4, 1, tempStr);  //25.1
      sprintf(sendBuf, "[%s]SENSOR@%d@%s@%s\r\n", "JTY_SQL", cds, tempStr, humiStr);
      client.write(sendBuf, strlen(sendBuf));
      Serial.println(sendBuf);
      /************************************************************************/
#endif
      if (!client.connected()) {
        server_Connect();
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

  len = client.readBytesUntil('\n', recvBuf, CMD_SIZE);
  client.flush();
#ifdef DEBUG
  Serial.print("recv : ");
  Serial.print(recvBuf);
#endif
  pToken = strtok(recvBuf, "[@]");
  while (pToken != NULL) {
    pArray[i] = pToken;
    if (++i >= ARR_CNT)
      break;
    pToken = strtok(NULL, "[@]");
  }
  if (!strncmp(pArray[1], " New connected", 4))  // New Connected
  {
    Serial.write('\n');
    return;
  } else if (!strncmp(pArray[1], " Alr", 4))  //Already logged
  {
    Serial.write('\n');
    client.stop();
    server_Connect();
    return;
  } else if (!strcmp(pArray[1], "LED")) {
    if (!strcmp(pArray[2], "ON")) {
      digitalWrite(LED_BUILTIN_PIN, HIGH);
    } else if (!strcmp(pArray[2], "OFF")) {
      digitalWrite(LED_BUILTIN_PIN, LOW);
    }
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  } else if (!strcmp(pArray[1], "LAMP")) {
    if (!strcmp(pArray[2], "ON")) {
      digitalWrite(LED_TEST_PIN, HIGH);
    } else if (!strcmp(pArray[2], "OFF")) {
      digitalWrite(LED_TEST_PIN, LOW);
    }
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  } else if (!strcmp(pArray[1], "GETSTATE")) {
    if (!strcmp(pArray[2], "DEV")) {
      sprintf(sendBuf, "[%s]DEV@%s@%s\n", pArray[0], digitalRead(LED_BUILTIN_PIN) ? "ON" : "OFF", digitalRead(LED_TEST_PIN) ? "ON" : "OFF");
    }
  } else if (!strcmp(pArray[1], "MOTOR")) {
    int pwm = atoi(pArray[2]);
    pwm = map(pwm, 0, 100, 0, 255);
    analogWrite(MOTOR_PIN, pwm);
    sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
  } else if (!strcmp(pArray[1], "GETSENSOR")) { ///////////////////////////
    int sensor_period = atoi(pArray[2]);
    sensorPeriod = sensor_period;
    secCount = 0;  
    sprintf(sendBuf, "[%s]sensorPeriod : %dsec\n", LOGID, sensorPeriod);/////////////
    client.write(sendBuf, strlen(sendBuf));
    client.flush();
#ifdef DEBUG
    Serial.print(", send : ");
    Serial.print(sendBuf);
#endif
  }
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
  do {
    WiFi.init(&wifiSerial);
    if (WiFi.status() == WL_NO_SHIELD) {
#ifdef DEBUG_WIFI
      Serial.println("WiFi shield not present");
#endif
    } else
      break;
  } while (1);

#ifdef DEBUG_WIFI
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(AP_SSID);
#endif
  while (WiFi.begin(AP_SSID, AP_PASS) != WL_CONNECTED) {
#ifdef DEBUG_WIFI
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(AP_SSID);
#endif
  }
#ifdef DEBUG_WIFI
  Serial.println("You're connected to the network");
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
  } else {
#ifdef DEBUG_WIFI
    Serial.println("server connection failure");
#endif
  }
  return 0;
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
