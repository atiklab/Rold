void findcenter()
{
    while(1)
    {
      sensorread();
      if(position==1500)
      break;
      else if(position>1500)
      mway('R');
      else if(position<1500)
      mway('L');
    }
     mway('s');
}

