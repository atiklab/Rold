#define trigPin 8
#define echoPin 7
#define trigPin1 13
#define echoPin1 12
int SPEED;
int lf = 5; 
int lb = 6; 
int rf = 10; 
int rb = 11; 
int state=0;
int flag=0; 
int stateStop=0;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);

 
  Serial.begin(9600);
  //delay(500);

  SPEED=150;
}

void loop() {
  long duration, distance;
 // long duration1, distance1;
  digitalWrite(trigPin, LOW);  
  //digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
 // digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
 // digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin, HIGH);
 // duration1 = pulseIn(echoPin1, HIGH);
  distance = (duration/2) / 29.1;
  //distance1 = (duration1/2) / 29.1;

  if (distance >= 5000 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
   // Serial.print(distance1);
   // Serial.println(" cm");
  }

    if (distance>11)
  mway('r');
  if ((distance<11)&&distance>5)
  mway('f');
  if (distance<9)
  mway('l');
}
void mway(int state)
{

if (state == 'f') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
         // Serial.println("F");
    }
    else if (state == 'l') {
        analogWrite(lf, 0 );
        analogWrite(lb, 0); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
        // Serial.println("l");
    }
    else if (state == 'L') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, SPEED);
        analogWrite(rb, 0);
        //  Serial.println("L");
    }
        else if (state == 'm') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        // Serial.println("BL");
     }
    else if (state == 'b') {
        analogWrite(lf, 0);
        analogWrite(lb, SPEED); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
        // Serial.println("BACK");
    }
    else if (state == 'r') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        //  Serial.println("r");
    }
    else if (state == 'R') {
        analogWrite(lf, SPEED);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
         // Serial.println("R");
    }
    else if (state == 'q') {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, SPEED);
        // Serial.println("BR");
    }

    else if (state == 's') {
        analogWrite(lf, 0); 
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
       
        if(flag == 0){
        // Serial.println("S");
          flag=1;
        }
        stateStop=0;
    }
}

