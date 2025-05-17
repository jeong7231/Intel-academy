#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
#include <MsTimer2.h>


DS1302 rtc(4, 5, 6);  // CE, DATA, CLK
Time t;
LiquidCrystal_I2C lcd(0x27, 16, 2);


char day[4] = { '\0' };
char line1[17] = { '\0' };
char line2[17] = { '\0' };

void setup() {

  // RTC작동, 시간변경 방지 건들지말것
  rtc.halt(false);       
  rtc.writeProtect(true); 
  //

  Serial.begin(115200);  
  lcd.init();
  lcd.backlight();

  MsTimer2::set(1000, clock);  
  MsTimer2::start();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void clock(void) {
  t = rtc.getTime();

  strncpy(day, rtc.getDOWStr(), 3);

  sprintf(line1, " %04d %02d %02d     ", t.year, t.mon, t.date);

  sprintf(line2, " %02d:%02d:%02d %s", t.hour, t.min, t.sec, day);

  serial();
}

void serial(void) {
  Serial.println("-------------------------------------");

  Serial.print(" ");
  Serial.print(t.year);
  Serial.print(" ");
  Serial.print(t.mon);
  Serial.print(" ");
  Serial.print(t.date);
  Serial.println();

  Serial.print(" ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(":");
  Serial.print(t.sec);
  Serial.print(" ");
  Serial.print(day);
  Serial.println();
}
