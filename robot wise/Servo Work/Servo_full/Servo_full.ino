
/*
this program taken from arduino Example .
  modified by By Mohannad Rawashdeh
  http://www.genotronex.com
  This code used to control Servo Motor 360 Degree using 
  potebtiometer connected on A0

*/
#include <Servo.h> 
int t=10;
Servo SR04;  // Full rotational
int PinReading=0;
int potentiometer=0;
void setup() {
  // put your setup code here, to run once:
SR04.attach(9);// servo connected to D9
pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  PinReading=analogRead(A0);
  delay(t);
  potentiometer=map(PinReading,0,1023,0,180);
  potentiometer=constrain(potentiometer,0,180);
  SR04.write(potentiometer);
  delay(50);
  
}
