
void mway2(int lspeed,int rspeed )
{
  if (rspeed==0)
  {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
  }
  else if(rspeed>0)
  {
        analogWrite(lf, rspeed);
        analogWrite(lb, 0);  
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        analogWrite(lf, 0);
        analogWrite(lb, rspeed);  
  }
if (lspeed==0)
  {
        analogWrite(rf, 0);
        analogWrite(rb, 0); 
  }
  else if(lspeed>0) 
  {
        analogWrite(rf, lspeed);
        analogWrite(rb, 0);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        analogWrite(rf, 0);
        analogWrite(rb, lspeed);  
  }

}
