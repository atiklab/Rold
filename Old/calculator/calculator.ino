char num[]={"p    00000000000"};
char num2[]={"00000000000"};
char bal[]={"00"};
char callnum[]={"ATD+8801830259379;"};
char dbblnum[]={"AT+CUSD=1,\"01613130903\""};
char amount[]={"AT+CUSD=1,\"26\""};
char pin[]={"1994"};
char amount2[]={"000000"};
char tem;



/*this keypad tutorial number one by omar tarek 29-06-2014 */
byte h=0,v=0;    //variables used in for loops
const unsigned long period=50;  //little period used to prevent error
unsigned long kdelay=0;        // variable used in non-blocking delay 
const byte rows=4;             //number of rows of keypad
const byte columns=4;            //number of columnss of keypad
const byte Output[rows]={10,3,4,5}; //array of pins used as output for rows of keypad
const byte Input[columns]={6,7,8,9}; //array of pins used as input for columnss of keypad

//int bal[5]={};

int a;
char buffers[64];

int dig=6;
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13; 
int buttonState = 0;
int count=0;
void setup() 
{

   // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
//  for( a=0;a<5;a++)  //for loop used to make pin mode of outputs as output
//  {
//  pinMode(bal[a],OUTPUT);
//  }

  for(byte i=0;i<rows;i++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(Output[i],OUTPUT);
  }
  for(byte s=0;s<columns;s++)  //for loop used to makk pin mode of inputs as inputpullup
  {
    pinMode(Input[s],INPUT_PULLUP);
  }


  Serial.begin(9600);
  }
void loop()
{

keycall();

//gsmreceive();

}


