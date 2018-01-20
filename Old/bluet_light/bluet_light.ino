int led = 11;
//int led1 =10;
int led2= 9;
//int led3 =5;
int led1= 13;
int led3  =12;
int state;
int flag=0;       
int stateStop=0;
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
 pinMode(led1, OUTPUT);   
 pinMode(led2, OUTPUT);  
 pinMode(led3, OUTPUT);  
  Serial.begin(115200);  
}

void loop() {
  if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    } 
    
    
 if (state == '1') {
       digitalWrite(led, HIGH); 
        if(flag == 0){
          Serial.println("Light1 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == '2') {
       digitalWrite(led, LOW); 
        if(flag == 0){
          Serial.println("Light1 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
      if (state == '3') {
       digitalWrite(led1, HIGH); 
        if(flag == 0){
          Serial.println("Light2 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == '4') {
       digitalWrite(led1, LOW); 
        if(flag == 0){
          Serial.println("Light2 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
     if (state == '5') {
       digitalWrite(led2, HIGH); 
        if(flag == 0){
          Serial.println("Light3 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == '6') {
       digitalWrite(led2, LOW); 
        if(flag == 0){
          Serial.println("Light3 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
     if (state == '7') {
       digitalWrite(led3, HIGH); 
        if(flag == 0){
          Serial.println("Light4 On");
          Serial.println(state);
          Serial.write(state);
          flag=1;
        }
    }
    else if (state == '8') {
       digitalWrite(led3, LOW); 
        if(flag == 0){
          Serial.println("Light4 Off!");
           Serial.println(state);
           Serial.write(state);
          flag=1;
        }
    }
    
}
