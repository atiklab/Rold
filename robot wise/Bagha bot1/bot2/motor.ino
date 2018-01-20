void mrun(int y, int x)
{
  int motorSpeedLeft = x + y;
  int motorSpeedRight = x - y;

if (motorSpeedLeft>254)
  motorSpeedLeft=254;
if (motorSpeedLeft<-254)
  motorSpeedLeft=-254;
if (motorSpeedRight>254)
  motorSpeedRight=254;
if (motorSpeedRight<-254)
  motorSpeedRight=-254;
  Serial.print("\t"); 
  Serial.print("y=");
  Serial.print(y); 
  Serial.print("\t"); 
  Serial.print("x=");
  Serial.print(x); 
  
  Serial.print("\t"); 
  Serial.print("L=");
  Serial.print(motorSpeedLeft);  
  Serial.print("\t"); 
  Serial.print("R="); 
  Serial.println(motorSpeedRight); 

  mway3(motorSpeedLeft,motorSpeedRight);
}
void mway3(int lspeed,int rspeed )
{
  if (lspeed==0)
  {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
  }
  else if(lspeed>0)
  {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH);  
  }
if (rspeed==0)
  {
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW); 
  }
  else if(rspeed>0) 
  {
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);  
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);  
  }
 analogWrite(el, lspeed);
 analogWrite(er, rspeed);

}

