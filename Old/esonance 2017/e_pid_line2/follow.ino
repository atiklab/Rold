

void followline()
{
   lastError = 0;
  while(1)
  {
    sensorread();
        int error = position - 1500;

int  motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;


  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < -rightMaxSpeed) rightMotorSpeed = -rightMaxSpeed; // keep the motor speed positive
  if (leftMotorSpeed < -leftMaxSpeed) leftMotorSpeed = -leftMaxSpeed; // keep the motor speed positive
if ((sv2[5]==1))
  rfinder();
else if((position!=0)&&(position!=3000)&&(sv2[0]==0)&&(sv2[5]==0))//&&((sensorValues2[0]<cr)||(sensorValues2[1]<cr)))
   {
     mway2(leftMotorSpeed,rightMotorSpeed);
   }
else 
  
  mway2(0,0);
//
// //formaze:
//if((sv2[0]==1)||(sv2[5]==1))
//{
//  mway2(0,0);
//  return;
//}
//if((sv2[1]==0)&&(sv2[2]==0)&&(sv2[3]==0)&&(sv2[4]==0))
//{
//  mway2(0,0);
//  return;
//}
//if((sv2[1]==1)&&(sv2[2]==1)&&(sv2[3]==1)&&(sv2[4]==1))
//{
//  mway2(0,0);
//  return;
//}
//   else // if (((position==0)||(position==3000)))
//{
//  if (vleft==1)
//  mway2(-250,250);
//  if (vright==1)
//  mway2(250,-250);
//}

//AcuteAngle:
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

//// for stop unwanted time
//if((sv2[0]==0)&&(sv2[1]==0)&&(sv2[2]==0)&&(sv2[3]==0)&&(sv2[4]==0)&&(sv2[5]==0))//||((position==0)&&(position==3000)))
//{
//  mway2(0,0);
//  return;
//}
//
//if((sv2[5]==1)&&((position>0)&&(position<3000)))//||((position==0)&&(position==3000)))
//{
//  mway2(0,0);
//  return;
//}
}
//mway2(0,0);
}
