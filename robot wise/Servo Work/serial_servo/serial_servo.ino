#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
Servo myservo1;
int state;
int potpin = 0;  // analog pin used to connect the potentiometer
int val = 0;    // variable to read the value from the analog pin 

void setup() 
{ 
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object 
  myservo1.attach(5);
  Serial.begin(115200);
} 

void loop() 
{ 
  state = Serial.read();            
  val = map(val, 0, 179, 0, 179); 

  if (state == '1') {
    if (val<180)
      val = val + 10;
        myservo.write(val); 
    Serial.println(val);  
  myservo1.write(179-val); 
  }
  else if (state == '2') { 
    if (val>0)
      val = val - 10;
        myservo.write(val); 
    Serial.println(val);  
  myservo1.write(179-val); 
  }

 
} 

