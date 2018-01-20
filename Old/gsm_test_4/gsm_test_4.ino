#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 9); // RX, TX
/*this keypad tutorial number one by omar tarek 29-06-2014 */
byte h=0,v=0;    //variables used in for loops
const unsigned long period=50;  //little period used to prevent error
unsigned long kdelay=0;        // variable used in non-blocking delay 
const byte rows=4;             //number of rows of keypad
const byte columns=4;            //number of columnss of keypad

const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13; 
int buttonState = 0;
int count=0;
char num[]={"p    00000000000"};
char num2[]={"01830259379"};
char bal[]={"26"};
char callnum[]={"ATD+8801830259379;"};
char dbblnum[]={"AT+CUSD=1,\"01613130903\""};
char amount[]={"AT+CUSD=1,\"26\""};
char pin[]={"1994"};
char amount2[]={"000000"};
void setup() 
{

  mySerial.begin(9600);
  Serial.begin(9600); //to use serial monitor we set the buad rate
             Serial.println(num2);
            Serial.print("\t\t");
            Serial.println(bal);
}
void loop()
{

//keycall();
//display7();
//display7cc();
//gsmreceive();

}




