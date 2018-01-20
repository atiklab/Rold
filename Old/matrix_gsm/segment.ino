void display7()
{
  for( a=0;a<16;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(ndis[a],HIGH);
  }
  for( a=0;a<7;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(seg[a],LOW);
  }
  for( a=0;a<16;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(ndis[a],LOW);
  switch (num[a])  //switch used to specify which button
   {
            case '0':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],LOW);        
       break;  
            case '1':
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
            case '2':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[5],LOW);
       break;
            case '3':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
       break;
            case '4':
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
       break;
            case '5':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[4],LOW);
       break;
            case '6':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[1],LOW);
       break;
            case '7':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
            case '8':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
       break;
            case '9':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[4],LOW);
       break;
            case 'n':
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[5],LOW);
       break;
            case 'b':
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
       break;
            case '-':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],HIGH);
       break;
            case 'a':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],HIGH);
       break;
            case 'p':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
       break;
            case 'c':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],LOW);
       break;
           
            default:
                    ;           
      }
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(ndis[a],HIGH);
  }
}

