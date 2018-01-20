int led = 13;
int state;
int flag=0;       
int stateStop=0;
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  Serial.begin(9600);  
}

void loop() {
  if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    } 
    
    
 if (state == '1') {
       digitalWrite(led, HIGH); 
        if(flag == 0){
          Serial.println("Light On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == '2') {
       digitalWrite(led, LOW); 
        if(flag == 0){
          Serial.println("Light Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
     else if (state == '3') {
        tone(7, 523, 300);
        delay(300);
        noTone(11);
        if(flag == 0){
          Serial.println("Tone 1");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
     else if (state == '4') {
       tone(7, 494, 500);
        delay(500);
        if(flag == 0){
          Serial.println("Tone 2");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
}
