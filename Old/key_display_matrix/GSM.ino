char num[]={'p',' ','0','0',' ','0','0','0','0','0','0','0','0','0','0','0'};
char callnum[]={"ATD+8801830259379;"};
char tem;
char smsnum[]={"AT+CMGS=\"+8801830259379\"\r"};// Replace x with mobile number
char text[]={"Your account refilled from KU_GSM Project by Tk XX.00."};
 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println(smsnum); // Replace x with mobile number
  delay(1000);
  mySerial.println(text);// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  num[0]='p';
}
void call()
{
  mySerial.println(callnum);
  num[0]='p';
}
void cstring()
{  
            for(int b=0;b<11;b++)
            {
              callnum[6+b]=num[5+b];
            }
            for(int b=0;b<11;b++)
            {
              smsnum[12+b]=num[5+b];
            }
            text[48]=num[2];
            text[49]=num[3];
            Serial.println(num);
            Serial.println(callnum);
            Serial.println(smsnum);
            Serial.println(text);
}
 void Recharge()
{
  mySerial.println("AT+CUSD=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CUSD=1,\"*322#\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
   mySerial.println("AT+CUSD=1,\"3\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second 
    mySerial.println("AT+CUSD=1,\"2\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CUSD=1,\"01613130903\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CUSD=1,\"26\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CUSD=1,\"1994\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CUSD=1,\"0\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  num[0]='p';
}
 void USSD()
{
  mySerial.println("AT+CUSD=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  
  num[0]='p';
}
