
//CREDIT to Patrick McCabe for the path Solving Code, visit patrickmccabemakes.com!!

#define leftCenterSensor   12
#define leftNearSensor     4
#define leftFarSensor      3
#define rightCenterSensor  11
#define rightNearSensor    10
#define rightFarSensor     9

int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;

int maxTimeVal = 2000;    //Define to Maximun amount of time allow for the sensor return a Value
int Threshold = 400;

int leftNudge;
int replaystage;
int rightNudge;

#define leapTime 150

#define leftMotor1  5   //Speed
#define leftMotor2  7   //Direction

#define rightMotor1 6   //Speed
#define rightMotor2 8   //Direction

#define led 13

char path[30] = {};
int pathLength;
int readLength;

void setup()
{  
  pinMode(leftCenterSensor, INPUT);
  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  pinMode(rightCenterSensor, INPUT);
  pinMode(rightNearSensor, INPUT);
  pinMode(rightFarSensor, INPUT);
    
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  digitalWrite(led, HIGH);
  delay(1000);
}


void loop()
{  
 readSensors();                                                                                      
 if(leftFarReading<Threshold && rightFarReading<Threshold && (leftCenterReading>Threshold || rightCenterReading>Threshold) )
 {  //Far LEFT & Far RIGHT are over White & (Left or Right) are over the Line
   straight();                                                                                      
 }
 else
 {                                                                                              
   leftHandWall();                                                                                   
 }
}


void leftHandWall()
{
  if(leftFarReading>Threshold && rightFarReading>Threshold)   //If Both are over Black Line
  {
    HLHL();
    delay(leapTime);                                          //Delay for the LeapTime
    readSensors();                                            //Check Sensors
    if(leftFarReading>Threshold || rightFarReading>Threshold) //If Both are still over the Black Line
    {
      done();                                               //DONE, We found the End!!
    }
    if(leftFarReading<Threshold && rightFarReading<Threshold) //If Neither are over Black Turn Left
    { 
      turnLeft();
    }    
  }
  if(leftFarReading>Threshold)                                //If Far Left is over Black
  { 
    HLHL();
    delay(leapTime);                                          //Delay for the LeapTime    
    readSensors();                                            //Check Sensors
    if(leftFarReading<Threshold && rightFarReading<Threshold) //If Neither are over Black Turn Left
    {
      turnLeft();
    }
    else
    {
      done();
    }
  }

  if(rightFarReading>Threshold)                                //If Far Right is over Black
  {
    HLHL();
    delay(leapTime);                                          //Delay for the LeapTime    
    readSensors();                                            //Check Sensors
    if(leftFarReading>Threshold)
    {
      delay(leapTime);
      readSensors();
      if(rightFarReading>Threshold && leftFarReading>Threshold)
      {
        done();
      }
      else
      {
        turnLeft();
        return;
      }
    }  
    readSensors();    
    if(leftFarReading<Threshold && leftCenterReading<Threshold && rightCenterReading<Threshold && rightFarReading<Threshold)
    {   //If Center & Far Left/Right are not over the LINE, Turn Right
      turnRight();
      return;
    }
    
    //PATH SOLVING
    path[pathLength]='S';
   // Serial.println("s");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
    if(path[pathLength-2]=='B')
    {
    //Serial.println("shortening path");
      shortPath();   
    } 
    
    
    straight();
  }
  readSensors();
  if(leftFarReading<Threshold && leftCenterReading<Threshold && rightCenterReading<Threshold && rightFarReading<Threshold && leftNearReading<Threshold && rightNearReading<Threshold)
  {   //If NONE are over line, Turn Around
    turnAround();
  }
}


void done()
{
  LLLL();
  replaystage=1;
  path[pathLength]='D';
  pathLength++;
  while(sensorRead(leftFarSensor)>Threshold)
  {
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
  }
  delay(500);
  replay();
}


void turnLeft()
{ 
  while(sensorRead(rightCenterSensor)>Threshold||sensorRead(leftCenterSensor)>Threshold)
  {
    LHHL();
    delay(2);
    LLLL();
    delay(1);
  }   
  while(sensorRead(rightCenterSensor)<Threshold)
  {
    LHHL();
    delay(2);
    LLLL();
    delay(1);
  }  
 
  
  if(replaystage==0){
    path[pathLength]='L';
    //Serial.println("l");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
      if(path[pathLength-2]=='B'){
        //Serial.println("shortening path");
        shortPath();
      }
  }
   //   Serial.println("Turn Left");
}

void turnRight()
{
  //Serial.println("Turn Right");  
  while(sensorRead(rightCenterSensor)>Threshold)
  {
    HLLH();
    delay(2);
    LLLL();
    delay(1);
  }
  while(sensorRead(rightCenterSensor)<Threshold)
  {
    HLLH();
    delay(2);
    LLLL();
    delay(1);
  }
  while(sensorRead(leftCenterSensor)<Threshold)
  {
    HLLH();
    delay(2);
    LLLL();
    delay(1);
  }  
  
      
  
  if(replaystage==0){
  path[pathLength]='R';
//  Serial.println("r");
  pathLength++;
//  Serial.print("Path length: ");
//  Serial.println(pathLength);
    if(path[pathLength-2]=='B'){
  //    Serial.println("shortening path");
      shortPath();
    }
  }
 
}


void straight()
{
  if(leftCenterReading<Threshold)
  {
    analogWrite(leftMotor1, 100);
    digitalWrite(leftMotor2, LOW);
   //   Serial.println("Veer Right");
  }
  else if(rightCenterReading<Threshold)
  {
    analogWrite(rightMotor1, 100);
    digitalWrite(rightMotor2, LOW);
  //   Serial.println("Veer Left");
  } 
  else
  {
    HLHL();  
   //   Serial.println("Straight");
  } 
}


void turnAround()
{
//  Serial.println("Turn Around");
  HLHL();
  delay(150);
  while(sensorRead(leftCenterSensor)<Threshold)
  {
    LHHL();
    delay(2);
    LLLL();
    delay(1);   
  } 
  path[pathLength]='B';
  pathLength++;
  straight();  
  //Serial.println("b");
  //Serial.print("Path length: ");
  //Serial.println(pathLength);
}


void shortPath()
{
  int shortDone=0;
  if(path[pathLength-3]=='L' && path[pathLength-1]=='R')
  {
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test1");
    shortDone=1;
  } 
  if(path[pathLength-3]=='L' && path[pathLength-1]=='S' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='R';
    //Serial.println("test2");
    shortDone=1;
  } 
  if(path[pathLength-3]=='R' && path[pathLength-1]=='L' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test3");
    shortDone=1;
  } 
  if(path[pathLength-3]=='S' && path[pathLength-1]=='L' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='R';
    //Serial.println("test4");
    shortDone=1;
  }   
  if(path[pathLength-3]=='S' && path[pathLength-1]=='S' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test5");
    shortDone=1;
  }
  if(path[pathLength-3]=='L' && path[pathLength-1]=='L' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='S';
    //Serial.println("test6");
    shortDone=1;
  }
  path[pathLength+1]='D';
  path[pathLength+2]='D';
  pathLength++;
  //Serial.print("Path length: ");
  //Serial.println(pathLength);
  //printPath();  */
}


void printPath()
{
  Serial.println("+++++++++++++++++");
  int x;
  while(x<=pathLength)
  {
    Serial.println(path[x]);
    x++;
  }
  Serial.println("+++++++++++++++++");
}


void replay()
{
  readSensors();
  if(leftFarReading<Threshold && rightFarReading<Threshold)
  {
    straight();
  }
  else
  {
    if(path[readLength]=='D')
    {
      HLHL();
      delay(100);
      LLLL();
      endMotion();
    }
    if(path[readLength]=='L')
    {
      HLHL();
      delay(leapTime);
      turnLeft();
    }
    if(path[readLength]=='R')
    {
      HLHL();
      delay(leapTime);
      turnRight();
    }
    if(path[readLength]=='S')
    {
      HLHL();
      delay(leapTime);
      straight();
    }
    readLength++;
  }
  replay();
}

void endMotion()
{
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(500);
  endMotion();
}
