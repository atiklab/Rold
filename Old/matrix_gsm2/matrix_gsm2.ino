#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 9); // RX, TX
/*this keypad tutorial number one by omar tarek 29-06-2014 */
byte h=0,v=0;    //variables used in for loops
const unsigned long period=50;  //little period used to prevent error
unsigned long kdelay=0;        // variable used in non-blocking delay 
const byte rows=4;             //number of rows of keypad
const byte columns=4;            //number of columnss of keypad
const byte Output[rows]={A2,A3,A4,A5}; //array of pins used as output for rows of keypad
const byte Input[columns]={A6,A7,A8,A9}; //array of pins used as input for columnss of keypad
int seg[7]={31,33,35,37,39,41,43};
//int bal[5]={};
int ndis[]={32,34,36,38,40,45,47,49,51,53,42,44,46,48,50,52};
int a;
char buffers[64];
int segcc[7]={14,15,16,17,18,19,20};
int ndiscc[]={2,3,4,5,6,7};
int dig=6;
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13; 
int buttonState = 0;
int count=0;
void setup() 
{
  for( a=0;a<7;a++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(seg[a],OUTPUT);
  }
    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
//  for( a=0;a<5;a++)  //for loop used to make pin mode of outputs as output
//  {
//  pinMode(bal[a],OUTPUT);
//  }
  for( a=0;a<16;a++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(ndis[a],OUTPUT);
  }
  for(byte i=0;i<rows;i++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(Output[i],OUTPUT);
  }
  for(byte s=0;s<columns;s++)  //for loop used to makk pin mode of inputs as inputpullup
  {
    pinMode(Input[s],INPUT_PULLUP);
  }
    for( a=0;a<7;a++)  
  {
  pinMode(segcc[a],OUTPUT);
  }
  for( a=0;a<dig;a++) 
  {
  pinMode(ndiscc[a],OUTPUT);
  }
  mySerial.begin(9600);
  Serial.begin(9600); //to use serial monitor we set the buad rate
}
void loop()
{
keycall();
display7();
display7cc();
//gsmreceive();
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    enter2();
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

void gsmreceive(){
  while(mySerial.available())
{
buffers[count++]=mySerial.read();
if (count==64) break;
}
Serial.write(buffers,count);
clearbuffer();
count=0;

}

void clearbuffer()
{
  for(int c=0;c<count;c++)
  buffers[c]=NULL;
}

