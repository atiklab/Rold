void lebelmonitor()
{
  
   // for(int a=0;a<4;a++) 
  
   // level[a] = digitalRead(levelpin[a]);
  
  
    if (digitalRead(levelpin[3])==HIGH)
  {
    lcd.setCursor(6, 0);
    lcd.print("L3");
    l=3;
    df();
     
  }
  else  if (digitalRead(levelpin[2])==HIGH)
  {
    lcd.setCursor(6, 0);
    lcd.print("L2");
    l=2;
  }
  else  if (digitalRead(levelpin[1])==HIGH)
  {
    lcd.setCursor(6, 0);
    lcd.print("L1");
    l=1;
  }
  else  if (digitalRead(levelpin[0])==HIGH)
  {
    lcd.setCursor(6, 0);
    lcd.print("L0");
    l=0;
  }
}
