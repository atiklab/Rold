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

