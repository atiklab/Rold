char amount2[]={"ful123"};



void display7cc()
{
  for( a=0;a<dig;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(ndiscc[a],LOW);
  }
  for( a=0;a<7;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(segcc[a],HIGH);
  }
  //delayMicroseconds(del);
  for( a=0;a<dig;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(ndiscc[a],HIGH);
  switch (amount2[a])  //switch used to specify which button
   {
            case '0':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],HIGH);        
       break;  
            case '1':
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],HIGH);
    digitalWrite(segcc[5],HIGH);
    digitalWrite(segcc[6],HIGH);
       break;
            case '2':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[5],HIGH);
       break;
            case '3':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[4],HIGH);
    digitalWrite(segcc[5],HIGH);
       break;
            case '4':
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],HIGH);
       break;
            case '5':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[4],HIGH);
       break;
            case '6':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[1],HIGH);
       break;
            case '7':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],HIGH);
    digitalWrite(segcc[5],HIGH);
    digitalWrite(segcc[6],HIGH);
       break;
            case '8':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
       break;
            case '9':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[4],HIGH);
       break;
            case 'n':
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[5],HIGH);
       break;
            case 'b':
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],HIGH);
       break;
            case '-':
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],HIGH);
    digitalWrite(segcc[5],HIGH);
    digitalWrite(segcc[6],LOW);
       break;
            case 'a':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
       break;
            case 'p':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
       break;
            case 'c':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],HIGH);
       break;
             case 'h':
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
       break;
        case 'f':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
       break;
        case 'e':
    digitalWrite(segcc[0],LOW);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
       break;
       case 't':
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],LOW);
       break;
       case 'u':
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],LOW);
    digitalWrite(segcc[2],LOW);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],HIGH);
       break;
       case 'l':
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],LOW);
    digitalWrite(segcc[4],LOW);
    digitalWrite(segcc[5],LOW);
    digitalWrite(segcc[6],HIGH);
       break;
            default:
                    ;           
      }
    digitalWrite(segcc[0],HIGH);
    digitalWrite(segcc[1],HIGH);
    digitalWrite(segcc[2],HIGH);
    digitalWrite(segcc[3],HIGH);
    digitalWrite(segcc[4],HIGH);
    digitalWrite(segcc[5],HIGH);
    digitalWrite(segcc[6],HIGH);
    digitalWrite(ndiscc[a],LOW);
  }
}

