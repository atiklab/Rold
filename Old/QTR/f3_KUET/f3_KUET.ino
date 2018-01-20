#include <QTRSensors.h>
#define NUM_SENSORS   6     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go 0
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A0, A1, 7,8, A4, A5},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sv[NUM_SENSORS];
int sv2[NUM_SENSORS]={1,1,1,1,1,1};
unsigned long int sum=0,ts=0,ps=0;
int lf = 5; 
int lb = 6; 
int rf = 10; 
int rb = 11; 
int led = 13;
int bspeed =70;
int SPEED;
int MSPEED=200;
int state=0;
int flag=0; 
int stateStop=0;

void setup()
{
  delay(500);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600); // set the data rate in bits per second for serial data transmission
  delay(1000);
  SPEED=bspeed;
  
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
   
    
   if(sv[i]>350)
    sv2[i]=1;
    else
    sv2[i]=0;
    Serial.print(sv[i]);
    Serial.print('\t');
   sum=sum*10+sv2[i];
    //Serial.print(sv2[i]);
    //Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
    Serial.print(sum);
   // Serial.print('\t');
    //Serial.print(ts);
  Serial.println();

  
drive:
  if(sum==ts)
  {
    if(SPEED<MSPEED)
    SPEED=SPEED+1;
    else
    SPEED=MSPEED;
  }
  else
  SPEED=bspeed;

if ((sum==0)|| (sum==110011))
 mway('f');
else if ((sum==000011)|| (sum==000111)|| (sum==001111)|| (sum==011111)|| (sum==100011)|| (sum==100111)|| (sum==101111))
 mway('l');
else if ((sum==110000)|| (sum==111000)|| (sum==111100)|| (sum==111110)|| (sum==110001)|| (sum==111001)|| (sum==111101))
  mway('r');
else if((sum==111111)||(sum==100001))
{sum=ts;
goto drive;
}
if(ts!=sum)
   ts=sum;
  
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

