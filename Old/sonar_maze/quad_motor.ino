void mway2(int lspeed,int rspeed )
{
  if (lspeed==0)
  {
        analogWrite(lf, 0);
        analogWrite(lb, 0);
        analogWrite(lf1, 0);
        analogWrite(lb1, 0); 
  }
  else if(lspeed>0)
  {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0);
        analogWrite(lf1, lspeed);
        analogWrite(lb1, 0);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        analogWrite(lf, 0);
        analogWrite(lb, lspeed);
        analogWrite(lf1, 0);
        analogWrite(lb1, lspeed);  
  }
if (rspeed==0)
  {
        analogWrite(rf, 0);
        analogWrite(rb, 0); 
        analogWrite(rf1, 0);
        analogWrite(rb1, 0);
  }
  else if(rspeed>0) 
  {
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);
        analogWrite(rf1, rspeed);
        analogWrite(rb1, 0);  
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        analogWrite(rf, 0);
        analogWrite(rb, rspeed); 
        analogWrite(rf1, 0);
        analogWrite(rb1, rspeed);  
  }

}
