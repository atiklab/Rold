
void mway2(int lspeed,int rspeed )
{
  if (lspeed==0)
  {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
  }
  else if(rspeed>0)
  {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        analogWrite(lf, 0);
        analogWrite(lb, lspeed);  
  }
  
if (rspeed==0)
  {
        analogWrite(rf, 0);
        analogWrite(rb, 0); 
  }
  else if(rspeed>0) 
  {
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);  
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);  
  }

}
