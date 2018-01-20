#include <QTRSensors.h>
#define Kp 5
#define Kd 100
#define rightMaxSpeed 150 // max speed of the robot
#define leftMaxSpeed 150 // max speed of the robot
#define rightBaseSpeed 150 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 150  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  3     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2
#define rightMotor1 12 // In 2
#define rightMotor2 13 // In 1
#define rightMotorPWM 9 //En A 
#define leftMotor1 11 // In 3
#define leftMotor2 8 // In 4
#define leftMotorPWM 10 // En B Right Motor
#define motorPower 13
#define middle_sensor 5
//-------------------for digital pid
  int middle_sensor_value=0;
  int digital_sensor_position=0; 
  int right_side = 1;
  int left_side = -1;
  int u=0;
  int total_current_position=0;
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
  signed int sensor_value[5]= {-10,-10,0,10,10};
  int digital_sens[5]={7,6,5,4,3}; // 2,13,8 left sens and 9,10,12 right sens
  int digital_sens_reading[5];

//--------------------------------------
int lastError = 0;
int rightMotorSpeed=0;
int leftMotorSpeed=0;
int middle_right_sens1=0;
int middle_middle_sens1=0;
int middle_left_sens1 = 0;
int PID_state=0;
int error=0;
int middle_right_sens =  0;
int middle_middle_sens = 0;
int middle_left_sens =   0;
int position=0;
int white=0;
int black=1;
int line;
int motorSpeed=0;
int k=0;
unsigned int sensors[3];
QTRSensorsAnalog qtra ((unsigned char[]) {0, 1, 2 } ,NUM_SENSORS, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19

unsigned int sensorValues[NUM_SENSORS];

void setup()
{
   for(int r=0;r<4;r++)
       {
          pinMode(digital_sens[r], INPUT);
       }
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  //pinMode(12, OUTPUT);
  pinMode(motorPower, OUTPUT);
  pinMode(middle_sensor,INPUT);
  digitalWrite(motorPower, HIGH); 
  int i;
           
 //---------------------------------------------
   for(int m=0; m<5; m++) //read digital sensor
        {
         digital_sens_reading[m]= digitalRead(digital_sens[m]);
        }
        
       if(digital_sens_reading[0]==1 || digital_sens_reading[4]==1)
           {
              //background_black;
              line = white;//for white line
           
           }else
              {
               // background_white;
                line =black; //for black line
              }
         //delay(1000);
 //---------------------------------------------- 
  
  
for (int i = 0; i < 100; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead

  /* comment this part out for automatic calibration 
  if ( i  < 25 || i >= 75 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
     turn_right();  
   else
     turn_left(); */ 
   qtra.calibrate();   
   delay(20);
wait();  
delay(2000); // wait for 2s to position the bot before entering the main loop 
    
    
    Serial.begin(9600);
    Serial.println("Cal Started"); 
  
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtra.calibratedMinimumOn[i]);
      Serial.print(' ');
    }
    Serial.println();

    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtra.calibratedMaximumOn[i]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
  
  } 

void loop()
{
       
             
              
                 if(line ==black) 
                     {
                       black_line_follow();
                        
                    }else if(line==white)
                        {
                           white_line_follow();
                        }
     
     
                 u=0;
                 previous_error = error_digital; 
                 integrate=0;
                 derivative=0;
                
}//end loop
  
void wait(){
    digitalWrite(motorPower, LOW);
}

void stop_motor_with_revers()
      {
                     
                       rightMotorSpeed = 80;
                       leftMotorSpeed  =80;
                       digitalWrite(rightMotor1, LOW);
                       digitalWrite(rightMotor2, HIGH);
                       analogWrite(rightMotorPWM, rightMotorSpeed);
                       digitalWrite(leftMotor1, LOW);
                       digitalWrite(leftMotor2, HIGH);
                       analogWrite(leftMotorPWM, leftMotorSpeed);
                       //delay(1);
                        rightMotorSpeed =0;
                        leftMotorSpeed  =0;

                       digitalWrite(rightMotor1, LOW);
                       digitalWrite(rightMotor2, LOW);
                       analogWrite(rightMotorPWM, rightMotorSpeed);
                       digitalWrite(leftMotor1, LOW);
                       digitalWrite(leftMotor2, LOW);
                       analogWrite(leftMotorPWM, leftMotorSpeed);
                       
                                       
      
      }

void black_line_follow()
 {  
     
     pid_calibration();
     digital_pid();
     black_line_motor_speed();
  // int f= digitalRead(middle_sensor);
     
     if( position==0 || position==2000 || total_current_position==0)
               {
                   PID_state=0;
               
               }else
                   {
                     PID_state=1;
                   }
       
                if(PID_state==1)
                    {
                        digitalWrite(rightMotor1, HIGH);
                        digitalWrite(rightMotor2, LOW);
                        analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                     }
                    else if( PID_state==0 & digital_sensor_position == left_side) //left sens
                      {
                        stop_motor_with_revers(); 
                        //delay(100);
                        rightMotorSpeed = 80;
                        leftMotorSpeed  = 80;
                        digitalWrite(rightMotor1, LOW);
                        digitalWrite(rightMotor2, HIGH);
                        analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                       // delay(100);
                
                     }else if(PID_state==0 & digital_sensor_position == right_side)//right sens
                     {
                         stop_motor_with_revers(); 
                        // delay(100);
                         rightMotorSpeed = 80;
                         leftMotorSpeed  = 80;//this is right motor
                         digitalWrite(rightMotor1, HIGH);
                         digitalWrite(rightMotor2, LOW);
                         analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, LOW);
                        digitalWrite(leftMotor2, HIGH);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                       // delay(100);
                   
                     }
       }//black line follow
void white_line_follow()
    { 
      
      pid_calibration();
      digital_pid();
      white_line_motor_speed();
       middle_sensor_value = digitalRead(middle_sensor);
     // middle_sensor_value== HIGH;
      if( middle_sensor_value== HIGH )
              {
                  PID_state=0;
               
              }else
                   {
                     PID_state=1;
                   }
       
                if(PID_state==1)
                    {
                        digitalWrite(rightMotor1, HIGH);
                        digitalWrite(rightMotor2, LOW);
                        analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                     }
                    else if(PID_state=0 & digital_sensor_position == left_side) //left sens
                      {
                        stop_motor_with_revers(); 
                        //delay(100);
                        rightMotorSpeed = 80;
                        leftMotorSpeed  = 80;
                        digitalWrite(rightMotor1, LOW);
                        digitalWrite(rightMotor2, HIGH);
                        analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                       // delay(100);
                
                     }else if(PID_state=0 & digital_sensor_position == right_side)//right sens
                     {
                         stop_motor_with_revers(); 
                        // delay(100);
                         rightMotorSpeed = 80;
                         leftMotorSpeed  = 80;
                         digitalWrite(rightMotor1, HIGH);
                         digitalWrite(rightMotor2, LOW);
                         analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, LOW);
                        digitalWrite(leftMotor2, HIGH);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                       // delay(100);
                   
                     }
             
 }//white line follow
 void black_line_motor_speed()
    {
             rightMotorSpeed = rightBaseSpeed + motorSpeed;
             leftMotorSpeed = leftBaseSpeed - motorSpeed;
              if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
              if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
              if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
             if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
          
    }//black_line_motor_speed
void white_line_motor_speed()
    {
             rightMotorSpeed = rightBaseSpeed - motorSpeed;
             leftMotorSpeed = leftBaseSpeed + motorSpeed;
              if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
              if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
              if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
             if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
          
    }//end white line motor speed    

 void pid_calibration()
     {
             sensors[3];
             position = qtra.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
            Serial.println(position);
             error = position - 1000;  //2500 for 5 Sensors
           // Serial.println(error);
             motorSpeed = Kp * error + Kd * (error - lastError);
             lastError = error; 
     } 
void digital_pid()
    {
              digital_sens_read_for_pid();
              error_digital = total_current_position;
              proportional = error_digital * kp;
              integrate = integrate + error_digital;
              integrate = integrate * ki;
              derivative = error - previous_error;
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
                      } //else // Turn right
                    //  Serial.println(digital_sensor_position);
                
                 
    
    }
void digital_sens_read_for_pid()
  {
       for(u=0;u<5;u++)
              {
                 digital_sens_reading[u] = digitalRead(digital_sens[u]);
                 if(digital_sens_reading[u]==line)  //1
                       {
                         current_position = sensor_value[u] ;
                         total_current_position +=current_position;
                       //  Serial.println(total_current_position); 
                         // u=6;
                       }
                     
              }
              //Serial.println(total_current_position); 
             if(total_current_position >=60)
                  {
                    total_current_position=60;
                  }else if(total_current_position <-60)
                        {
                          total_current_position =-60;
                        }
        // Serial.println(total_current_position);
  }//end digital_sens_read_for_pid
