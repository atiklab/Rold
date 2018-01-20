char num[]={"p 00 01830259379"};
char num2[]={"00000000000"};
char bal[]={"00"};
char callnum[]={"ATD+8801830259379;"};
char dbblnum[]={"AT+CUSD=1,\"01613130903\""};
char amount[]={"AT+CUSD=1,\"26\""};
char pin[]={"1994"};
char tem;
char amount2[]={"ful123"};
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
            for(int b=0;b<11;b++)
            {
              dbblnum[11+b]=num[5+b];
              num2[b]=num[5+b];
            }
            text[48]=num[2];
            text[49]=num[3];
            for(int b=0;b<2;b++)
            {
              amount[11+b]=num[2+b];
              bal[b]=num[2+b];
            }

}

 void DBBL()
{
  mySerial.println("AT+CUSD=1");    //Sets the GSM Module in Text Mode
  delay(2500);  // Delay of 1000 milli seconds or 1 second
 // gsmreceive();
 // gsmreceive();
  mySerial.println("AT+CUSD=1,\"*322#\"");    //Sets the GSM Module in Text Mode
  delay(4500);  // Delay of 1000 milli seconds or 1 second
  //gsmreceive();
  //gsmreceive();
  mySerial.println("AT+CUSD=1,\"3\"");    //Sets the GSM Module in Text Mode
  delay(2500);  // Delay of 1000 milli seconds or 1 second 
 // gsmreceive();
  //gsmreceive();
    mySerial.println("AT+CUSD=1,\"2\"");    //Sets the GSM Module in Text Mode
  delay(2500);  // Delay of 1000 milli seconds or 1 second
  // gsmreceive();
  // gsmreceive();
   mySerial.println(dbblnum);    //Sets the GSM Module in Text Mode
  delay(2500);  // Delay of 1000 milli seconds or 1 second
 //  gsmreceive();
 //  gsmreceive();
   mySerial.println(amount);    //Sets the GSM Module in Text Mode
  delay(2500);  // Delay of 1000 milli seconds or 1 second
 //  gsmreceive();
 //  gsmreceive();
   mySerial.println("AT+CUSD=1,\"1994\"");    //Sets the GSM Module in Text Mode
  delay(2500);  // Delay of 1000 milli seconds or 1 second
 //  gsmreceive();
 //  gsmreceive();
   mySerial.println("AT+CUSD=1,\"0\"");    //Sets the GSM Module in Text Mode
  delay(2500);  // Delay of 1000 milli seconds or 1 second
  num[0]='p';
            Serial.print(num2);
            Serial.print("\t\t");
            Serial.println(bal);
}
 void USSD()
{
  mySerial.println("AT+CUSD=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CUSD=1,\"*222#\"\r");    //Sets the GSM Module in Text Mode
  delay(1000);
  num[0]='p';
            Serial.print(num2);
            Serial.print("\t\t");
            Serial.println(bal);
  //gsmreceive();
}
void sprint(){
            Serial.println(num);
            Serial.println(callnum);
            Serial.println(smsnum);
            Serial.println(dbblnum);
            Serial.println(amount);
            Serial.println(text);
            Serial.println(num2);
            Serial.println(bal);
}
