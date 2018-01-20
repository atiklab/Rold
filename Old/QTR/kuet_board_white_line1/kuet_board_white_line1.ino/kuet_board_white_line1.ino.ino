#include <QTRSensors.h>
#define NUM_SENSORS   6     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go 0
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A0, A1, A2, A3, A4, A5},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sv[NUM_SENSORS],temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];
int sv2[NUM_SENSORS]={1,1,1,1,1,1};
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ols,ors;
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
int led = 13;
int bspeed =70;
int SPEED;
int MSPEED=90;
int state=0;
int flag=0; 
int stateStop=0;
int i,j;
void setup()
{
  delay(500);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200); // set the data rate in bits per second for serial data transmission
  delay(500);
  SPEED=bspeed;
  calibration();
  
}


void loop()
{
  
  // read raw sensor values
  qtrrc.read(sv);
sum=0;
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (int i = 0; i < NUM_SENSORS; i++)
  {
   
    
   if(sv[i]<1050)
    sv2[i]=1;
    else
    sv2[i]=0;
    Serial.print(sv[i]);
    Serial.print('\t');
   sum=sum*10+sv2[i];
    //Serial.print(sv2[i]);
    //Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
  ls=sv2[0]*10+sv2[1];
  rs=sv2[5]*10+sv2[4];
    Serial.print(sum);
    Serial.print('\t');
    Serial.print(ls);
    Serial.print('\t');
    Serial.print(rs);
   // Serial.print('\t');
    //Serial.print(ts);
  Serial.println();

  
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
 {
  if((ls-rs)<99)
  mway('r');
  else
  mway('R');
  ols=ls;
  ors=rs;
 }
 
 else if(ls<rs)
 {
 if((rs-ls)<99)
 mway('l');
 else
 mway('L');
  ols=ls;
  ors=rs;
 }
  



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
void calibration()
{
  for (int i=0;i<NUM_SENSORS;i++)
{
  qtrrc.read(maxv);
  qtrrc.read(minv);
    //maxv[i] = analogRead(sensors[i]);
   // minv[i] = analogRead(sensors[i]);
}

mway('R');   
 for (int j=0;j<25;j++)
 {
  qtrrc.read(temp);
  for (int i=0;i<NUM_SENSORS;i++)
  {
    //temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(1); 
 }
  

mway('L');    
 for (int j=0;j<50;j++)
 {
  qtrrc.read(temp);
  for (int i=0;i<NUM_SENSORS;i++)
  {
    //temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(1); 
 }  
mway('R');
 for (int j=0;j<25;j++)
 {
  qtrrc.read(temp);
  for (int i=0;i<NUM_SENSORS;i++)
  {
    //temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(1); 
 }    
delay(1); 
for(i=0;i<NUM_SENSORS;i++)
{
threshold[i]= minv[i] + (maxv[i]-minv[i])/2;
Serial.print(threshold[i]);
  Serial.print('\t');
}
        mway('s');

}

