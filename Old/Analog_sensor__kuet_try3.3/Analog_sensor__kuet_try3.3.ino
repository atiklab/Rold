#define NUM_SENSORS   6
int forwards=0;
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
  int digital_sens[6]={A0,A1,A2,A3,A4,A5}; // 2,13,8 left sens and 9,10,12 right sens
  int digital_sens_reading[6];
int led =9;
int val=255;
int sensors[]={A0, A1, A2, A3, A4, A5};
int sv[NUM_SENSORS],temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];
int sv2[NUM_SENSORS]={1,1,1,1,1,1};
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ms=0,ols,ors;
int lf = 5; 
int lb = 6; 
int rf = 10; 
int rb = 11; 

int bspeed =150;
int SPEED;
int MSPEED=250;
int state=0;
int flag=0; 
int stateStop=0;
int i,j;

void setup() {
  pinMode(led, OUTPUT);
    //delay(200);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  //delay(500);
  analogWrite(led, val);
  

SPEED=70;

calibration();

  SPEED=bspeed;
}

// the loop routine runs over and over again forever:






void mway(int state)
{

if (state == 'f') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
          Serial.println("F");
    }
    else if (state == 'l') {
        analogWrite(lf, 0 );
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
         Serial.println("l");
    }
    else if (state == 'L') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
          Serial.println("L");
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
          Serial.println("r");
    }
    else if (state == 'R') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
          Serial.println("R");
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
         Serial.println("S");
          flag=1;
        }
        stateStop=0;
    }
}

int sence()
{
   sum=0;
  // read the input on analog pin 0:
  for (int i=0;i<NUM_SENSORS;i++){
    
  sv[i] = analogRead(sensors[i]);
  // print out the value you read:
  Serial.print(sv[i]);
  Serial.print('\t');
    Serial.print(sv2[i]);
  Serial.print('\t');
  if(sv[i]>threshold[i])
    sv2[i]=1;
    else
    sv2[i]=0;
  }
   
 
   for (int i=0;i<NUM_SENSORS;i++)
   sum=sum*10+sv2[i];
   ls=sv2[0]*100+sv2[1]*10;
  rs=sv2[5]*100+sv2[4]*10;
  ms=sv2[2]*10+sv2[3]*1;
//   Serial.print(sum);
//    Serial.print('\t');
//    Serial.print(ls);
//    Serial.print('\t');
//    Serial.print(rs);
//    Serial.print('\t');
//    Serial.print(ms);
   Serial.println();
  delay(1);        // delay in between reads for stability
}
void calibration()
{
  for (int i=0;i<NUM_SENSORS;i++)
{
    maxv[i] = analogRead(sensors[i]);
    minv[i] = analogRead(sensors[i]);
}

mway('R');   
 for (int j=0;j<100;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(3); 
 }
  
mway('s');  
delay(50);
mway('L');    
 for (int j=0;j<200;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(3); 
 }
 mway('s');  
delay(50);  
mway('R');
 for (int j=0;j<100;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    temp[i] = analogRead(sensors[i]);
    if(temp[i]>maxv[i])
    maxv[i]=temp[i];
    if(temp[i]<minv[i])
    minv[i]=temp[i];
  }
  delay(3); 
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


void follow(){
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
 mway('f');
else if ((sum==1000)||(sum==1100)||(sum==100)) 
{
 mway('s');
 }
 else if ((sum==111000)||(sum==110000)) 
{
 
    mway('R');
    
  

  
 }
  else if ((sum==000111)||(sum==000011)) 
{
 
    mway('L');
    

 
  
 }
else if((ls==rs))
{
 if(sum!=111111)
 mway('f');
}
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
{
  ls=ols;
  rs=ors;
 /* if(ols>ors)
  mway('L');
  else
  mway('R');*/   
}


/* if(ls!=rs)
 {
   
if(ts!=sum)
    ts=sum;
if(ols!=ls)
    ols=ls;
if(ors!=rs)
    ors=rs;
  }*/

}

void loop() {
 
sence();
//mway('R');
//follow();
     for(u=0;u<6;u++)
              {
                 
                 if(sv2[u] == 0)  //1 >200== Black
                       {
                        
                          current_position = sensor_value[u] ;
                         
                        //  u=6;
                          // Serial.println(current_position); 
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
                 // Serial.println(error_correction);

                //--------------------------------------------


                if(digital_sensor_position == right_side)
                {
                    //left turn
                                 
                      mway('l');              
                  
                  }else if(digital_sensor_position == left_side)
                     {
                      //right  turn 
                      
                         mway('r');         
                      
                      }else if(digital_sensor_position == forwards)
                          {
                            
                                 mway('f'); 
                            
                            }


                            previous_error =error_digital;

}

