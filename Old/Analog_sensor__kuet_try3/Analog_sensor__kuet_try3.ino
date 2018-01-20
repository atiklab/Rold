  
 #define left_forward 5
 #define right_forward 10
 #define left_backward 6
 #define right_backward 11
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
  int digital_sens[6]={A0,A1,A2,A3,A4,A5}; // 2,13,8 left sens and 9,10,12 right sens
  int digital_sens_reading[6];
 int temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];




void setup() {

Serial.begin(115200);

pinMode(left_forward,OUTPUT);
pinMode(right_forward,OUTPUT);
pinMode(left_backward,OUTPUT);
pinMode(right_backward,OUTPUT);

//calibration();
  

}

void loop() {


       for(u=0;u<6;u++)
              {
                 digital_sens_reading[u] = analogRead(digital_sens[u]);
                 if(digital_sens_reading[u] >500 )  //1 >200== Black
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
                                  analogWrite(left_forward,120);
                                  analogWrite(right_forward,0);
                                 // delay(5);
                                  analogWrite(left_backward,0);
                                  analogWrite(right_backward,120);
//                                 right_forward 10
//                                  left_backward 6
//                                right_backward 11
                                    
                  
                  }else if(digital_sensor_position == left_side)
                     {
                      //right  turn 
                      
                                  analogWrite(left_forward,0);
                                  analogWrite(right_forward,120);
                                 // delay(5);
                                  analogWrite(left_backward,120);
                                  analogWrite(right_backward,0);
                      
                      
                      }else if(digital_sensor_position == forwards)
                          {
                            
                                  analogWrite(left_forward,120);
                                  analogWrite(right_forward,120);
                                  //delay(5);
                                  analogWrite(left_backward,0);
                                  analogWrite(right_backward,0);
                            
                            }


                            previous_error =error_digital;
 


}

