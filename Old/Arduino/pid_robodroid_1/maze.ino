int tdelay=100;
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
    digitalWrite(12, HIGH);
    SPEED=70;    //pass intersection
    mway('f');
   delay(tdelay);
   mway('s');
   digitalWrite(12, LOW);
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

  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(200);              // wait for a second
 


    return_preparation:
    SPEED=tspeed;
    mway('L');
    delay(2*ttime-50) ;

  

    while(1)
    {
      sensorread();
      if((sensors[0]>cr)||(sensors[1]>cr)||(sensors[2]>cr)||(sensors[3]>cr))
      break;
    }
 digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
 // delay(500);

 
for(i=0;i<path_length;i++)
    {
      // SECOND MAIN LOOP BODY  
    followline();
    digitalWrite(12, HIGH);
    SPEED=70;    //to in line
    mway('f');   
   delay(tdelay);
   mway('s');
   digitalWrite(12, LOW);
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

