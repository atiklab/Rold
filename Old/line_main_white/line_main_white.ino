int lf = 2; 
int lb = 3; 
int rf = 4; 
int rb = 5; 
int led = 13;
int s[6]={A0,A1,A2,A3,A4,A5};
int r1= 0;
int r2= 0;
int m1= 0;
int l1= 0;
int l2= 0;
int m2= 0;
int ob= 0;
int hole= 0;
int lw= 0;
int rw= 0;
int lt= 0;
int rt= 0;

int i;
int key;
int state=0;
int flag=0; 
int stateStop=0;
void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  for(i=0;i<12;i++)
  pinMode(s[i], INPUT);

      Serial.begin(9600);
     pinMode(led, OUTPUT); 

}

void loop() {  
      r1 = digitalRead(s[0]);
      r2 = digitalRead(s[1]);
      m1 = digitalRead(s[2]);
      l2 = digitalRead(s[3]);
      l1 = digitalRead(s[4]);
      m2 = digitalRead(s[5]);
      ob = digitalRead(s[6]);
      hole = digitalRead(s[7]);
      lw = digitalRead(s[8]);
      rw = digitalRead(s[9]);
      lt = digitalRead(s[10]);
      rt = digitalRead(s[11]);
     if(r1==HIGH&&r2==HIGH&&m1==LOW&&l1==HIGH&&l2==HIGH&&m2==LOW)
   {
      mway('1'); 
  } 
  else if(r1==HIGH&&r2==HIGH&&l1==HIGH&&l2==HIGH)
  mway('1');
  else if(r2==LOW&&m1==LOW&&l2==LOW)
  mway('1');
  else if(r1==LOW&&r2==LOW&&l1==LOW&&l2==LOW&&m1==LOW&&m2==LOW)
  mway('3');
  else if(r1==HIGH&&r2==HIGH&&l1==HIGH&&l2==HIGH&&(m1==LOW||m2==LOW))
   {
      mway('1');
  }
 else if(r1==LOW&&l1==HIGH&&l2==HIGH)
      mway('3'); 
 else if(r2==LOW&&l1==HIGH&&l2==HIGH)
      mway('2'); 
 else if(l1==LOW&&r1==HIGH&&r2==HIGH)
      mway('6'); 
 else if(l2==LOW&&r1==HIGH&&r2==HIGH)
      mway('5'); 
      
      
 else if(r1==LOW&&l1==HIGH&&l2==LOW)
      mway('3'); 
 else if(l1==LOW&&r1==HIGH&&r2==LOW)
      mway('6'); 
      
      
  else {
    // turn LED off:
    digitalWrite(led, LOW);
   mway(57); 
  }    
}
void mway(int state)
{
  if (state == '1') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("Go Forward!");
    }
    else if (state == '2') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("SL");
    }
    else if (state == '3') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("HL");
    }
    else if (state == '4') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("BACK");
    }
    else if (state == '5') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
          Serial.println("SR");
    }
    else if (state == '6') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("HR");
    }

    else if (state == '9') {
        digitalWrite(lf, LOW); 
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
        digitalWrite(led, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
}
