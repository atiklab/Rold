void wallsence()
{

  digitalWrite(ltrigPin, LOW);   
  delayMicroseconds(2); 
  digitalWrite(ltrigPin, HIGH);
  delayMicroseconds(5); 
  digitalWrite(ltrigPin, LOW);
  duration1 = pulseIn(lechoPin, HIGH);
  distance1 = (duration1/2) / 29.1;
    if (distance1 >= 500 || distance1 <= 0){
    Serial.println("Out of range");
  }
  lposition=distance1;
  if (distance1>25)
 wa=0; 
  if (distance1<25)
wa=1;
}
 void wallfollow()
 {

  
if (lposition<13)
mway2(-cspeed/b,cspeed);
else if(lposition<17&&lposition>13)
mway2(MSPEED/b,MSPEED);
else if(lposition>17)
 mway2(cspeed/b,-cspeed);
 }

