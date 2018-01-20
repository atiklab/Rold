int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
   Serial.begin(115200);

}

void loop() {
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;}
        if(flag == 0){
           Serial.write(state);
           Serial.println();
          flag=1;
        }
}
