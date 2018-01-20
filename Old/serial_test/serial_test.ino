int flag,state;
int s[6];

void setup() {
Serial.begin(115200);  

}

void loop() {
  if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    } 
    
        if(flag == 0){
          Serial.write(state);
          Serial.println();
          flag=1;
        }
}
