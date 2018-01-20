#include <QTRSensors.h>
#define NUM_SENSORS2  2
#define Kp .15 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .67 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 250 // max speed of the robot
#define leftMaxSpeed 250 // max speed of the robot
#define rightBaseSpeed 180 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 180  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  4     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   A8     // emitter is controlled by digital pin 2
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
int  SPEED=70,MSPEED=150;

QTRSensorsRC qtrrc((unsigned char[]) { A2, A3, A4, A5} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19
QTRSensorsRC qtrrc2((unsigned char[]) {  A0, A7},NUM_SENSORS2, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];
unsigned int sensorValues2[NUM_SENSORS2];
void setup()
{

  
  int i;
for (int i = 0; i < 40; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
{
  // comment this part out for automatic calibration 
  if ( i  < 10 || i >= 30 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
     mway('R'); 
   else
     mway('L');
    qtrrc.calibrate();  
    qtrrc2.calibrate();  
   delay(10);
mway2(0,0); 
}
delay(200); // wait for 2s to position the bot before entering the main loop 
    Serial.begin(9600);
    /* comment out for serial printing
    
    Serial.begin(9600);
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtrrc.calibratedMinimumOn[i]);
      Serial.print(' ');
    }
    Serial.println();

    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtrrc.calibratedMaximumOn[i]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
    */
  } 

int lastError = 0;

void loop()
{
  unsigned int sensors[4];
  int position = qtrrc.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  unsigned int position2 = qtrrc2.readLine(sensorValues2);
  int error = position - 1500;

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;
  Serial.print(position);
  Serial.print('\t');
    Serial.print(sensorValues2[0]);
    Serial.print('\t');
    Serial.print(sensorValues2[1]);
    Serial.print('\t'); 
  Serial.println(position2); 
   
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < -rightMaxSpeed) rightMotorSpeed = -rightMaxSpeed; // keep the motor speed positive
  if (leftMotorSpeed < -leftMaxSpeed) leftMotorSpeed = -leftMaxSpeed; // keep the motor speed positive
//if(sensorValues2[0]>800)
//{
//  qtrrc2.readLine(sensorValues2);
//  mway('L');
//}
//else
if((position!=0)&&(position!=3000))
   {
     mway2(leftMotorSpeed,rightMotorSpeed);
   }
     else if ((position2==0)&&((position==0)||(position==3000)))//&&(position2<1500))
  {
    SPEED= MSPEED;
   mway('L'); 
  }
  
  else if ((position2==1000)&&((position==0)||(position==3000)))
  {
    //SPEED= MSPEED;
   mway('R'); 
  }
   
}
  

