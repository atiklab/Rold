int motor1Pin1 = 5; 
int motor1Pin2 = 6; 

int motor2Pin1 = 7; 
int motor2Pin2 = 8; 


int led = 13;
int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
   
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
  
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    
  
    Serial.begin(9600);
     pinMode(led, OUTPUT); 
}

void loop() {
   if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;}
  
  
   if (state == '1') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW); 
        
          Serial.println("Go Forward!");
         
       
    }
    else if (state == '2') { 
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
       
        Serial.println("Turn Left");
         
    }
    // if the state is '3' the motor will Stop
    else if (state == '3' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
      
          Serial.println("STOP!");
         
        
     
    }
    // if the state is '4' the motor will turn right
    else if (state == '4') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        
          Serial.println("Turn Right");
         
       
    }
    // if the state is '5' the motor will Reverse
    else if (state == '5') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        Serial.println("Reverse!");
         
    }
    
    
     else if (state == '6') {
     digitalWrite(led, HIGH);   
    }
    
     else if (state == '7') {
     digitalWrite(led, LOW);
    }
    
    
     else if (state == '8') {
   
    }
    
     else if (state == '9') {
     
    }
}
