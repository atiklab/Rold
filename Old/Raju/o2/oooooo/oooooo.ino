#include <QTRSensors.h>
#define Kp 5
#define Kd 300
#define NUM_SENSORS  3     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2
#define rightMotor1 7 // In 2
#define rightMotor2 6 // In 1
#define rightMotorPWM 11 //En A 
#define leftMotor1 5 // In 3
#define leftMotor2 4 // In 4
#define leftMotorPWM 3 // En B Right Motor
//#define motorPower 13

//-----------------for sonar
int q=0;
int trigPin = A3;
int echoPin = A4;
int sonar_max_pwm_right =255;
int sonar_max_pwm_left = 255;
long sonar_error =0;
long target_cm =15;
long current_cm=0;
long sonar_proportional = 0;//for sonar 
long sonar_kp=10;
long sonar_integrate = 0;
long sonar_ki=1;
long sonar_derivative=1;
long sonar_previous_error =0;
long sonar_error_correction =0;
int sonar_pwm_right=0;
int sonar_pwm_left=0;  
long duration, cm;
//-------------------------------
  

//-------------------for digital pid

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
  signed int sensor_value[6]= {-10,-10,-10,10,10,10};
  int digital_sens[6]={2,13,8,9,10,12}; // 2,13,8 left sens and 9,10,12 right sens
  int digital_sens_reading[6];

//--------------------------------------
int rightMaxSpeed= 150; // max speed of the robot//155
int leftMaxSpeed =150; // max speed of the robot
int rightBaseSpeed=150; // this is the speed at which the motors should spin when the robot is perfectly on the line
int leftBaseSpeed =150; // this is the speed at which the motors should spin when the robot is perfectly on the line
int indicator[9]={30,31,32,33,34,35,36,37,38};
float gear=0;
int max_gear=100;//100
int lastError = 0;
int rightMotorSpeed=0;
int leftMotorSpeed=0;
int rightMotor_gear_Speed =0;
int leftMotor_gear_Speed =0;
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
int stop_method=0;
unsigned int sensors[3];
QTRSensorsAnalog qtra ((unsigned char[]) {0, 1, 2 } ,NUM_SENSORS, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19

unsigned int sensorValues[NUM_SENSORS];

void setup()
{
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
  
   for(int p=0;p<9;p++)
       {
          pinMode(indicator[p], OUTPUT);
       }
  
   for(int r=0;r<6;r++)
       {
          pinMode(digital_sens[r], INPUT);
       }
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
 // pinMode(12, OUTPUT);
 // pinMode(motorPower, OUTPUT);
  //digitalWrite(motorPower, HIGH); 
  int i;
 
           
 //---------------------------------------------
   for(int m=0; m<6; m++) //read digital sensor
        {
         digital_sens_reading[m]= digitalRead(digital_sens[m]);
        }
        
       if(digital_sens_reading[0]==1 || digital_sens_reading[5]==1)
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
 {
      // comment this part out for automatic calibration 
      if ( i  < 25 || i >= 75 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
         {
            turn_right();
         }  
       else
         {
           turn_left(); // */ 
         }
       qtra.calibrate();   
       delay(20);
 }//end if
//wait();  
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
//---------for stop 
          if(line ==black)
                {
                  black_pid_calibration();
                   if(sensors[1] < 200)
                       {
                         stop_method=1; 
                       }else
                         {
                            stop_method=0;
                         }
                  
                }else
                  {
                    white_line_pid_calibration();
                    if(sensors[1] > 200)
                       {
                         stop_method=2; 
                       }else
                         {
                            stop_method=0;
                         }
                    
                     
                  }
 //---------------------------------------------------         
          digital_sens_read_for_pid();
          if(digital_sens_reading[1]==line && digital_sens_reading[2]==line && (stop_method==1 || stop_method==2) && digital_sens_reading[3]==line && digital_sens_reading[4]==line)
                     {
                        for(q=0;q <= 4; q++)                              //----------------------------------//
                            {  
                              motor_full_stop();
                              delay(500);
                            }  
                    }   
             
           
//----------------------------------------
           sonar_read();
             if(line ==black)
                {
                  black_pid_calibration();
                }else
                  {
                    white_line_pid_calibration();
                  }
            if(current_cm >20)
                 {
                   
                     if(line ==black) 
                     
                                {
                                  black_line_follow();
                              
                                }else if(line==white)
                                    {
                                      white_line_follow();
                                    }
                        sonar_pwm_left = 0;
                        sonar_pwm_right = 0;               
                      
                 } else if(current_cm >0 && current_cm <20 && PID_state==0)
                    {
                       
                          follow_line_with_sonar();
                          
                          rightMotor_gear_Speed=0;
                          leftMotor_gear_Speed=0;
                          rightMotorSpeed = 0;
                          leftMotorSpeed  = 0;
                             
                    
                    }//end else if
     
//---------------------------------------
//                 if(line ==black) 
//                     {
//                       black_line_follow();
//                        
//                    }else if(line==white)
//                        {
//                           white_line_follow();
//                        }
     
                sonar_previous_error=sonar_error;
                 sonar_proportional=0;
                 sonar_integrate=0;
                 sonar_derivative=0;
                 //-------------------
                 u=0;
                 previous_error = error_digital; 
                 integrate=0;
                 derivative=0;
}//end loop
  


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
                       // rightMotorSpeed =0;
                       // leftMotorSpeed  =0;

                       digitalWrite(rightMotor1, LOW);
                       digitalWrite(rightMotor2, LOW);
                       analogWrite(rightMotorPWM, rightMotorSpeed);
                       digitalWrite(leftMotor1, LOW);
                       digitalWrite(leftMotor2, LOW);
                       analogWrite(leftMotorPWM, leftMotorSpeed);
                       
                                       
      
      }

void black_line_follow()
 {  
     
     black_pid_calibration();
     digital_pid();
     black_line_motor_speed();
    
       
                if(PID_state==1)
                    {
                       // speed_up();
                       // rightMotorSpeed = rightMotorSpeed + 10 ;
                       // leftMotorSpeed  = leftMotorSpeed + 10 ;
                        digitalWrite(rightMotor1, HIGH);
                        digitalWrite(rightMotor2, LOW);
                        analogWrite(rightMotorPWM, rightMotor_gear_Speed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM,leftMotor_gear_Speed );
                       // u=0;
                        
                   }
                    else if( PID_state==0 & digital_sensor_position == left_side) //left sens
                      {
                        stop_motor_with_revers(); 
                       // delay(1);
                        //left_turn_indicating();                        
                        rightMotorSpeed = 80;
                        leftMotorSpeed  = 80;
                        digitalWrite(rightMotor1, LOW);
                        digitalWrite(rightMotor2, HIGH);
                        analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                        //delay(100);
                        //stop_motor_with_revers();
                       // delay(100);
                        //u=0;
                        gear=0;
                     }else if(PID_state==0 & digital_sensor_position == right_side)//right sens
                     {
                         stop_motor_with_revers(); 
                        // delay(1);
                        // right_turn_indicating();
                         rightMotorSpeed = 80;
                         leftMotorSpeed  = 80;//this is right motor
                         digitalWrite(rightMotor1, HIGH);
                         digitalWrite(rightMotor2, LOW);
                         analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, LOW);
                        digitalWrite(leftMotor2, HIGH);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                       // delay(100);
                      //  stop_motor_with_revers();
                       // delay(100);
                        // u=0;
                        gear=0;
                     }
       }//black line follow
void white_line_follow()
    { 
      
      white_line_pid_calibration();
      digital_pid();
      white_line_motor_speed();
      
      
       
                if(PID_state==0)
                    {
                       // speed_up();  
                        digitalWrite(rightMotor1, HIGH);
                        digitalWrite(rightMotor2, LOW);
                        analogWrite(rightMotorPWM, rightMotor_gear_Speed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotor_gear_Speed);
                       // u=0;
                        
                   }
                    else if( PID_state==1 & digital_sensor_position == left_side) //left sens
                      {
                        stop_motor_with_revers(); 
                        delay(1);
                        rightMotorSpeed = 80;
                        leftMotorSpeed  = 80;
                        digitalWrite(rightMotor1, LOW);
                        digitalWrite(rightMotor2, HIGH);
                        analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                       // delay(100);
                       //u=0;
                       gear=0;
                     }else if(PID_state==1 & digital_sensor_position == right_side)//right sens
                     {
                         stop_motor_with_revers(); 
                         delay(1);
                         rightMotorSpeed = 80;
                         leftMotorSpeed  = 80;
                         digitalWrite(rightMotor1, HIGH);
                         digitalWrite(rightMotor2, LOW);
                         analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, LOW);
                        digitalWrite(leftMotor2, HIGH);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
                       // delay(100);
                       //u=0;
                       gear=0;
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
              //-----------------------
               gear = gear +0.5;
               if(gear > max_gear)
                    {
                      gear= max_gear; 
                    }
               rightMotor_gear_Speed = rightMotorSpeed + gear ;
               leftMotor_gear_Speed  = leftMotorSpeed +  gear;
                //Serial.println(rightMotorSpeed);
              // delay(5);
              //----------------------
    }//black_line_motor_speed
void white_line_motor_speed()
    {
             rightMotorSpeed = rightBaseSpeed - motorSpeed;
             leftMotorSpeed = leftBaseSpeed + motorSpeed;
              if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
              if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
              if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
              if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
              //----------------------
               //-----------------------
               gear = gear +0.5;
               if(gear > max_gear)
                    {
                      gear= max_gear; 
                    }
               rightMotor_gear_Speed = rightMotorSpeed + gear ;
               leftMotor_gear_Speed  = leftMotorSpeed +  gear;
                //Serial.println(rightMotorSpeed);
                
              
              //------------------------
    }//end white line motor speed    

 void black_pid_calibration()
     {
              sensors[3];
             position = qtra.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
           // Serial.println(position);
            if (sensors[0] > 200 || sensors[1] > 200 || sensors[2] > 200)
                {
                   PID_state=1;
                  //return;
                }else
                   {
                      PID_state=0;
                   
                   }
                 //----------------------------------------
                    indicating_PID_LED_For_black_line();      
                //------------------------------------------         
             error = position - 1000;  //2500 for 5 Sensors
           // Serial.println(error);
             motorSpeed = Kp * error + Kd * (error - lastError);
             lastError = error; 
     } 
void digital_pid()
    {
              digital_sens_read_for_pid();
              error_digital = current_position;
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
       for(u=0;u<6;u++)
              {
                 digital_sens_reading[u] = digitalRead(digital_sens[u]);
                 if(digital_sens_reading[u]==line)  //1
                       {
                         current_position = sensor_value[u] ;
                        // Serial.println(current_position); 
                         // u=6;
                       }
                       
                       //..................for indicating 
                       
                       indicating_digital_LED_For_any_line();
                             
                          //---------------------------------
              }//end for loop
  
  
  }//end digital_sens_read_for_pid
  
  void indicating_digital_LED_For_any_line()
 {
   
    if(digital_sens_reading[0]==line)
                         {
                           digitalWrite(indicator[0],HIGH);
                         
                         }else
                             {
                               digitalWrite(indicator[0],LOW);
                             
                             }
                           
                        if(digital_sens_reading[1]==line)
                         {
                           digitalWrite(indicator[1],HIGH);
                         
                         }else
                             {
                               digitalWrite(indicator[1],LOW);
                             
                             }   
                         if(digital_sens_reading[2]==line)
                         {
                           digitalWrite(indicator[2],HIGH);
                         
                         }else
                             {
                               digitalWrite(indicator[2],LOW);
                             
                             } 
                        if(digital_sens_reading[3]==line)
                         {
                           digitalWrite(indicator[6],HIGH);
                         
                         }else
                             {
                               digitalWrite(indicator[6],LOW);
                             
                             }     
                         if(digital_sens_reading[4]==line)
                         {
                           digitalWrite(indicator[7],HIGH);
                         
                         }else
                             {
                               digitalWrite(indicator[7],LOW);
                             
                             }    
                      if(digital_sens_reading[5]==line)
                         {
                           digitalWrite(indicator[8],HIGH);
                         
                         }else
                             {
                               digitalWrite(indicator[8],LOW);
                             
                             } 
                     
 
 }
 

 void indicating_PID_LED_For_black_line()
   {
      if (sensors[0] > 200)
                       {
                          digitalWrite(indicator[3],HIGH);
                         
                       }else
                         {
                            digitalWrite(indicator[3],LOW);
                         
                         }   
                         
                       if (sensors[1] > 200)
                       {
                          digitalWrite(indicator[4],HIGH);
                         
                       }else
                         {
                            digitalWrite(indicator[4],LOW);
                         
                         }  
                      if (sensors[2] > 200)
                       {
                          digitalWrite(indicator[5],HIGH);
                         
                       }else
                         {
                            digitalWrite(indicator[5],LOW);
                         
                         } 
   
   }
   
 void left_turn_indicating()
 {
                        digitalWrite(indicator[2],HIGH);
                        delay(50);
                        digitalWrite(indicator[1],HIGH);
                        delay(50);
                        digitalWrite(indicator[0],HIGH);
                        delay(50);
                        digitalWrite(indicator[2],LOW);
                        delay(50);
                        digitalWrite(indicator[1],LOW);
                        delay(50);
                        digitalWrite(indicator[0],LOW);
                        delay(50);

 
 }
 
void right_turn_indicating()
{
                         digitalWrite(indicator[8],HIGH);
                         delay(50);
                         digitalWrite(indicator[7],HIGH);
                         delay(50);
                         digitalWrite(indicator[6],HIGH);
                         delay(50);
                         digitalWrite(indicator[8],LOW);
                         delay(50);
                         digitalWrite(indicator[7],LOW);
                         delay(50);
                         digitalWrite(indicator[6],LOW);
                         delay(50);
                        

}

void sonar_pid()
 {
              sonar_read();
              sonar_error = target_cm - current_cm;
              sonar_proportional = sonar_error * sonar_kp;
              sonar_integrate = sonar_integrate + sonar_error;
              sonar_integrate = sonar_integrate * sonar_ki;
              sonar_derivative = sonar_error - sonar_previous_error;
              sonar_error_correction = sonar_proportional + sonar_integrate + sonar_derivative ; 
              
             // if( sonar_error_correction > 100 ) { sonar_error_correction = 100; }
              //if( sonar_error_correction <-100 ) { sonar_error_correction = -100; }
              // Serial.println(current_position); 
              
              sonar_pwm_right = 100 + sonar_error_correction;
              sonar_pwm_left  = 100 - sonar_error_correction;
              if(sonar_pwm_right > sonar_max_pwm_right )
                  {
                     sonar_pwm_right = sonar_max_pwm_right;
                      
                  }
               if(sonar_pwm_left > sonar_max_pwm_left )
                  {
                     sonar_pwm_left = sonar_max_pwm_left;
                      
                  }
                if(sonar_pwm_right < 0 )
                  {
                     sonar_pwm_right = 0;
                      
                  }
               if(sonar_pwm_left < 0 )
                  {
                     sonar_pwm_left = 0;
                      
                  }
              
//                 if(sonar_error_correction==0)
//                     {
//                        sonar_pwm_right = 100 ;
//                        sonar_pwm_left = 100;
//                     
//                     }
//                if(sonar_error_correction >0) //& sonar_error_correction<60)//go straight
//                    
//                     {
//                        sonar_pwm_right = sonar_error_correction ;
//                        sonar_pwm_left = sonar_error_correction; //100 - sonar_error_correction;
//                    
//                   }else if(error_correction <0)// & sonar_error_correction <-60 ) // Turn left
//                      {
//                        sonar_pwm_right = sonar_error_correction;//100 - sonar_error_correction;
//                        sonar_pwm_left = sonar_error_correction ;
//                      } //else // Turn right
                  //    Serial.println(sonar_error_correction);
                
                 
 
 
 
 }
 
void sonar_read()
 {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      cm = duration / 29 / 2;
      current_cm=cm;
     // delay(50);
 
 }
 
 void sonar_follow()
 {
                        
                        digitalWrite(rightMotor1, HIGH);
                        digitalWrite(rightMotor2, LOW);
                        analogWrite(rightMotorPWM, sonar_pwm_right);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM,sonar_pwm_left );
 
 }
 
 void follow_line_with_sonar()
    {
    
      sonar_pid();
      sonar_follow();
    
    }
void motor_full_stop()
  {
                       digitalWrite(rightMotor1, LOW);
                       digitalWrite(rightMotor2, LOW);
                       analogWrite(rightMotorPWM, rightMotorSpeed);
                       digitalWrite(leftMotor1, LOW);
                       digitalWrite(leftMotor2, LOW);
                       analogWrite(leftMotorPWM, leftMotorSpeed);
  
  }
void indicating_PID_LED_For_white_line()
   {
      if (sensors[0] < 100)
                       {
                          digitalWrite(indicator[3],HIGH);
                         
                       }else
                         {
                            digitalWrite(indicator[3],LOW);
                         
                         }   
                         
                       if (sensors[1] < 100)
                       {
                          digitalWrite(indicator[4],HIGH);
                         
                       }else
                         {
                            digitalWrite(indicator[4],LOW);
                         
                         }  
                      if (sensors[2] < 100)
                       {
                          digitalWrite(indicator[5],HIGH);
                         
                       }else
                         {
                            digitalWrite(indicator[5],LOW);
                         
                         } 
   
   }
void white_line_pid_calibration()
     {
              sensors[3];
             position = qtra.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
           // Serial.println(position);
            if (sensors[0] < 100 || sensors[1] < 100 || sensors[2] < 100)
                {
                   PID_state=0;
                  //return;
                }else
                   {
                      PID_state=1;
                   
                   }
                 //----------------------------------------
                    indicating_PID_LED_For_white_line();      
                //------------------------------------------         
             error = position - 1000;  //2500 for 5 Sensors
           // Serial.println(error);
             motorSpeed = Kp * error + Kd * (error - lastError);
             lastError = error; 
     }

void turn_left()
  {
  
                        rightMotorSpeed = 80;
                        leftMotorSpeed  = 80;
                        digitalWrite(rightMotor1, LOW);
                        digitalWrite(rightMotor2, HIGH);
                        analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, HIGH);
                        digitalWrite(leftMotor2, LOW);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
  
  }
  
 void turn_right()
 {
                         rightMotorSpeed = 80;
                         leftMotorSpeed  = 80;//this is right motor
                         digitalWrite(rightMotor1, HIGH);
                         digitalWrite(rightMotor2, LOW);
                         analogWrite(rightMotorPWM, rightMotorSpeed);
                 
                        digitalWrite(leftMotor1, LOW);
                        digitalWrite(leftMotor2, HIGH);
                        analogWrite(leftMotorPWM, leftMotorSpeed);
 
 
 }

