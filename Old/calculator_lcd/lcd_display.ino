void playlcd()
{
  
  int s0,s1,m0,m1;
  
  
  
  
      if(t>gs)
    {
     lcd.setCursor(11, 1);
     lcd.print("Over ");
     df();
     
    }
    else
    {
    st=(millis()/1000);
    if(st!=lt)
    if(t<6000)
    t++;
    
    digitalWrite(motor, HIGH); 
    digitalWrite(led, HIGH);     

     

    s0=(t%60)%10;
    s1=(t%60)/10;
    m0=(t/60)%10;
    m1=(t/600);
    

  
  
  
  lcd.setCursor(11, 1);
  lcd.print(m1);
  lcd.print(m0);
  lcd.print(':');
  lcd.print(s1);
  lcd.print(s0);
  

  
  lt=st;
  }
  
}



/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)   
 */
