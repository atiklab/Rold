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
