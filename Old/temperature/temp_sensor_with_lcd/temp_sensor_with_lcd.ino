
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int val;
int tempPin = 1;

void setup() {
  lcd.begin(16, 2);
  lcd.print("TEMPRATURE = ");
}

void loop() {
 
  val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
lcd.setCursor(0, 1);
lcd.print(cel);
lcd.setCursor(6, 1);
lcd.print("*C ");
lcd.setCursor(10, 1);
lcd.print(farh);
lcd.setCursor(14, 1);
lcd.print("*F");
Serial.print(cel);
Serial.print("*C ");
Serial.print(farh);
Serial.print("*F");
//Serial.println();
delay(1000);

}

