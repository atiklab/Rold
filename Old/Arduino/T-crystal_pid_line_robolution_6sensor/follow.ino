int tdelay=60;
void followline()
{
   lastError = 0;
  while(1)
  {
    sensorread();
        int error = position - 1500;

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = b*(rightBaseSpeed + motorSpeed);
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;


  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < -rightMaxSpeed) rightMotorSpeed = -rightMaxSpeed; // keep the motor speed positive
  if (leftMotorSpeed < -leftMaxSpeed) leftMotorSpeed = -leftMaxSpeed; // keep the motor speed positive
 mway2(leftMotorSpeed,rightMotorSpeed);


 
if((position!=0)&&(position!=3000))//&&((sensorValues2[0]<cr)||(sensorValues2[1]<cr)))
   {
     mway2(leftMotorSpeed/b,rightMotorSpeed);
   }
   else // if (((position==0)||(position==3000)))
{
  if (vleft==1)
  mway2(MSPEED/b,-MSPEED);
  if (vright==1)
  mway2(-MSPEED/b,MSPEED);
//  while(1)
//  {
//    sensorread();
//    if((position!=0)&&(position!=2000))
//    break;
//  }
}
AcuteAngle:
if((sv2[0]==1)||(sv2[5]==1))//||((position==0)&&(position==3000)))
{
      vleft=0;
    vstraight=0;
    vright=0;
    if(sv2[0]==1)
    vleft=1;
    if(sv2[5]==1)
    vright=1;
}
}
}
