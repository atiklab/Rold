int lf=5;
int lb=6;
int rf=7;
int rb=8;

int el=9;
int er=10;
int mspeed=255;
int state;
int flag=0;  

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
       flag=0;  
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
      else if (state == 'G') mway3(0,mspeed);
      else if (state == 'H') mway3(-mspeed,0);
      else if (state == 'I') mway3(mspeed,0);
      else if (state == 'J') mway3(0,-mspeed);







   }
}



void mway3(int lspeed,int rspeed )
{
  
  if (lspeed==0)
  {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
  }
  else if(lspeed>0)
  {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH);  
  }
if (rspeed==0)
  {
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW); 
  }
  else if(rspeed>0) 
  {
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);  
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);  
  }
 analogWrite(el, lspeed);
 analogWrite(er, rspeed);
}

