
byte keypad() // function used to detect which button is used 
{
 static bool no_press_flag=0;  //static flag used to ensure no button is pressed 
  for(byte x=0;x<columns;x++)   // for loop used to read all inputs of keypad to ensure no button is pressed 
  {
     if (digitalRead(Input[x])==HIGH);   //read evry input if high continue else break;
     else
     break;
     if(x==(columns-1))   //if no button is pressed 
     {
      no_press_flag=1;
      h=0;
      v=0;
     }
  }
  if(no_press_flag==1) //if no button is pressed 
  {
    for(byte r=0;r<rows;r++) //for loop used to make all output as low
    digitalWrite(Output[r],LOW);
    for(h=0;h<columns;h++)  // for loop to check if one of inputs is low
    {
      if(digitalRead(Input[h])==HIGH) //if specific input is remain high (no press on it) continue
      continue;
      else    //if one of inputs is low
      {
          for (v=0;v<rows;v++)   //for loop used to specify the number of row
          {
          digitalWrite(Output[v],HIGH);   //make specified output as HIGH
          if(digitalRead(Input[h])==HIGH)  //if the input that selected from first sor loop is change to high
          {
            no_press_flag=0;                //reset the no press flag;
            for(byte w=0;w<rows;w++) // make all outputs as low
            digitalWrite(Output[w],LOW);
            return v*4+h;  //return number of button 
          }
          }
      }
    }
  }
 return 50;
}
void keycall()
{
  char tem;
  
  if(millis()-kdelay>period) //used to make non-blocking delay
  {
    kdelay=millis();  //capture time from millis function
switch (keypad())  //switch used to specify which button
   {
            case 0:
            Serial.println(1);
            tem='1';
            temnum=1;
            lcd.setCursor(0, 1);
            lcd.print(tem);
           addc();
            
            
            
          
       break;  
            case 1:
            Serial.println(2);
            tem='2';
            temnum=2;
            lcd.setCursor(0, 1);
            lcd.print(tem);
           addc();
            
       break;
            case 2:
            Serial.println(3);
            tem='3';
            temnum=3;
            lcd.setCursor(0, 1);
            lcd.print(tem);
           addc();
           
       break;
            case 3:
            Serial.println("A");
            tem='A';
            lcd.setCursor(0, 1);
            lcd.print(tem);
            af();
       break;
            case 4:
            Serial.println(4);
            tem='4';
            temnum=4;
            lcd.setCursor(0, 1);
            lcd.print(tem);
           addc();
            
       break;
            case 5:
            Serial.println(5);
            tem='5';
            temnum=5;
            lcd.setCursor(0, 1);
            lcd.print(tem);
           addc();
            
       break;
            case 6:
            Serial.println(6);
            tem='6';
            temnum=6;
            lcd.setCursor(0, 1);
            lcd.print(tem);
           addc();
            
       break;
            case 7:
            Serial.println("B");
            tem='B';
            lcd.setCursor(0, 1);
            lcd.print(tem);
            bf();
       break;
            case 8:
            Serial.println(7);
            tem='7';
            temnum=7;
            lcd.setCursor(0, 1);
            lcd.print(tem);
           addc();
            
       break;
            case 9:
            Serial.println(8);
           tem='8';
           temnum=8;
           lcd.setCursor(0, 1);
           lcd.print(tem);
           addc();
            
       break;
            case 10:
            Serial.println(9);
           tem='9';
           temnum=9;
           lcd.setCursor(0, 1);
           lcd.print(tem);
           addc();
            
       break;
            case 11:
            Serial.println("C");
            tem='C';
            lcd.setCursor(0, 1);
           lcd.print(tem);
           cf();
       break;
            case 12:
            Serial.println("*");
            tem='*';
            lcd.setCursor(0, 1);
           lcd.print(tem);
           delc();
       break;
            case 13:
            Serial.println(0);
           tem='0';
           temnum=0;
            lcd.setCursor(0, 1);
           lcd.print(tem);
           addc();
            
       break;
            case 14:
            Serial.println("#");
            tem='#';
            lcd.setCursor(0, 1);
           lcd.print(tem);
           enter();
            
       break;
            case 15:
            Serial.println("D");
            tem='D';
            lcd.setCursor(0, 1);
           lcd.print(tem);
           df();
       break;
            default:
            ;
}
}
}
void enter()
{
  if(mm>99)
    mm=99;
  if(ss>59)
  ss=59;
  gs=mm*60+ss;
gsdisplay();
t=0;
  start();
}

void addc()
{

if (mode==1)
{ 
 if(mm<10) 
  mm=mm*10+temnum;
  else
  mm=temnum;

  if(mm>9)
    mode=0;
}
else
{
  if(ss<10)
  ss=ss*10+temnum;
  else
  ss=temnum;
  if(ss>9)
  mode=1;
}


gsdisplay();

}
void delc()
{

mm=0;
ss=0;
mode=0;
gs=0;
gsdisplay();
}
void start()
{
  ;
}



void af()
{

lcd.setCursor(0, 1);
lcd.print("Auto Full");
t=0;


  start();
}


void bf()
{
  mm=10;
  ss=0;
gs=mm*60+ss;
gsdisplay();
t=0;
  start();
}
void cf()
{
  mm=5;
  ss=0;
  gs=mm*60+ss;
gsdisplay();
t=0;
  start();
}

void df()
{
gs=0;
t=0;
lcd.setCursor(0, 1);
lcd.print("Motor off");
digitalWrite(motor, LOW);   
digitalWrite(led, LOW);   

}

void gsdisplay()
{

lcd.setCursor(1, 1);
lcd.print(" ");
lcd.print(mm/10);
lcd.print(mm%10);
lcd.setCursor(4, 1);
lcd.print(':');
lcd.setCursor(5, 1);
lcd.print(ss/10);
lcd.print(ss%10);
lcd.print(" ");
lcd.print(" ");
}
