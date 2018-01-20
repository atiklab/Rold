int led = 13;
int state;
int flag=0;       
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
        if(flag == 0)
          flag=1;
    }
    else if (state == '2') {
       digitalWrite(led, LOW); 
        if(flag == 0)
          flag=1;
    }

}
