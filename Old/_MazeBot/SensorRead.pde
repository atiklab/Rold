void readSensors()
{  
  leftCenterReading  = sensorRead(leftCenterSensor);
  leftNearReading    = sensorRead(leftNearSensor);
  leftFarReading     = sensorRead(leftFarSensor);
  rightCenterReading = sensorRead(rightCenterSensor);
  rightNearReading   = sensorRead(rightNearSensor);
  rightFarReading    = sensorRead(rightFarSensor);  

/* // serial printing below for debugging purposes
 Serial.print(leftFarReading);
 Serial.print(" ");
 Serial.print(leftNearReading);  
 Serial.print(" ");
 Serial.print(leftCenterReading);
 Serial.print(" ");
 Serial.print(rightCenterReading);
 Serial.print(" ");
 Serial.print(rightNearReading);
 Serial.print(" ");
 Serial.print(rightFarReading);
 Serial.print(" ");
 delay(200);   */
}



int sensorRead(int Sensor)  //This Function sets the Right and Left sensor value's by Charging a capacitor and timing
                //how long it take to discharge
{
  digitalWrite(Sensor, HIGH);   //Puts a Pin to HIGH (+5v)
  pinMode(Sensor, OUTPUT);      //Turns a Pin to an OUTPUT
  delayMicroseconds(10);         //Charges the Capacitors
  pinMode(Sensor, INPUT);       //Turns a Pin to an INPUT
  digitalWrite(Sensor, LOW);    //Setting a Pin to LOW disables the internal Pull Up

  unsigned long startTime = micros();    //Stores the Time when this process begins
  while(micros() - startTime < maxTimeVal)  //Loops while the current time - the start time is less than the TimeOutValue
  {
    unsigned int time = micros() - startTime;  //Stores the time that it's been looping for
    if(digitalRead(Sensor) == LOW && time < maxTimeVal)  //When the Capacitor is discharged , The Pin will go LOW
    {
      return time;   //Records the amount of time taken for Sensors Capacitor to go LOW
    } 
  }
  return 999;
}
