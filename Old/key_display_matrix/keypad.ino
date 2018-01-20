
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
  if(millis()-kdelay>period) //used to make non-blocking delay
  {
    kdelay=millis();  //capture time from millis function
switch (keypad())  //switch used to specify which button
   {
            case 0:
            Serial.println(1);
            tem='1';
            addc();
            if(num[0]=='c')
            call();
       break;  
            case 1:
            Serial.println(2);
            
            tem='2';
            addc();
            if(num[0]=='c')
            Recharge();
       break;
            case 2:
            Serial.println(3);
            tem='3';
            addc();
       break;
            case 3:
            Serial.println("F1");
            tem='0';
       break;
            case 4:
            Serial.println(4);
            tem='4';
            addc();
       break;
            case 5:
            Serial.println(5);
            tem='5';
            addc();
       break;
            case 6:
            Serial.println(6);
            tem='6';
            addc();
       break;
            case 7:
            Serial.println("F2");
            tem='0';
       break;
            case 8:
            Serial.println(7);
            tem='7';
            addc();
       break;
            case 9:
            Serial.println(8);
           tem='8';
            addc();
       break;
            case 10:
            Serial.println(9);
           tem='9';
            addc();
       break;
            case 11:
            Serial.println("F3");
            tem='0';
       break;
            case 12:
            Serial.println("Enter");
            enter();
       break;
            case 13:
            Serial.println(0);
           tem='0';
            addc();
       break;
            case 14:
            Serial.println("Cancel");
            delc();
       break;
            case 15:
            Serial.println("Mode");
       break;
            default:
            ;
}
}
}
void enter()
{

            if(num[0]=='p')
            num[0]='a';
            else if(num[0]=='a')
            {
              num[0]='c';
              cstring();
            }
            else if(num[0]=='c')
            {
            USSD();

           // num[0]='p';
            }
}

void delc()
{
  if(num[0]=='p')
  {
    for(a=15;a>5;a--)
    {
      num[a]=num[a-1];
    }
    num[5]=' ';
  }
  else   if(num[0]=='a')
  {
    for(a=3;a>2;a--)
    {
      num[a]=num[a-1];
    }
    num[2]=' ';
  }
  else   if(num[0]=='c')
  num[0]='p';
}
void addc()
{
  if(num[0]=='p')
  {
    for(a=6;a<16;a++)
    {
      num[a-1]=num[a];
    }
    num[15]=tem;
  }
  else if(num[0]=='a')
  {
    {
      num[2]=num[3];
    }
    num[3]=tem;
  }

}
