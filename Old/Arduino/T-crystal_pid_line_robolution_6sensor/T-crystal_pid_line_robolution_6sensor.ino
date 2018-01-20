int a=0; //for line white =0/black=1
#define b 1
#define Kp .05// experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .15 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define Ki 0
int SPEEDmax=250;
int SPEEDbase=100;
int rightMaxSpeed =SPEEDmax; // max speed of the robot
int leftMaxSpeed =SPEEDmax; // max speed of the robot
int rightBaseSpeed =SPEEDbase; // this is the speed at which the motors should spin when the robot is perfectly on the line
int leftBaseSpeed =SPEEDbase;  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  6
int cspeed =80;

int MSPEED=100;

int lf = 7; 
int lb = 8; 

int rf = 9; 
int rb = 10; 
 int i;
 int forwards=0;
int sensors[]={A0, A1, A2, A3, A4,A5};
int sv[NUM_SENSORS],temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];
int sv2[NUM_SENSORS];
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ms=0,ols,ors;

int lastError = 0;
  int position; 
  int position2;
    int vleft=0;
    int vstraight=0;
    int vright=0;


void setup() {

Serial.begin(9600);

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

