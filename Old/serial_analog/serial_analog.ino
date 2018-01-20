


int state;
int potpin = 0;  // analog pin used to connect the potentiometer
int val = 0;    // variable to read the value from the analog pin 
int AC_LOAD=3;
void setup() 
{ 
pinMode(AC_LOAD, OUTPUT);
  Serial.begin(115200);
} 

void loop() 
{ 
  state = Serial.read();            


  if (state == '1') {
    if (val<200)
      val = val + 10;
      
    Serial.println(val);  
  analogWrite(val); 
  }
  else if (state == '2') { 
    if (val>0)
      val = val - 10;
    
    Serial.println(val);  
 analogWrite(val); 
  }

 
} 

