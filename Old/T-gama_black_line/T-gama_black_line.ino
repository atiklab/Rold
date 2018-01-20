int el=4;
int lf = 5; 
int lb = 6; 
int er=9;
int rf = 10; 
int rb = 11; 
 #define NUM_SENSORS 6
 int i;
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
  int digital_sens[6]={A0,A2,A1,A3,A4,A5}; // 2,13,8 left sens and 9,10,12 right sens
  int digital_sens_reading[6];
 int temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];

int bspeed =130;
int SPEED;
int MSPEED=250;
int state=0;
int flag=0; 
int stateStop=0;



void setup() {

Serial.begin(115200);
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  digitalWrite(el, HIGH);
  digitalWrite(er, HIGH);
SPEED=150;
 analogWrite(el, SPEED);
  analogWrite(er, SPEED);
calibration();
    SPEED=bspeed;

}

void loop() {


       for(u=0;u<6;u++)
              {
                 digital_sens_reading[u] = analogRead(digital_sens[u]);
                 if(digital_sens_reading[u] >threshold[u] )  //1 >200== Black
                       {
                        
                          current_position = sensor_value[u] ;
                         
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
                    //SPEED=bspeed;
                    SPEED=MSPEED;
                     analogWrite(el, SPEED);
                      analogWrite(er, SPEED);
                    mway('R'); 
                                    
                  
                  }else if(digital_sensor_position == left_side)
                     {
                      //right  turn 
                                  //SPEED=bspeed;
                                  SPEED=MSPEED;
                                  analogWrite(el, SPEED);
                                  analogWrite(er, SPEED);
                                  mway('L'); 
                      
                      
                      }else if(digital_sensor_position == forwards)
                          {
                            if(SPEED<MSPEED)
                            SPEED=SPEED+20;
                            analogWrite(el, SPEED);
                            analogWrite(er, SPEED);
                             mway('f'); 
                            
                            }


                            previous_error =error_digital;
//                            delay(4); 
//                            mway('s');
//                            delay(1); 
 


}
void calibration()
{
  for (int i=0;i<NUM_SENSORS;i++)
{
    maxv[i] = analogRead(digital_sens[i]);
    minv[i] = analogRead(digital_sens[i]);
}

mway('R');   
 for (int j=0;j<100;j++)
 {
  for (int i=0;i<NUM_SENSORS;i++)
  {
    temp[i] = analogRead(digital_sens[i]);
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
    temp[i] = analogRead(digital_sens[i]);
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
    temp[i] = analogRead(digital_sens[i]);
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
void mway(int state)
{

if (state == 'f') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("Go Forward!");
    }
    else if (state == 'l') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("SL");
    }
    else if (state == 'L') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("HL");
    }
        else if (state == 'm') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
          Serial.println("BL");
     }
    else if (state == 'b') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("BACK");
    }
    else if (state == 'r') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
          Serial.println("SR");
    }
    else if (state == 'R') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("HR");
    }
    else if (state == 'q') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("BR");
    }

    else if (state == 's') {
        digitalWrite(lf, LOW); 
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
     
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
}
