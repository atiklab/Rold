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
unsigned int temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];
int i;
int celnum=10,celdelay=0;
 int forwards=0;
 int leftNudge;
int replaystage;
int rightNudge;

int digital_sensor_position=0; 
  int right_side = 1;
  int left_side = -1;
  int u=0;
  signed int error_digital=0;
  signed int target_position =5;
  signed int current_position;
  signed int proportional =0;
  signed int integrate =0;
  signed int derivative =0;
  signed int previous_error;
  signed int error_correction=0;
  signed int kp=200;//15
  signed int ki=2;
  signed int kd=5;
  signed int sensor_value[6]= {-10,-10,0,0,10,10};


#define leapTime 200
char path[30] = {};
int pathLength;
int readLength;
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
int led = 13;
int bspeed =100;
int SPEED=150;
int MSPEED=200;
int state=0;
int flag=0; 
int stateStop=0;

void setup()
{
  //delay(200);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600); // set the data rate in bits per second for serial data transmission
  //delay(1000);
  SPEED=bspeed;
 // calibration();
  
}


void loop()
{
  readSensors();
 drive:


  for(u=1;u<=6;u++)
              {
               // qtrrc.read(sv);
                 //digital_sens_reading[u] = analogRead(digital_sens[u]);
                // if(digital_sens_reading[u] >threshold[u] )  //1 >200== Black
                if(sv2[u] ==0 )
                       {
                        
                          current_position = sensor_value[u-1] ;
                         
                        //  u=6;
                          // Serial.println(digital_sens_reading[u]); 
                       }
                  
                        //..................for indicating 
                       
    
                             
                          //---------------------------------
              }//end for loop

              //---------------------
     
              error_digital =  current_position;
              proportional = error_digital * kp;
              integrate = integrate + error_digital;
              integrate = integrate * ki;
              derivative = error_digital - previous_error;
              error_correction = proportional + integrate + derivative ; 
              
              if( error_correction > 60 ) { error_correction = 60; }
              if( error_correction <-60 ) { error_correction = -60; }
              // Serial.println(current_position); 
                if(error_correction > 0)//go straight
                    
                     {
                        digital_sensor_position = right_side;
                    
                   }else if(error_correction <0) // Turn left
                      {
                        digital_sensor_position = left_side;
                      }else if(error_correction ==0 )
                         {
                            
                           digital_sensor_position = forwards;
                          
                          }//else // Turn right
                  Serial.println(error_correction);

                //--------------------------------------------


                if(digital_sensor_position == right_side)
                {
                
                    //left turn
                    SPEED=bspeed;
                    //SPEED=70;
                    mway('R'); 
                                    
                  
                  }else if(digital_sensor_position == left_side)
                     {
                      //right  turn 
                                  SPEED=bspeed;
                                 // SPEED=70;
                                  mway('L'); 
                      
                      
                      }else if(digital_sensor_position == forwards)
                          {
                            //if(SPEED<MSPEED)
                            //SPEED=70;
                            SPEED=MSPEED;
                             mway('f'); 
                            
                            }


                            previous_error =error_digital;
   //delay(3);


}
void readSensors(){
  
  qtrrc.read(sv);
sum=0;
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (int i = 0; i < NUM_SENSORS; i++)
  {
   
    
   if(sv[i]<850)
    sv2[i]=1;
    else
    sv2[i]=0;
   Serial.print(sv[i]);
   Serial.print('\t');
   sum=sum*10+sv2[i];
   // Serial.print(sv2[i]);
   // Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }

    Serial.print(sum);
   // Serial.print('\t');
    //Serial.print(ts);
  Serial.println();
  

}

void mway(int state)
{

if (state == 'f') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
          Serial.println("Go Forward!");
    }
    else if (state == 'l') {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
          Serial.println("SL");
    }
    else if (state == 'L') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
          Serial.println("HL");
    }
        else if (state == 'm') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
          Serial.println("BL");
     }
    else if (state == 'b') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
          Serial.println("BACK");
    }
    else if (state == 'r') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
          Serial.println("SR");
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
          Serial.println("BR");
    }

    else if (state == 's') {
        analogWrite(lf, 0); 
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        analogWrite(led, 0);
        if(flag == 0){
          Serial.println("STOP!");
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
//void endMotion(){
//    digitalWrite(led, LOW);
//    delay(500);
//    digitalWrite(led, HIGH);
//    delay(200);
//      digitalWrite(led, LOW);
//    delay(200);
//    digitalWrite(led, HIGH);
//    delay(500);
//  endMotion();
//}
//
//void replay(){
//   readSensors();
//  if(sv2[0]==1 && sv2[7]==1){
//    straight();
//  }
//  else{
//    if(path[readLength]=='D'){
//mway('f'); 
//    delay(100);
//mway('s'); 
//      endMotion();
//    }
//    if(path[readLength]=='L'){
//mway('L'); 
//    delay(leapTime);
//      turnLeft();
//    }
//    if(path[readLength]=='R'){
//mway('R'); 
//    delay(leapTime);
//    turnRight();
//    }
//    if(path[readLength]=='S'){
//mway('f'); 
//    delay(leapTime);
//    straight();
//    }
//    
//    readLength++;
//  }
//     
//  replay();
//  
//}

