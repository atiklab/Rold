int lf=5;
int lb=6;
int rf=7;
int rb=8;

int el=9;
int er=10;
int mspeed=40;
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
  //mway3(mspeed,mspeed);

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
      else if (state == 'F') mway3(mspeed,mspeed);
      else if (state == 'B') mway3(-mspeed,-mspeed);
      else if (state == 'R') mway3(mspeed,-mspeed);
      else if (state == 'L') mway3(-mspeed,mspeed);
      else if (state == 'S') mway3(0,0);  
      else if (state == 'a') Serial.print("Connecting to ");

   }
}
