 void rfinder()
 {
  while(1)
  {
    sensorread();
    if ((position!=0)&&(position!=3000))
    
      
      return;
      mway2(-250,250);
  }
 }

  void lfinder()
 {
  while(1)
  {
    sensorread();
    if ((position!=0)&&(position!=3000))
    
      
      return;
      mway2(250,-250);
  }
 }
 
