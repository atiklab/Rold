void findcenter()
{
    while(1)
    {
      sensorread();
      if((sensors[0]>cr)||(sensors[1]>cr)||(sensors[2]>cr)||(sensors[3]>cr))
      break;
    }
}

