// Define Variables:
const int chA=22;  //Constant variables relating to pin locations
const int chB=24;
const int chC=26;
const int chD=28;
const int chE=30;
const int chF=32;
const int chG=34;
const int chH=36;
int led = 13;

int ch1;  //Varibles to store and display the values of each channel
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int ch7;
int ch8;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // Set input pins
  pinMode(chA, INPUT);
  pinMode(chB,INPUT);
  pinMode(chC,INPUT);
  pinMode(chD,INPUT);
  pinMode(chE,INPUT);
  pinMode(chF,INPUT);
  pinMode(chG,INPUT);
  pinMode(chH,INPUT);
  pinMode(led, OUTPUT);  
}

//Main Program
void loop() {
  // read the input channels

 
  ch3 = pulseIn (chF,HIGH);
  Serial.print ("Ch3:");
  Serial.print (ch3);
  Serial.print ("|");
 
if((ch3<1000))//&&ch3>900)
digitalWrite(led, HIGH);
else 
digitalWrite(led, LOW);
 
delay(500);
}

