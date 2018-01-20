int lf=5;
int lb=6;
int rf=9;
int rb=10;

int el=3;
int er=11;
int mspeed=240;
int state;

void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(115200);

}

void loop() {

   if(Serial.available() > 0){     
      state = Serial.read();   
      digitalWrite(13, HIGH);
           if (state == '0') mspeed=0;
      else if (state == '1') mspeed=90;
      else if (state == '2') mspeed=150;
      else if (state == '3') mspeed=190;
      else if (state == '4') mspeed=220;
      else if (state == '5') mspeed=255;
      else if (state == 'F') {
        mway2(mspeed,mspeed);
        Serial.println("Forward");
      }
                              
      else if (state == 'B') mway2(-mspeed,-mspeed);
      else if (state == 'R') mway2(mspeed,-mspeed);
      else if (state == 'L') mway2(-mspeed,mspeed);
      else if (state == 'S') mway2(0,0);  
      else if (state == 'G') mway2(0,mspeed);
      else if (state == 'H') mway2(-mspeed,0);
      else if (state == 'I') mway2(mspeed,0);
      else if (state == 'J') mway2(0,-mspeed);

   }
}




