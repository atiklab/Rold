#include <LiquidCrystal.h>
int t=0;
int st,lt;
int mm,ss,ms,gs;
int temnum,mode=0;
int levelpin[4] = {9,10,11,12};  
int level[4] ;  
int motor=8;
int led=13;
int l;

/*this keypad tutorial number one by omar tarek 29-06-2014 */
byte h=0,v=0;    //variables used in for loops
const unsigned long period=50;  //little period used to prevent error
unsigned long kdelay=0;        // variable used in non-blocking delay 
const byte rows=4;             //number of rows of keypad
const byte columns=4;            //number of columnss of keypad
const byte Output[rows]={15,16,17,18}; //array of pins used as output for rows of keypad
const byte Input[columns]={19,20,21,22}; //array of pins used as input for columnss of keypad

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  
  
   Serial.begin(9600);
   
   
    pinMode(motor,OUTPUT);
   // pinMode(led,OUTPUT);
   
  for(int a=0;a<4;a++) 
  {
  pinMode(levelpin[a],INPUT);
  }
 
  
   
     for(byte i=0;i<rows;i++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(Output[i],OUTPUT);
  }
  for(byte s=0;s<columns;s++)  //for loop used to makk pin mode of inputs as inputpullup
  {
    pinMode(Input[s],INPUT_PULLUP);
  }
  
  
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Level:");
  lcd.setCursor(10, 0);
  lcd.print("Timer:");

  lcd.setCursor(9, 0);
  lcd.print("|");
  lcd.setCursor(9, 1);
  lcd.print("|");




}

void loop() {
if(gs>1)
{
playlcd();
}

keycall();
lebelmonitor();
}

