void followline()
{
   lastError = 0;
  while(1)
  {
    sensorread();
        int error = position - 1000;

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;


  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < -rightMaxSpeed) rightMotorSpeed = -rightMaxSpeed; // keep the motor speed positive
  if (leftMotorSpeed < -leftMaxSpeed) leftMotorSpeed = -leftMaxSpeed; // keep the motor speed positive

if((position!=0)&&(position!=2000)&&((sensorValues2[0]<cr)||(sensorValues2[1]<cr)))
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

