#define CORRECTION 700

int AC_LOAD = 3;    // Output to Opto Triac pin. That means connect RLY pin to Arduino Uno's pin number 3.
int dimming = 85;  // Dimming level (0-128)  0 = ON, 128 = OFF
int incomingByte;   // for incoming serial data


int a=11;
int b=9;
int c=10;
int d=8;
int i=0;
String state;
int flag=0;       
int stateStop=0;


void setup() {                
  // initialize the digital pin as an output.
  pinMode(a, OUTPUT); 
 pinMode(b, OUTPUT);   
 pinMode(c, OUTPUT);  
 pinMode(d, OUTPUT);  
   pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(0, zero_crosss_int, RISING);
  
  Serial.begin(115200);  
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
 while(Serial.available() > 0){

if(i<15)
{
      char c = Serial.read(); 
     state[i]=c;
     i++;
     state[i]='\0';

}
 flag=0;
} 
    
    
 if (state == "ao") {
       digitalWrite(a, HIGH); 
        if(flag == 0){
          Serial.println("Light1 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == "af") {
       digitalWrite(a, LOW); 
        if(flag == 0){
          Serial.println("Light1 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
     
}
