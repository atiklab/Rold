
int sensorread()
{
   sum=0;
   ls=0;
   rs=0;
  // read the input on analog pin 0:
  for (int i=0;i<NUM_SENSORS;i++){
    
  sv[i] = analogRead(sensors[i]);
  // print out the value you read:

  if(sv[i]>threshold[i])
    sv2[i]=a;
    else
    sv2[i]=1-a;
  Serial.print(sv[i]);
  Serial.print('\t');
  }
   

   for (int i=1;i<(NUM_SENSORS-1);i++)
   {
    ls=ls+sv2[i];
    rs=rs+(1000*(i-1)*sv2[i]);
    sum=sum*10+sv2[i];
   }
   if (ls==0)
   {
    if (position>1000)
    position=2000;
    else
    position=0;
   }
   else
   position=rs/ls;
   Serial.print(sum);
    Serial.print('\t');
    Serial.print(position);
    Serial.print('\t');
    Serial.print(distance);
    Serial.print(" cm");
    Serial.print('\t');
    Serial.print(distance1);
    Serial.print(" cm");
     Serial.print('\t');
   Serial.println();
   // obsence();
   wallsence();
   delayMicroseconds(500);
}
void calibration()
{
  for (int i=0;i<NUM_SENSORS;i++)
{
    maxv[i] = analogRead(sensors[i]);
    minv[i] = analogRead(sensors[i]);
}

mway2(cspeed,-cspeed);   //right 
 for (int j=0;j<100;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(3); 
 }
  
mway2(0,0);  //stop
delay(50);
mway2(-cspeed,cspeed);    //left
 for (int j=0;j<200;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(3); 
 }
 mway2(0,0);  
delay(50);  
mway2(cspeed,-cspeed); //right
 for (int j=0;j<100;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(3); 
 }  
mway2(0,0);   
delay(50); 
for(i=0;i<NUM_SENSORS;i++)
{
threshold[i]= minv[i] + (maxv[i]-minv[i])/2;
Serial.print(threshold[i]);
  Serial.print('\t');
}
}
