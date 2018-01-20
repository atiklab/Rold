int a=1; // line black=0, white=1
#define Kp .15 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd .5 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 250 // max speed of the robot
#define leftMaxSpeed 250 // max speed of the robot
#define rightBaseSpeed 200 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 200  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  6 
int el=9;
int er=10;
int lf = 5; 
int lb = 6; 
int rf = 7; 
int rb = 8; 
 int i;
 int forwards=0;
int sensors[]={A5, A2, A1, A3, A4,A0};
int sv[NUM_SENSORS],temp[NUM_SENSORS],maxv[NUM_SENSORS],minv[NUM_SENSORS],threshold[NUM_SENSORS];
int sv2[NUM_SENSORS];
unsigned long int sum=0,ts=0,ps=0,ls=0,rs=0,ms=0,ols,ors;
int bspeed =130;
int SPEED;
int MSPEED=200;
int lastError = 0;
  int position; 
  int position2;
    int vleft=0;
    int vstraight=0;
    int vright=0;


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

calibration();


}

void loop() {
      //followline();
}

