#include <QTRSensors.h>
#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go 0
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A0, A1, A2, A3, A4, A5,A6,A7},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sv[NUM_SENSORS];
int sv2[NUM_SENSORS]={1,1,1,1,1,1,1,1};
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ols,ors;
int valuet=1000;
unsigned int temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS]={valuet,valuet,valuet,valuet,valuet,valuet,valuet,valuet};
int i;
int celnum=10,celdelay=0;




void readSensors(){
  
  qtrrc.read(sv);
  position = qtrrc.readLine(sv); 
sum=0;
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (int i = 0; i < NUM_SENSORS; i++)
  {
   
    
   if(sv[i]>threshold[i])
    sv2[i]=0;
    else
    sv2[i]=1;
   Serial.print(sv[i]);
   Serial.print('\t');
   sum=sum*10+sv2[i];
   // Serial.print(sv2[i]);
   // Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }

    Serial.print(sum);
   Serial.print('\t');
    //Serial.print(ts);
    Serial.println(position);
  Serial.println();
  

}


void calibration()
{
  for (int i=0;i<NUM_SENSORS;i++)
{
   qtrrc.read(maxv);
    qtrrc.read(minv);
    //maxv[i] = analogRead(digital_sens[i]);
    //minv[i] = analogRead(digital_sens[i]);
}

mway('R');   
 for (int j=0;j<celnum;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    qtrrc.read(temp);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(celdelay); 
 }
  
mway('s');  
delay(50);
mway('L');    
 for (int j=0;j<2*celnum;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    qtrrc.read(temp);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(celdelay); 
 }
 mway('s');  
delay(50);  
mway('R');
 for (int j=0;j<celnum;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
   qtrrc.read(temp);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(celdelay); 
 }  
mway('s');  
delay(50); 
for(i=0;i<NUM_SENSORS;i++)
{
threshold[i]= minv[i] + (maxv[i]-minv[i])/2;
Serial.print(threshold[i]);
  Serial.print('\t');
}

}

