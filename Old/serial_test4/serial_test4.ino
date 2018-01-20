String readString;
int a=11;
int b=9;
int c=10;
int d=8;
int state;
int flag=0;       
int stateStop=0;
int ahu,bhu,chu,dhu;

int inputPin = 2;               
int pirState = LOW; 
int val = 0;
int human=0;


#define CORRECTION 700

int AC_LOAD = 3;    // Output to Opto Triac pin. That means connect RLY pin to Arduino Uno's pin number 3.
int dimming = 85;  // Dimming level (0-128)  0 = ON, 128 = OFF
int incomingByte;   // for incoming serial data



void setup() {
  Serial.begin(115200);
  
   pinMode(inputPin, INPUT); 
   
     pinMode(a, OUTPUT); 
     pinMode(b, OUTPUT);   
     pinMode(c, OUTPUT);  
     pinMode(d, OUTPUT);  
   pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(0, zero_crosss_int, RISING);
}


void zero_crosss_int()  //function to be fired at the zero crossing to dim the light
{
  int dimtime = (95*dimming);    // For 60Hz =>65    
  delayMicroseconds(dimtime+CORRECTION);    // Wait till firing the TRIAC    
  digitalWrite(AC_LOAD, HIGH);   // Fire the TRIAC
  delayMicroseconds(10);         // triac On propogation delay 
         // (for 60Hz use 8.33) Some Triacs need a longer period
  digitalWrite(AC_LOAD, LOW);    // No longer trigger the TRIAC (the next zero crossing will swith it off) TRIAC
}


void loop() {

  while (Serial.available()) {
   delay(1); 

    char c = Serial.read(); 
    if (c == ',') {
      flag=0;
      break;
    } 
    readString += c; 
  } 

val = digitalRead(inputPin);  
  if (val == HIGH) {          
    if (pirState == LOW) {
      human=1;
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      human=0;
      pirState = LOW;
    }
  }

 if (readString[0] == 'a') {
   
       if (readString[2] == 'n') 
       {
       digitalWrite(a, HIGH); 
       }
       if (readString[2] == 'f') 
       {
       digitalWrite(a, LOW); 
       }
       if (readString[2] == 'u') 
       {
       ahu=1; 
       }

    }
    
    

  if (readString.length() >0) {
    Serial.println(readString); 

    readString=""; 
  }
}
