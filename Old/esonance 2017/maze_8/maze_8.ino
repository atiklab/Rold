#include <QTRSensors.h>
#define NUM_SENSORS2  2
#define Kp .05 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .17 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 250 // max speed of the robot
#define leftMaxSpeed 250 // max speed of the robot
#define rightBaseSpeed 100 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 100  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  4     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   A10     // emitter is controlled by digital pin 2
int lf = 2; 
int lb = 3; 
int rf = 7; 
int rb = 8; 
int  SPEED=70,MSPEED=130,tspeed=100,ttime=178*2;
int cspeed=200;
int tm=200;

int sec=0;
int cr=300;
unsigned int sensors[4];
QTRSensorsAnalog qtra((unsigned char[]) {  A3, A4, A5,A6} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19
QTRSensorsAnalog qtra2((unsigned char[]) {  A0, A9},NUM_SENSORS2, TIMEOUT, EMITTER_PIN); 
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

delay(200); // wait for 2s to position the bot before entering the main loop 
    Serial.begin(115200);
    // cturn('L');
  //  time_test();
  } 

int lastError = 0;

void loop()
{
//sensorread2();
  MazeSolve();
}

