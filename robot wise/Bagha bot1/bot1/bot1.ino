#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
Servo myservo1;
Servo myservo2; 
int val = 100;
int val2 = 30;
int val3 = 0;

int lf=2;
int lb=3;
int rf=4;
int rb=5;

int el=6;
int er=7;
int mspeed=255;
int cspeed=200;
int tm=200;
int state;
int flag=0;  

void setup() {
  myservo.attach(9);
  myservo1.attach(10);
  myservo2.attach(11);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(115200);
  myservo1.write(val);
   myservo.write(val2);
   //time_test();

}

void loop() {
   if(Serial.available() > 0){     
      state = Serial.read(); 
       flag=0;  
      //digitalWrite(13, HIGH);


   
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



       else if (state == 'a'){
         if (val<170)
         val = val + 10;
         myservo1.write(val);
          digitalWrite(13, HIGH);
         Serial.print(val);
          Serial.println("Up");
          flag=1;
          delay(40);
       
       }
      else if (state == 'b') {
        if (val>10)
        val = val - 10;
        myservo1.write(val);
         digitalWrite(13, LOW);
          Serial.print(val);
          Serial.println("Down");
          flag=1;
           delay(40);
        
      }
             else if (state == 'c'){
         if (val2<170)
         val2 = val2 + 10;
         myservo.write(val2);
         Serial.print(val2);
          Serial.println("Up");
          flag=1;
          delay(40);
       
       }
      else if (state == 'd') {
        if (val2>10)
        val2 = val2 - 10;
        myservo.write(val2);
          Serial.print(val2);
          Serial.println("Down");
          flag=1;
           delay(40);
        
      }
        



   }
}
void mway3(int lspeed,int rspeed )
{
  if (rspeed==0)
  {
        analogWrite(rf, 0);
        analogWrite(rb, 0); 
  }
  else if(rspeed>0)
  {
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);  
  }
  else if(rspeed<0)
  {
        rspeed=-rspeed;
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);  
  }
if (lspeed==0)
  {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
  }
  else if(lspeed>0) 
  {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0);  
  }
  else if(lspeed<0)
  {
        lspeed=-lspeed;
        analogWrite(lf, 0);
        analogWrite(lb, lspeed);  
  }

}




