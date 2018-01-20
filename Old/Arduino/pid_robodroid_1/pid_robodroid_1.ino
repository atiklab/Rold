#include <QTRSensors.h>
#define NUM_SENSORS2  2
#define Kp .05 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .17 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 250 // max speed of the robot
#define leftMaxSpeed 250 // max speed of the robot
#define rightBaseSpeed 100 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 100  // this is the speed at which the motors should spin when the robot is perfectly on the line

#define NUM_SENSORS             3  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN   A8     // emitter is controlled by digital pin 2
int lf = 7; 
int lb = 8; 
int rf = 9; 
int rb = 10; 
int  SPEED=70,MSPEED=130,tspeed=100,ttime=178*2;
int sec=0;
int cr=300;
unsigned int sensors[4];
QTRSensorsAnalog qtra((unsigned char[]) {A1, A2, A3} ,NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19
QTRSensorsAnalog qtra2((unsigned char[]) {  A0, A4},NUM_SENSORS2, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN); 
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
  SPEED=70;
 mway('f');
  delay(200) ;
  mway('s');
  delay(80) ;
for (int i = 0; i < 38; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
{
  // comment this part out for automatic calibration 
  if ( i  <= 10 || i >= 30 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
     mway('R'); 
   else
     mway('L');
    qtra.calibrate();  
    qtra2.calibrate();  
   delay(10);
mway2(0,0); 
}
//findcenter();

delay(200); // wait for 2s to position the bot before entering the main loop 
    Serial.begin(9600);
    // cturn('L');
  } 

int lastError = 0;

void loop()
{

followline();
}

