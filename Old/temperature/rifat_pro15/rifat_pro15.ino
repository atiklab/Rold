float temp;
int tempPin = 1;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int m=6;

int mspeed=0;
void setup()
{
  Serial.begin(9600);
  pinMode(m, OUTPUT);
   pinMode(13, OUTPUT);
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
  Serial.print("*C ");
  
  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.setCursor(6, 1);
  lcd.print("C, ");
  lcd.setCursor(9, 1);
  lcd.print(farh);
  lcd.setCursor(13, 1);
  lcd.print("F ");
  if(temp<34){
  mspeed=0;
  digitalWrite(13,LOW); }
  else
  {mspeed=250;
  digitalWrite(13, HIGH);
  }
  Serial.print(mspeed);
  
   Serial.println();
  delay(1000);
}
