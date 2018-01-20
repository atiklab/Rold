int tdelay=50;
void turn()
{
  if(vleft==1)
  {
    SPEED=tspeed;
    mway('L');
  delay(ttime) ;
  mway('s');
  }
  else if(vstraight==1)
  {
    mway('f');
    mway('s');
  }
  else if(vright==1)
  {
    SPEED=tspeed;
    mway('R');
  delay(ttime) ;
  mway('s');
  }
  else
  {
    SPEED=tspeed;
    mway('L');
  delay(2*ttime) ;
  mway('s');
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
    SPEED=70;
    mway('f');
   delay(20);
   mway('s');
    sensorread();
    if(sensorValues2[0]>cr)
    vleft=1;
    if(sensorValues2[1]>cr)
    vright=1;
    SPEED=70;
    mway('f');
   delay(tdelay);
   mway('s');
   sensorread();
   if((sensors[0]>cr)||(sensors[1]>cr)||(sensors[2]>cr)||(sensors[3]>cr))
   vstraight=1;
   while((sensors[0]>cr)&&(sensors[1]>cr)&&(sensors[2]>cr)&&(sensors[3]>cr))
  {
    sensorread();
    delay(50);
  }
   turn();
  } // end running solved
  END:
  mway('s');
} // end MazeSolve
