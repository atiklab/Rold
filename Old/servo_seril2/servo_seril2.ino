#include <Servo.h> 
 
Servo myservo;  
int state; 
void setup() 
{ 
  myservo.attach(9);  
  Serial.begin(9600);
} 
 
void loop() 
{ 
  state = Serial.read();            
  if (state == '1') 
  myservo.write(0);
  else if (state == '2') 
  myservo.write(180); 
  else {
    delay(40);
  //myservo.write(90); 
   }
} 
