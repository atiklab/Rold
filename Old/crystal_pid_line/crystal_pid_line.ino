
#define Kp .15 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .40 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
int bspeed =100;
int CSPEED=90;
int SPEED=100;
int MSPEED=150;
int rightMaxSpeed =MSPEED; // max speed of the robot
int leftMaxSpeed =MSPEED; // max speed of the robot
int rightBaseSpeed =SPEED; // this is the speed at which the motors should spin when the robot is perfectly on the line
int leftBaseSpeed =SPEED;  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  6 
int el=3;
int lf = 11; 
int lb = 10; 
int er=9;
int rf = 6; 
int rb = 4; 
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
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  digitalWrite(el, HIGH);
  digitalWrite(er, HIGH);

calibration();


}

void loop() {
      followline();
}

