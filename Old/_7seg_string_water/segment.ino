char num[]={"ful"};
char ept[]={"ept"};
char one[]={"001"};
char two[]={"002"};
char haf[]={"haf"};
char four[]={"004"};
char ful[]={"ful"};
void collect()
{
  if (digitalRead(level[4])==HIGH)
  {
     for(int b=0;b<3;b++)
            {
              num[b]=ful[b];
            }

    digitalWrite(motor, LOW);    
  }
   else if (digitalRead(level[3])==HIGH)
  {
   for(int b=0;b<3;b++)
            {
              num[b]=four[b];
            }
  }
   else if (digitalRead(level[2])==HIGH)
  {
    for(int b=0;b<3;b++)
            {
              num[b]=haf[b];
            }
  }
   else if (digitalRead(level[1])==HIGH)
  {
    for(int b=0;b<3;b++)
            {
              num[b]=two[b];
            }
  }
 else if (digitalRead(level[0])==HIGH)
  {
    for(int b=0;b<3;b++)
            {
              num[b]=one[b];
            }
  }
   else 
  {
   for(int b=0;b<3;b++)
            {
              num[b]=ept[b];
            }
    digitalWrite(motor, HIGH);    
  }
}

void display7()
{
  for( a=0;a<3;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(ndis[a],LOW);
  }
  for( a=0;a<7;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(seg[a],HIGH);
  }
  //delayMicroseconds(del);
  for( a=0;a<3;a++)  //for loop used to make pin mode of outputs as output
  {
  digitalWrite(ndis[a],HIGH);
  switch (num[a])  //switch used to specify which button
   {
            case '0':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],HIGH);        
       break;  
            case '1':
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
       break;
            case '2':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[5],HIGH);
       break;
            case '3':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
       break;
            case '4':
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
       break;
            case '5':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[4],HIGH);
       break;
            case '6':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[1],HIGH);
       break;
            case '7':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
       break;
            case '8':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
            case '9':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[4],HIGH);
       break;
            case 'n':
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[5],HIGH);
       break;
            case 'b':
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
       break;
            case '-':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],LOW);
       break;
            case 'a':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
            case 'p':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
            case 'c':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],HIGH);
       break;
             case 'h':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
        case 'f':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
        case 'e':
    digitalWrite(seg[0],LOW);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
       case 't':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],LOW);
       break;
       case 'u':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],LOW);
    digitalWrite(seg[2],LOW);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],HIGH);
       break;
       case 'l':
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],LOW);
    digitalWrite(seg[4],LOW);
    digitalWrite(seg[5],LOW);
    digitalWrite(seg[6],HIGH);
       break;
            default:
                    ;           
      }
    digitalWrite(seg[0],HIGH);
    digitalWrite(seg[1],HIGH);
    digitalWrite(seg[2],HIGH);
    digitalWrite(seg[3],HIGH);
    digitalWrite(seg[4],HIGH);
    digitalWrite(seg[5],HIGH);
    digitalWrite(seg[6],HIGH);
    digitalWrite(ndis[a],LOW);
  }
}

