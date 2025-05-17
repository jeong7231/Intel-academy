#define ADJ_RES A1
#define LED 9

int sensorValue;
int sensorValueOld;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  pinMode(A1, INPUT); // 생략 가능
}

void loop() {
  sensorValue = analogRead(ADJ_RES); 

  if(abs(sensorValue - sensorValueOld) > 50 )
  {
    Serial.print("Analog : ");
    Serial.println(sensorValue);
    
    // Analog : 0~1023 PWM : 0~255   
    int PWM = map(sensorValue, 0, 1023, 15, 255); 

    if(PWM > 100)
    {
      analogWrite(LED, PWM);
    }

    else 
    {
      analogWrite(LED, 0); 

    }

    Serial.print("PWM : ");
    Serial.println(PWM);
    Serial.print("Volt : ");
    Serial.println(5.0 * sensorValue / 1024.0);
    sensorValueOld = sensorValue;
  }
  
}
