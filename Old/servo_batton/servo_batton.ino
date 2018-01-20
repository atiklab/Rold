#include <Servo.h>

Servo myservo; // creating myservo object
int buttonPin = 7;
int buttonPin2 = 6;
int servoPin = 9;
int buttonState = 0; // set buttonState
int buttonState2 = 0;

void setup()
{
myservo.attach(servoPin);
pinMode(buttonPin, INPUT);
}

void loop()
{ buttonState = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);
if (buttonState == HIGH)
myservo.write(0);
else if (buttonState2 == HIGH)
myservo.write(180); 
else
myservo.write(80);
}
