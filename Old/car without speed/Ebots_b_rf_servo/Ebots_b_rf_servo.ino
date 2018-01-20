#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
Servo myservo1;
Servo myservo2; 
int val = 0;
int val2 = 0;

int motor1Pin1 = 8; 
int motor1Pin2 = 10; 

int motor2Pin1 = 11; 
int motor2Pin2 = 12; 



int led = 13;
int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
  
  myservo.attach(6);
  myservo1.attach(5);
  myservo2.attach(9);
  
   
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
  
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    
   
  
    Serial.begin(1200);
     pinMode(led, OUTPUT); 
}

void loop() {
   if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
  digitalWrite(led, HIGH);}
  
   val = map(val, 0, 179, 0, 179);
   val2 = map(val2, 0, 90, 0, 90);
  
   if (state == '1') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }
         delay(40);
        state=3;
        stateStop=1;
        
    }
    else if (state == '2') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Turn Left");
          flag=1;
        }
         delay(40);
        state=3;
        stateStop=1;
    }
    // if the state is '3' the motor will Stop
    else if (state == '3' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(led, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    // if the state is '4' the motor will turn right
    else if (state == '4') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Turn Right");
          flag=1;
        }
         delay(40);
        state=3;
        stateStop=1;
        
    }
    // if the state is '5' the motor will Reverse
    else if (state == '5') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Reverse!");
          flag=1;
        }
        delay(40);
        state=3;
        stateStop=1;

        
    }
    
    
     else if (state == '6') {
         if (val2<90)
         val2 = val2 + 10;
         myservo2.write(val2);
        if(flag == 0){
          Serial.println("Up");
          flag=1;
        }
        
        delay(40);
        state=3;
        stateStop=1;
    }
    
     else if (state == '7') {
        if (val2>0)
        val2 = val2 - 10;
        myservo2.write(val2);
        if(flag == 0){
          Serial.println("Down");
          flag=1;
        }
        
        delay(40);
        state=3;
        stateStop=1;
    }
    
    
     else if (state == '8') {
        if (val<180)
         val = val + 10;
          myservo.write(val); 
     myservo1.write(179-val);
        if(flag == 0){
          Serial.println("Open");
          flag=1;
        }
        delay(40);
        state=3;
        stateStop=1;
    }
    
     else if (state == '9') {
         if (val>0)
        val = val - 10; 
         myservo.write(val); 
     myservo1.write(179-val);
        if(flag == 0){
          Serial.println("Close");
          flag=1;
        }
        delay(40);
        state=3;
        stateStop=1;
    }
    // else {
    // Serial.println("Wrong Command");
     //}
     
     
     
    
    
    
}
