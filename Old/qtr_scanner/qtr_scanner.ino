int bspeed =100;
int SPEED;
int MSPEED=70;
int lf = 5; 
int lb = 6; 
int rf = 9; 
int rb = 10; 
int led = 13;
int position;
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
  //calibration();
   SPEED=100;
 mway('f');
  delay(200) ;
  mway('s');
  
}


void loop()
{
  readSensors();
  
 drive:
;


}

