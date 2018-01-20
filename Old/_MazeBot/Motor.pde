void HLHL()  //straight
{
  analogWrite(leftMotor1, 250);
  digitalWrite(leftMotor2, LOW);
  analogWrite(rightMotor1, 250);
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
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void LHHL() //Swapped
{
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}
