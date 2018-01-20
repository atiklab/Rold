
int leftCenterSensor = 0; //   3
int leftNearSensor  = 0; //   4
int leftFarSensor    = 0  ; //5
int rightCenterSensor = 0 ; // 2
int rightNearSensor   = 0; // 1
int rightFarSensor     = 0; //0

int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;

int leftNudge;
int replaystage;
int rightNudge;

#define leapTime 200
int el = 3;
#define leftMotor1  5
#define leftMotor2  6
int er = 9;
#define rightMotor1 10
#define rightMotor2 11
int i;
#define led 13

#define NUM_SENSORS   6
int sensors[] = {A0, A2, A1, A3, A4, A5};
int sv[NUM_SENSORS], sv2[NUM_SENSORS], temp[NUM_SENSORS], maxv[NUM_SENSORS], minv[NUM_SENSORS];
int  threshold[NUM_SENSORS]={300,300,500,350,400,150};
int bspeed;
int SPEED;
int MSPEED;

char path[30] = {};
int pathLength;
int readLength;

void setup() {
  for (int i = 0; i < NUM_SENSORS; i++)
    pinMode(sensors[i], INPUT);


  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  digitalWrite(led, HIGH);
  SPEED = 150;
  analogWrite(el, SPEED);
  analogWrite(er, SPEED);
  delay(100);
 // calibration();
}


void loop() {

  readSensors();

  if (leftFarReading < 200 && rightFarReading < 200 &&
      (leftCenterReading > 200 || rightCenterReading > 200) ) {
    straight();
  }
  else {
    leftHandWall();
  }

}

void readSensors() {
  for (int i = 0; i < NUM_SENSORS; i++) {

    sv[i] = analogRead(sensors[i]);
    // print out the value you read:
    Serial.print(sv[i]);
    Serial.print('\t');
    if (sv[i] < threshold[i])
      sv2[i] = 1;
    else
      sv2[i] = 0;
  }
  Serial.println('\t');
  if (sv2[0] == 1)
    leftFarReading  = 300;
  else //if (sv[0] == 0)
    leftFarReading  = 100;

  if (sv2[1] == 1)
    leftNearReading  = 300;
  else //if (sv[1] == 0)
    leftNearReading  = 100;

  if (sv2[2] == 1)
    leftCenterReading  = 300;
  else //if (sv2[2] == 0)
    leftCenterReading  = 100;

  if (sv2[3] == 1)
    rightCenterReading  = 300;
  else //if (sv2[3] == 0)
    rightCenterReading  = 100;

  if (sv2[4] == 1)
    rightNearReading  = 300;
  else //if (sv2[4] == 0)
    rightNearReading  = 100;

  if (sv2[5] == 1)
    rightFarReading  = 300;
  else //if (sv2[5] == 0)
    rightFarReading  = 100;
  //leftNearReading    = analogRead(leftNearSensor);
  // leftFarReading     = analogRead(leftFarSensor);
  //rightCenterReading = analogRead(rightCenterSensor);
  //rightNearReading   = analogRead(rightNearSensor);
  //  rightFarReading    = analogRead(rightFarSensor);

  // serial printing below for debugging purposes

  // Serial.print("leftCenterReading: ");
  // Serial.println(leftCenterReading);
  // Serial.print("leftNearReading: ");
  // Serial.println(leftNearReading);
  // Serial.print("leftFarReading: ");
  // Serial.println(leftFarReading);

  // Serial.print("rightCenterReading: ");
  // Serial.println(rightCenterReading);
  // Serial.print("rightNearReading: ");
  // Serial.println(rightNearReading);
  // Serial.print("rightFarReading: ");
  // Serial.println(rightFarReading);
  // delay(200);


}


void leftHandWall() {


  if ( leftFarReading > 200 && rightFarReading > 200) {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    readSensors();

    if (leftFarReading > 200 || rightFarReading > 200) {
      done();
    }
    if (leftFarReading < 200 && rightFarReading < 200) {
      turnLeft();
    }

  }

  if (leftFarReading > 200) { // if you can turn left then turn left
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    readSensors();

    if (leftFarReading < 200 && rightFarReading < 200) {
      turnLeft();
    }
    else {
      done();
    }
  }

  if (rightFarReading > 200) {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(30);
    readSensors();

    if (leftFarReading > 200) {
      delay(leapTime - 30);
      readSensors();

      if (rightFarReading > 200 && leftFarReading > 200) {
        done();
      }
      else {
        turnLeft();
        return;
      }
    }
    delay(leapTime - 30);
    readSensors();
    if (leftFarReading < 200 && leftCenterReading < 200 &&
        rightCenterReading < 200 && rightFarReading < 200) {
      turnRight();
      return;
    }
    path[pathLength] = 'S';
    // Serial.println("s");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
    if (path[pathLength - 2] == 'B') {
      //Serial.println("shortening path");
      shortPath();
    }
    straight();
  }
  readSensors();
  if (leftFarReading < 200 && leftCenterReading < 200 && rightCenterReading < 200
      && rightFarReading < 200 && leftNearReading < 200 && rightNearReading < 200) {
    turnAround();
  }

}
void done() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  replaystage = 1;
  path[pathLength] = 'D';
  pathLength++;
  while (analogRead(leftFarSensor) > 200) {
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
  }
  delay(500);
  replay();
}

void turnLeft() {



  while (analogRead(rightCenterSensor) > 200 || analogRead(leftCenterSensor) > 200) {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }

  while (analogRead(rightCenterSensor) < 200) {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }

  if (replaystage == 0) {
    path[pathLength] = 'L';
    //Serial.println("l");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
    if (path[pathLength - 2] == 'B') {
      //Serial.println("shortening path");
      shortPath();
    }
  }
}

void turnRight() {


  while (analogRead(rightCenterSensor) > 200) {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
  while (analogRead(rightCenterSensor) < 200) {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
  while (analogRead(leftCenterSensor) < 200) {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }

  if (replaystage == 0) {
    path[pathLength] = 'R';
    Serial.println("r");
    pathLength++;
    Serial.print("Path length: ");
    Serial.println(pathLength);
    if (path[pathLength - 2] == 'B') {
      Serial.println("shortening path");
      shortPath();
    }
  }

}

void straight() {
  if ( analogRead(leftCenterSensor) < 200) {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(1);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(5);
    return;
  }
  if (analogRead(rightCenterSensor) < 200) {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(1);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(5);
    return;
  }

  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  delay(4);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  delay(1);

}

void turnAround() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  delay(150);
  while (analogRead(leftCenterSensor) < 200) {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
  path[pathLength] = 'B';
  pathLength++;
  straight();
  //Serial.println("b");
  //Serial.print("Path length: ");
  //Serial.println(pathLength);
}

void shortPath() {
  int shortDone = 0;
  if (path[pathLength - 3] == 'L' && path[pathLength - 1] == 'R') {
    pathLength -= 3;
    path[pathLength] = 'B';
    //Serial.println("test1");
    shortDone = 1;
  }

  if (path[pathLength - 3] == 'L' && path[pathLength - 1] == 'S' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'R';
    //Serial.println("test2");
    shortDone = 1;
  }

  if (path[pathLength - 3] == 'R' && path[pathLength - 1] == 'L' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'B';
    //Serial.println("test3");
    shortDone = 1;
  }


  if (path[pathLength - 3] == 'S' && path[pathLength - 1] == 'L' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'R';
    //Serial.println("test4");
    shortDone = 1;
  }

  if (path[pathLength - 3] == 'S' && path[pathLength - 1] == 'S' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'B';
    //Serial.println("test5");
    shortDone = 1;
  }
  if (path[pathLength - 3] == 'L' && path[pathLength - 1] == 'L' && shortDone == 0) {
    pathLength -= 3;
    path[pathLength] = 'S';
    //Serial.println("test6");
    shortDone = 1;
  }

  path[pathLength + 1] = 'D';
  path[pathLength + 2] = 'D';
  pathLength++;
  //Serial.print("Path length: ");
  //Serial.println(pathLength);
  //printPath();
}




void printPath() {
  Serial.println("+++++++++++++++++");
  int x;
  while (x <= pathLength) {
    Serial.println(path[x]);
    x++;
  }
  Serial.println("+++++++++++++++++");
}


void replay() {
  readSensors();
  if (leftFarReading < 200 && rightFarReading < 200) {
    straight();
  }
  else {
    if (path[readLength] == 'D') {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      delay(100);
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
      endMotion();
    }
    if (path[readLength] == 'L') {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      delay(leapTime);
      turnLeft();
    }
    if (path[readLength] == 'R') {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      delay(leapTime);
      turnRight();
    }
    if (path[readLength] == 'S') {
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      delay(leapTime);
      straight();
    }

    readLength++;
  }

  replay();

}

void endMotion() {
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(500);
  endMotion();
}
void calibration()
{
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    maxv[i] = analogRead(sensors[i]);
    minv[i] = analogRead(sensors[i]);
  }

  //mway('R');
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  for (int j = 0; j < 100; j++)
  {
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      temp[i] = analogRead(sensors[i]);
      if (temp[i] > maxv[i])
        maxv[i] = temp[i];
      if (temp[i] < minv[i])
        minv[i] = temp[i];
    }
    delay(3);
  }

  //mway('s');
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  delay(50);
  //mway('L');
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  for (int j = 0; j < 200; j++)
  {
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      temp[i] = analogRead(sensors[i]);
      if (temp[i] > maxv[i])
        maxv[i] = temp[i];
      if (temp[i] < minv[i])
        minv[i] = temp[i];
    }
    delay(3);
  }
  // mway('s');
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  delay(50);
  //mway('R');
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  for (int j = 0; j < 100; j++)
  {
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      temp[i] = analogRead(sensors[i]);
      if (temp[i] > maxv[i])
        maxv[i] = temp[i];
      if (temp[i] < minv[i])
        minv[i] = temp[i];
    }
    delay(3);
  }
  //mway('s');
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  delay(50);
  for (i = 0; i < NUM_SENSORS; i++)
  {
    threshold[i] = minv[i] + (maxv[i] - minv[i]) / 2;
    Serial.print(threshold[i]);
    Serial.print('\t');
  }
}
