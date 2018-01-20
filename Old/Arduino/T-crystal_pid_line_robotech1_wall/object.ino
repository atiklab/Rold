void obsence()
{

  digitalWrite(trigPin, LOW);
 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(5); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;

  if (distance >= 500 || distance <= 0){
    Serial.println("Out of range");
  }
 
//  digitalWrite(ltrigPin, LOW);   
//  delayMicroseconds(2); 
//  digitalWrite(ltrigPin, HIGH);
//  delayMicroseconds(10); 
//  digitalWrite(ltrigPin, LOW);
//  duration1 = pulseIn(lechoPin, HIGH);
//  distance1 = (duration1/2) / 29.1;
//  lposition=distance1;
  if (distance>15)
 ob=0;
  if (distance<15)
ob=1;
//  if (distance1>20)
// wa=0; 
//  if (distance1<20)
//wa=1;
}
void object()
{
          
          Serial.println("object");
        mway2(cspeed,-cspeed);
      delay(600);
      mway2(100,250);
        delay(1430);
        mway2(cspeed,-cspeed);
      delay(650);
      mway2(0,0);
      
      
}

