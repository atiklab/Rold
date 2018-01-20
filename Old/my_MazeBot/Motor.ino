void HLHL()  //straight
{
  analogWrite(leftMotor1, speeda);
  digitalWrite(leftMotor2, LOW);
  analogWrite(rightMotor1, speeda);
  digitalWrite(rightMotor2, LOW);
}

void LLLL()  //stop
{
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void HLLH()  //Swapped
{
  digitalWrite(leftMotor1, LOW);
  analogWrite(leftMotor2, speeda);
  analogWrite(rightMotor1, speeda);
  digitalWrite(rightMotor2, LOW);
}

void LHHL() //Swapped
{
  analogWrite(leftMotor1, speeda);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
 analogWrite(rightMotor2, speeda);
}
