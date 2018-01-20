#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
Servo myservo1;
Servo myservo2; 
int val = 100;
int val2 = 30;
int val3 = 0;

int lf=2;
int lb=3;
int rf=4;
int rb=5;

int el=6;
int er=7;

int speedX = 0;
int speedY = 0;

int mspeed=255;
int cspeed=200;
int tm=200;
int state;
int flag=0;  

void setup() {
  myservo.attach(9);
  myservo1.attach(10);
  myservo2.attach(11);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(115200);
  myservo1.write(val);
   myservo.write(val2);
   //time_test();

}

void loop() {
   if(Serial.available() > 0){     
     char command = Serial.read(); 


      switch (command) {

      /* Commands send by Android app.
         Format: #VALUE where # is the letter prefix and VALUE is an interger 0-255
         Example: X100 == Move in x direction at speed of 100 */

      case 'Y':   /* Command accelerometer tilt in y direction */
      case 'W':   /* Command joystick y-axis*/
        speedY = Serial.parseInt();;
        break;

      case 'X':   /* Command accelerometer tilt in x direction */
      case 'A':   /* Command joystick x-axis */
        speedX = Serial.parseInt();;
        break;

      default:
        //sendResponse("Arduino Tank: Unknown command \"%c\"", command);

        break;
    }

   }

   mrun(speedX, speedY);
}




