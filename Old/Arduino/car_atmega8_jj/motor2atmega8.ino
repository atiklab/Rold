void mway3(int lspeed,int rspeed )
{
  
  if (lspeed==0)
  {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW); 
  }
  else if(lspeed>0)
  {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(A0, HIGH);
        digitalWrite(A1, LOW);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH);
        digitalWrite(A0, LOW);
        digitalWrite(A1, HIGH);  
  }
if (rspeed==0)
  {
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW); 
  }
  else if(rspeed>0) 
  {
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);  
        digitalWrite(A2, HIGH);
        digitalWrite(A3, LOW); 
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH); 
        digitalWrite(A2, LOW);
        digitalWrite(A3, HIGH); 
  }
 analogWrite(el, lspeed);
 analogWrite(er, rspeed);
}
