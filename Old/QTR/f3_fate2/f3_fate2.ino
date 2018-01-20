#include <QTRSensors.h>
#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go 0
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A0, A1, A2, A3, A4, A5, A6, A7},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sv[NUM_SENSORS];
int sv2[NUM_SENSORS]={1,1,1,1,1,1,1,1};
unsigned long int sum=0,ts=0,ps=0;
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
int led = 13;
int bspeed =70;
int SPEED;
int MSPEED=150;
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
   
    
   if(sv[i]>1500)
    sv2[i]=0;
    else
    sv2[i]=1;
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
    SPEED=SPEED+20;
    else
    SPEED=MSPEED;
  }
  else
  SPEED=bspeed;
 if (sum==0) 
 mway('s');
 else if((sum==11100111)||(sum==11110111)||(sum==11101111))
   mway('f');
  else if((sum==11000111)||(sum==11001111)||(sum==10011111)||(sum==11011111)||(sum==10111111)||(sum==1111111)||(sum==111111)||(sum==11111)||(sum==10001111))
   mway('l');
   else if((sum==11111011)||(sum==11111101)||(sum==11111110)||(sum==11110011)||(sum==11111001)||(sum==11111100)||(sum==11100011)||(sum==11110001)||(sum==11111000))
   mway('r');
  /* else if((sum==10000111)||(sum==10000011))
mway('R');
else if((sum==11100001)||(sum==11000001))
mway('L');*/
  else 
   mway('s');

   

   if((sum==11)||(sum==111)||(sum==1111)||(sum==11111))
   {
   
    mway('L');
   }

   if((sum==11000000)||(sum==11100000)||(sum==11110000)||(sum==11111000))
   {
   
    mway('R');
   }
/*if((sum==11111111))
 {    
  if((ts==11100111)||(ts==11110111)||(ts==11101111)||(ts==11111111))
 mway('R');
 

 }
else
  mway('f');*/
    else if((sum==10000011)||(sum==10000111))
   {
   
    mway('L');
   }

   else if((sum==11000001)||(sum==11100001))
   {
   
    mway('R');
   }

else if((sum==11000011)||(sum==10000001)||(sum==11111111))
{sum=ts;
goto drive;
}
//if((sum==11100001)||(sum==11000001)||(sum==10000111)||(sum==10000011))
//else
//{sum=ts;
//goto drive;
//}
   
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

