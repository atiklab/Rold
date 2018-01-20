#include <QTRSensors.h>
#define NUM_SENSORS2  2
#define Kp .05 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .17 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 250 // max speed of the robot
#define leftMaxSpeed 250 // max speed of the robot
#define rightBaseSpeed 150 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 150  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  4     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2
int el=3;
int er=9;
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
int  SPEED=70,MSPEED=150,tspeed=150,ttime=367;
int sec=0;
int cr=300;
unsigned int sensors[4];
QTRSensorsAnalog qtrrc((unsigned char[]) { A1, A2, A3, A4} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19
QTRSensorsAnalog qtrrc2((unsigned char[]) {  A0, A5},NUM_SENSORS2, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];
unsigned int sensorValues2[NUM_SENSORS2];
  int position; 
  int position2;
int vleft,vstraight,vright;
int path_length=0,i;
int path[100],revpath[100];
void setup()
{
  int i;
   pinMode(12, OUTPUT);
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  digitalWrite(el, HIGH);
  digitalWrite(er, HIGH);
  SPEED=150;
 mway('f');
  delay(200) ;
  mway('s');
  delay(80) ;
for (int i = 0; i < 40; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
{
  // comment this part out for automatic calibration 
  if ( i  < 10 || i >= 30 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
     mway('R'); 
   else
     mway('L');
    qtrrc.calibrate();  
    qtrrc2.calibrate();  
   delay(100);
mway2(0,0); 
}

delay(200); // wait for 2s to position the bot before entering the main loop 
    Serial.begin(9600);
  } 

int lastError = 0;

void loop()
{
 
 MazeSolve();
}

