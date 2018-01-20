void sensorread()
{

   position = qtra.readLine(sensors); 
   position2 = qtra2.readLine(sensorValues2);

  Serial.print(position);
  Serial.print('\t');
    Serial.print(sensorValues2[0]);
    Serial.print('\t');
    Serial.print(sensorValues2[1]);
    Serial.print('\t'); 
  Serial.println(position2); 
}
void sensorread2()
{

  qtra.read(sensorValues);

  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }

  Serial.println();
  
 // delay(50);
}

void time_test()
{

    mway2(cspeed,-cspeed);
    qtra.calibrate(); 
    mway2(0,0);

    
     for (i = 0; i < NUM_SENSORS; i++)
{
  
Serial.print(qtra.calibratedMinimumOn[i]);
Serial.print(' ');
}
Serial.println();

for (i = 0; i < NUM_SENSORS; i++)
{
Serial.print(qtra.calibratedMaximumOn[i]);
Serial.print(' ');
}
Serial.println();
  
    //delay(50);

  }
