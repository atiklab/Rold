float temp;
int tempPin = 1;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
    lcd.begin(16, 2);
  lcd.print("TEMPRATURE = ");
}

void loop()
{
  temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  float farh = (temp*9)/5 + 32;
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.setCursor(6, 1);
  lcd.print("C, ");
  lcd.setCursor(9, 1);
  lcd.print(farh);
  lcd.setCursor(13, 1);
  lcd.print("F ");
  delay(1000);
}
