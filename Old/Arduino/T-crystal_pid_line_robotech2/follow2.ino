void PIDline()
{
   lastError = 0;
   int last_proportional=0;
   int integral=0;
  while(1)
  {
    sensorread();
int proportional = (int)position - 2000;

  // Compute the derivative (change) and integral (sum) of the
  // position.
  int derivative = proportional - last_proportional;
  integral += proportional;

  // Remember the last position.
  last_proportional = proportional;

  // Compute the difference between the two motor power settings,
  // m1 - m2.  If this is a positive number the robot will turn
  // to the right.  If it is a negative number, the robot will
  // turn to the left, and the magnitude of the number determines
  // the sharpness of the turn.  You can adjust the constants by which
  // the proportional, integral, and derivative terms are multiplied to
  // improve performance.
  int power_difference = proportional/20 + integral/10000 + derivative*3/2;

  

  int rightMotorSpeed = (rightBaseSpeed + power_difference);
  int leftMotorSpeed = leftBaseSpeed - power_difference;


  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < -rightMaxSpeed) rightMotorSpeed = -rightMaxSpeed; // keep the motor speed positive
  if (leftMotorSpeed < -leftMaxSpeed) leftMotorSpeed = -leftMaxSpeed; // keep the motor speed positive
 mway2(leftMotorSpeed,rightMotorSpeed);


 
if((position!=0)&&(position!=2000))//&&((sensorValues2[0]<cr)||(sensorValues2[1]<cr)))
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
if((sv2[0]==1)||(sv2[4]==1))//||((position==0)&&(position==3000)))
{
      vleft=0;
    vstraight=0;
    vright=0;
    if(sv2[0]==1)
    vleft=1;
    if(sv2[4]==1)
    vright=1;
}
}
}
