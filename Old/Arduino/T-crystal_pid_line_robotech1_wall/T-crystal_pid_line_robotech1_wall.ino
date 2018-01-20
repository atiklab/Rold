int a=0; //for line white =0/black=1
#define trigPin 23
#define echoPin 22
#define ltrigPin 13
#define lechoPin 12
#define b 1.25
#define Kp .18// experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .44 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define Ki 0
int SPEEDmax=200;
int SPEEDbase=200;
int rightMaxSpeed =SPEEDmax; // max speed of the robot
int leftMaxSpeed =SPEEDmax; // max speed of the robot
int rightBaseSpeed =SPEEDbase; // this is the speed at which the motors should spin when the robot is perfectly on the line
int leftBaseSpeed =SPEEDbase;  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  5 
int cspeed =70;

int MSPEED=130;
int ob=0;
int wa=0;



int lf = 7; 
int lb = 8; 

int rf = 9; 
int rb = 10; 
 int i;
 int forwards=0;
int sensors[]={A0,A1,A2,A3,A4};
int sv[NUM_SENSORS],temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];
int sv2[NUM_SENSORS];
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ms=0,ols,ors;

int lastError = 0;
int lposition;
int duration, distance;
int duration1, distance1;
  int position; 
  int position2;
    int vleft=0;
    int vstraight=0;
    int vright=0;


void setup() {

Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ltrigPin, OUTPUT);
  pinMode(lechoPin, INPUT);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);


calibration();

//  if((sv[0]>threshold[0])&&(sv[4]>threshold[4]))
//    a=0;
//  else if((sv[0]<threshold[0])&&(sv[4]<threshold[4]))
//  a=1;
}

void loop() {
 


     
       followline();
      
     
}

