#define CORRECTION 700

int AC_LOAD = 3;    // Output to Opto Triac pin. That means connect RLY pin to Arduino Uno's pin number 3.
int dimming = 85;  // Dimming level (0-128)  0 = ON, 128 = OFF
int incomingByte;   // for incoming serial data


int a=11;
int b=9;
int c=10;
int d=8;
int state;
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
  if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;

    } 
    
    
 if (state == 'a') {
       digitalWrite(a, HIGH); 
        if(flag == 0){
          Serial.println("Light1 On");
          Serial.println(state);
          Serial.write(state);
          flag=1; 
        }
    }
    else if (state == 'b') {
       digitalWrite(a, LOW); 
        if(flag == 0){
          Serial.println("Light1 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
      if (state == 'd') {
       digitalWrite(b, HIGH); 
        if(flag == 0){
          Serial.println("Light2 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == 'e') {
       digitalWrite(b, LOW); 
        if(flag == 0){
          Serial.println("Light2 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
     if (state == 'g') {
       digitalWrite(c, HIGH); 
        if(flag == 0){
          Serial.println("Light3 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == 'h') {
       digitalWrite(c, LOW); 
        if(flag == 0){
          Serial.println("Light3 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
     if (state == 'j') {
       digitalWrite(d, HIGH); 
        if(flag == 0){
          Serial.println("Light4 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == 'k') {
       digitalWrite(d, LOW); 
        if(flag == 0){
          Serial.println("Light4 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
    
    if (state == '1') {
       
        if(flag == 0){
    dimming=100-2*10;
     
    delay(10);
          flag=1;
        }
    }
     if (state == '2') {
      
        if(flag == 0){
    dimming=100-3*10;

    delay(10);
          flag=1;
        }
    }
         if (state == '3') {
        
        if(flag == 0){
    dimming=100-4*10;

    delay(10);
          flag=1;
        }
    }
    
    if (state == '4') {
        
        if(flag == 0){
    dimming=100-5*10;
    
    delay(10);
          flag=1;
        }
    }
    
      if (state == '5') {
       
        if(flag == 0){
    dimming=100-9*10;
     
    delay(10);
          flag=1;
        }
    }
        if (state == '0') {
       
        if(flag == 0){
    dimming=100-10;
     
    delay(10);
          flag=1;
        }
    }
}
