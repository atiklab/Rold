int lf=10;
int lb=11;
int rf=9;
int rb=8;
int lf1=6;
int lb1=7;
int rf1=5;
int rb1=4;
//int el=9;
//int er=10;

int mspeed=40;
int state;
     

void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(lf1, OUTPUT);
  pinMode(lb1, OUTPUT);
  pinMode(rf1, OUTPUT);
  pinMode(rb1, OUTPUT);


  Serial.begin(9600);

}

void loop() {

   if(Serial.available() > 0){     
      state = Serial.read();   

           if (state == '1') mspeed=130;
      else if (state == '2') mspeed=160;
      else if (state == '3') mspeed=190;
      else if (state == '4') mspeed=220;
      else if (state == '5') mspeed=255;
      else if (state == 'F') mway2(mspeed,mspeed);
      else if (state == 'B') mway2(-mspeed,-mspeed);
      else if (state == 'R') mway2(mspeed,-mspeed);
      else if (state == 'L') mway2(-mspeed,mspeed);
      else if (state == 'S') mway2(0,0);  

   }
}
