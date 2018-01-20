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
          

   if(Serial.available()> 0){  
   val =  Serial.parseInt() ;
 if(val> 0){
    myservo.write(val); 
    Serial.print("value ="); 
    Serial.println(val); 
    delay(40);
   }
//        myservo.write(val); 
//    Serial.println(val);  
//  myservo1.write(179-val); 


   } 
} 

