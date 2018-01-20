#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
Servo myservo1;
Servo myservo2;
Servo myservo3;
int state;
int wait=200;
void setup() 
{ 
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object 
  myservo1.attach(5);
  myservo2.attach(10);
  myservo3.attach(11);
  Serial.begin(9600);
   myservo.write(80); 
   myservo1.write(100); 
   myservo2.write(10); 
   myservo3.write(180); 
} 

void loop() 
{ 
  state = Serial.read();             

  if (state == '1') {
     myservo2.write(90); 
     myservo3.write(90);
    delay(wait);  
    myservo.write(40); 
    myservo1.write(140);
   delay(wait); 
   myservo2.write(10); 
   myservo3.write(180);  
   delay(wait);
  }
  else if (state == '2') { 
    myservo2.write(90); 
     myservo3.write(90);
    delay(wait);  
    myservo.write(80); 
    myservo1.write(100);
   delay(wait); 
   myservo2.write(10); 
   myservo3.write(180);  
   delay(wait);  
  }
} 

