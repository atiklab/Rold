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
int m1 = 11;
int m2 = 12; 

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
  pinMode(m1, OUTPUT); 
  pinMode(m2, OUTPUT); 
}

//Main Program
void loop() {
  // read the input channels

  ch1 = pulseIn (chA,HIGH);  //Read and store channel 1
  Serial.print ("Ch1:");  //Display text string on Serial Monitor to distinguish variables
  Serial.print (ch1);     //Print in the value of channel 1
  Serial.print ("|");
 
  ch2 = pulseIn (chB,HIGH);
  Serial.print ("Ch2:");
  Serial.print (ch2);
  Serial.print ("|");
 
  ch3 = pulseIn (chC,HIGH);
  Serial.print ("Ch3:");
  Serial.print (ch3);
  Serial.print ("|");
 
  ch4 = pulseIn (chD,HIGH);
  Serial.print ("Ch4:");
  Serial.print (ch4);
  Serial.print ("|");
 
  ch5 = pulseIn (chE,HIGH);
  Serial.print ("Ch5:");
  Serial.print (ch5);
  Serial.print ("|");
 
  ch6 = pulseIn (chF,HIGH);
  Serial.print ("Ch6:");
  Serial.print (ch6);
  Serial.print ("|");
 
if((ch6<1000))//&&ch3>900)
digitalWrite(led, HIGH);
else 
digitalWrite(led, LOW);


 if((ch2>1300))
 {
digitalWrite(m1, HIGH);
digitalWrite(m2, HIGH);
 }

 
 else if(ch1>1320)
  {
digitalWrite(m1, HIGH);
digitalWrite(m2, LOW);
 }
else if(ch1<1285) 
 {
digitalWrite(m1, LOW);
digitalWrite(m2, HIGH);
 }
  else
     {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
     }

}

