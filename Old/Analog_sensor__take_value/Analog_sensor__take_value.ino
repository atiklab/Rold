#define NUM_SENSORS   6
int led =9;
int val=255;
int sensors[]={A0, A1, A2, A4, A3, A5};
unsigned int sv[NUM_SENSORS];
int sv2[NUM_SENSORS]={1,1,1,1,1,1};
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ols,ors;
int lf = 5; 
int lb = 6; 
int rf = 10; 
int rb = 11; 

int bspeed =70;
int SPEED;
int MSPEED=70;
int state=0;
int flag=0; 
int stateStop=0;
void setup() {
  pinMode(led, OUTPUT);
    delay(500);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  delay(500);
  analogWrite(led, val);
  SPEED=bspeed;
}

// the loop routine runs over and over again forever:
void loop() {
  sum=0;
  // read the input on analog pin 0:
  for (int i=0;i<6;i++){
    
  sv[i] = analogRead(sensors[i]);
  // print out the value you read:
  Serial.print(sv[i]);
  Serial.print('\t');
  if(sv[i]>29)
    sv2[i]=1;
    else
    sv2[i]=0;
  }
   
  /* if(sv[0]>200)
   sv2[0]=0;
   else
   sv2[0]=1;
   if(sv[1]>600)
   sv2[1]=0;
   else
   sv2[1]=1;
   if(sv[2]>400)
   sv2[2]=0;
   else
   sv2[2]=1;
  if(sv[3]>500)
   sv2[3]=0;
   else
   sv2[3]=1;
   if(sv[4]>500)
   sv2[4]=0;
   else
   sv2[4]=1;
   if(sv[5]>200)
   sv2[5]=0;
   else
   sv2[5]=1;*/
   for (int i=0;i<6;i++)
   sum=sum*10+sv2[i];
   ls=sv2[0]*100+sv2[1]*10+sv2[2];
  rs=sv2[5]*100+sv2[4]*10+sv2[3];
   Serial.print(sum);
    Serial.print('\t');
    Serial.print(ls);
    Serial.print('\t');
    Serial.print(rs);
   Serial.println();
  delay(1);        // delay in between reads for stability


  drive:
  if(sum==ts)
  {
    if(SPEED<MSPEED)
    SPEED=SPEED+20;
    else
    SPEED=MSPEED;
  }
  else
  SPEED=bspeed;
 if (sum==0) 
 mway('s');

else if(ls==rs)
 mway('f');
 else if(ls>rs)
 mway('r');
 else if(ls<rs)
 mway('l');
  


else if((sum==111111))
{sum=ts;
rs=ors;
ols=ls;
goto drive;
}

 if(ls!=rs)
 {
   
if(ts!=sum)
    ts=sum;
if(ols!=ls)
    ols=ls;
if(ors!=rs)
    ors=rs;
    }
}




void mway(int state)
{

if (state == 'f') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
         // Serial.println("Go Forward!");
    }
    else if (state == 'l') {
        analogWrite(lf, 0 );
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
         // Serial.println("SL");
    }
    else if (state == 'L') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
         // Serial.println("HL");
    }
        else if (state == 'm') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        //  Serial.println("BL");
     }
    else if (state == 'b') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
        //  Serial.println("BACK");
    }
    else if (state == 'r') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        //  Serial.println("SR");
    }
    else if (state == 'R') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
          Serial.println("HR");
    }
    else if (state == 'q') {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
       //   Serial.println("BR");
    }

    else if (state == 's') {
        analogWrite(lf, 0); 
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        analogWrite(led, 0);
        if(flag == 0){
        //  Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
}

