#include <QTRSensors.h>
#define NUM_SENSORS2  2
#define Kp .05 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .17 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 250 // max speed of the robot
#define leftMaxSpeed 250 // max speed of the robot
#define rightBaseSpeed 250 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 250  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  5     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   A8     // emitter is controlled by digital pin 2
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ms=0,ols,ors;
int  SPEED=70,MSPEED=130,tspeed=100,ttime=357,cspeed =70;;
int sec=0;
int cr=300;
int sensors[]={A0,A1,A2,A3,A4};
int sv[NUM_SENSORS],temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];
int sv2[NUM_SENSORS];
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
calibration();

delay(200); // wait for 2s to position the bot before entering the main loop 
    Serial.begin(115200);
  } 

int lastError = 0;

void loop()
{
 
 MazeSolve();
}

