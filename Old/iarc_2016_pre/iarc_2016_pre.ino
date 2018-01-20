#include <QTRSensors.h>
#define NUM_SENSORS2  2
#define Kp .05 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .17 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 250 // max speed of the robot
#define leftMaxSpeed 250 // max speed of the robot
#define rightBaseSpeed 80 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 80  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  4     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   A8     // emitter is controlled by digital pin 2
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
int  SPEED=70,MSPEED=130,tspeed=100,ttime=350;
int sec=0;
int cr=300;
unsigned int sensors[4];
QTRSensorsRC qtrrc((unsigned char[]) { A2, A3, A4, A5} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19
QTRSensorsRC qtrrc2((unsigned char[]) {  A0, A7},NUM_SENSORS2, TIMEOUT, EMITTER_PIN); 
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
  } 

int lastError = 0;

void loop()
{
 MazeSolve();
}
void followline()
{
   lastError = 0;
  while(1)
  {
    sensorread();
        int error = position - 1500;

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;


  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < -rightMaxSpeed) rightMotorSpeed = -rightMaxSpeed; // keep the motor speed positive
  if (leftMotorSpeed < -leftMaxSpeed) leftMotorSpeed = -leftMaxSpeed; // keep the motor speed positive

if((position!=0)&&(position!=3000)&&((sensorValues2[0]<cr)||(sensorValues2[1]<cr)))
   {
     mway2(leftMotorSpeed,rightMotorSpeed);
   }
formaze:
if((sensorValues2[0]>cr)||(sensorValues2[1]>cr))
{
  mway('s');
  return;
}
if((sensors[0]<cr)&&(sensors[1]<cr)&&(sensors[2]<cr)&&(sensors[3]<cr))
{
  mway('s');
  return;
}
if((sensors[0]>cr)&&(sensors[1]>cr)&&(sensors[2]>cr)&&(sensors[3]>cr))
{
  mway('s');
  return;
}
//AcuteAngle:
// if ((sec!=1)&&((position==0)||(position==3000)))//&&(position2<1500))
//  {
//    SPEED= MSPEED;
//   mway('L'); 
//  }
//  
//  else if ((position2==1000)&&((position==0)||(position==3000))&&(sec==1))
//  {
//    SPEED= MSPEED;
//   mway('R'); 
//  }

//Feedback:
//  if ((sensorValues2[0]>cr)&&(sensorValues2[1]>cr))
//{
//sec=3;
//SPEED=50;
// mway('f'); 
//}
//else if ((sensorValues2[0]>cr)&&(sensorValues2[1]<cr))
//{
//sec=2;
//}
//else if ((sensorValues2[0]<cr)&&(sensorValues2[1]>cr))
//{
//sec=1;
//}
//  
// 
  }
//    mway('f');
//  delay(250);
  mway('s');
}
int tdelay=50;
void simplify_path()
{
  // only simplify the path if the second-to-last turn was a 'B'
  if(path_length < 3 || path[path_length-2] != 'B')
    return;

  int total_angle = 0;
  int i;
  for(i=1;i<=3;i++)
  {
    switch(path[path_length-i])
    {
      case 'R':
        total_angle += 90;
  break;
      case 'L':
  total_angle += 270;
  break;
      case 'B':
  total_angle += 180;
  break;
    }
  }

  // Get the angle as a number between 0 and 360 degrees.
  total_angle = total_angle % 360;

  // Replace all of those turns with a single one.
  switch(total_angle)
  {
    case 0:
  path[path_length - 3] = 'S';
  break;
    case 90:
  path[path_length - 3] = 'R';
  break;
    case 180:
  path[path_length - 3] = 'B';
  break;
    case 270:
  path[path_length - 3] = 'L';
  break;
  }

  // The path is now two steps shorter.
  path_length -= 2;

} // end simplify_path
void cturn(char dir)
{
  switch(dir)
  {
    // Turn left 90deg
    case 'L': 
    SPEED=tspeed;
    mway('L');
    delay(ttime) ;
    mway('s');
    break;
    case 'R': 
    SPEED=tspeed;
    mway('R');
    delay(ttime) ;
    mway('s');
    break;
    case 'B': 
    SPEED=tspeed;
    mway('L');
    delay(2*ttime) ;
    mway('s');
    break;
    case 'S':
    break;
  }
}
    
void turn()
{
  if(vleft==1)    //left 
  {
    SPEED=tspeed;
    mway('L');
  delay(ttime) ;
  mway('s');
    path[path_length] = 'L';
    path_length ++;
    simplify_path();
  }
  else if(vstraight==1)   //straight
  {
    mway('f');
    mway('s');
    path[path_length] = 'S';
    path_length ++;
    simplify_path();
  }
  else if(vright==1)    //right
  {
    SPEED=tspeed;
    mway('R');
  delay(ttime) ;
  mway('s');
    path[path_length] = 'R';
    path_length ++;
    simplify_path();
  }
  else            //U turn
  {
    SPEED=tspeed;
    mway('L');
  delay(2*ttime) ;
  mway('s');
    path[path_length] = 'B';
    path_length ++;
    simplify_path();
  }
}
void MazeSolve()
{
  while(1)
  {
   followline();
    vleft=0;
    vstraight=0;
    vright=0;
    SPEED=70;  //to go in line
    mway('f');
   delay(20);
   mway('s');
    sensorread();
    if(sensorValues2[0]>cr)
    vleft=1;
    if(sensorValues2[1]>cr)
    vright=1;
    SPEED=70;    //pass intersection
    mway('f');
   delay(tdelay);
   mway('s');
   sensorread();
   if((sensors[0]>cr)||(sensors[1]>cr)||(sensors[2]>cr)||(sensors[3]>cr))
   vstraight=1;
   if((sensors[0]>cr)&&(sensors[1]>cr)&&(sensors[2]>cr)&&(sensors[3]>cr))
  {
  goto returnpath;
  }
   turn();
  } // end running solved
  returnpath:
    for(i=0;i<path_length;i++)
    if(path[i]=='L')
    revpath[path_length-i-1]='R';
    else if(path[i]=='R')
    revpath[path_length-i-1]='L';
    else
    revpath[path_length-i-1]=path[i];

    pathprint:
    for( i=0;i<path_length;i++)
    Serial.print(path[1]);
    Serial.println();
    for( i=0;i<path_length;i++)
    Serial.print(revpath[1]);
    Serial.println();

    return_preparation:
    SPEED=tspeed;
    mway('L');
    delay(2*ttime) ;
    mway('s');

    while(1)
    {
      sensorread();
      if((sensors[0]>cr)||(sensors[1]>cr)||(sensors[2]>cr)||(sensors[3]>cr))
      break;
    }

for(i=0;i<path_length;i++)
    {
      // SECOND MAIN LOOP BODY  
    followline();
    SPEED=70;    //to in line
    mway('f');   
   delay(tdelay);
   mway('s');
   cturn(revpath[i]);

   followline();
    }
     followline();
  END:
   while(1)
  {
    mway('s');
    
    for( i=0;i<path_length;i++)
    Serial.print(path[1]);
    Serial.println();
    for( i=0;i<path_length;i++)
    Serial.print(revpath[1]);
    Serial.println();
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  }
  mway('s');
} // end MazeSolve
void sensorread()
{

   position = qtrrc.readLine(sensors); 
   position2 = qtrrc2.readLine(sensorValues2);

  Serial.print(position);
  Serial.print('\t');
    Serial.print(sensorValues2[0]);
    Serial.print('\t');
    Serial.print(sensorValues2[1]);
    Serial.print('\t'); 
  Serial.println(position2); 
}
int state=0;
int flag=0; 
int stateStop=0;


void mway(int state)
{
int lspeed=  SPEED;
int rspeed=  SPEED;
if (state == 'f') {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0); 
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);
          Serial.println("Go Forward!");
    }
    else if (state == 'l') {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);
          Serial.println("SL");
    }
    else if (state == 'L') {
        analogWrite(lf, 0);
        analogWrite(lb, lspeed); 
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);
          Serial.println("HL");
    }
        else if (state == 'm') {
        analogWrite(lf, 0);
        analogWrite(lb, lspeed); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
          Serial.println("BL");
     }
    else if (state == 'b') {
        analogWrite(lf, 0);
        analogWrite(lb, lspeed); 
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);
          Serial.println("BACK");
    }
    else if (state == 'r') {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
          Serial.println("SR");
    }
    else if (state == 'R') {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);
          Serial.println("HR");
    }
    else if (state == 'q') {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);
          Serial.println("BR");
    }

    else if (state == 's') {
        analogWrite(lf, 0); 
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        //analogWrite(led, 0);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
}

void mway2(int lspeed,int rspeed )
{
  if (rspeed==0)
  {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
  }
  else if(rspeed>0)
  {
        analogWrite(lf, rspeed);
        analogWrite(lb, 0);  
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        analogWrite(lf, 0);
        analogWrite(lb, rspeed);  
  }
if (lspeed==0)
  {
        analogWrite(rf, 0);
        analogWrite(rb, 0); 
  }
  else if(lspeed>0) 
  {
        analogWrite(rf, lspeed);
        analogWrite(rb, 0);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        analogWrite(rf, 0);
        analogWrite(rb, lspeed);  
  }

}
