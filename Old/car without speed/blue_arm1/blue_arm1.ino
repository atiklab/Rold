int motor1Pin1 = 2; // pin 2 on L293D IC
int motor1Pin2 = 3; // pin 7 on L293D IC

int motor2Pin1 = 4; // pin 10 on L293D IC
int motor2Pin2 = 5; // pin 15 on L293D IC

int motor3Pin1 = 6;
int motor3Pin2 = 7;

int motor4Pin1 = 8;
int motor4Pin2 = 9;

int led = 13;
int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
   
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
  
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    
    pinMode(motor3Pin1, OUTPUT);
    pinMode(motor3Pin2, OUTPUT);
    
    pinMode(motor4Pin1, OUTPUT);
    pinMode(motor4Pin2, OUTPUT);
  
    Serial.begin(9600);
     pinMode(led, OUTPUT); 
}

void loop() {
  digitalWrite(led, HIGH);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, HIGH);
    
}
