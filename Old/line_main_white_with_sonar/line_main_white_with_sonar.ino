#define trigPin 13
#define echoPin 12
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


int i;
int key;
int state=0;
int flag=0; 
int stateStop=0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
      r1 = digitalRead(s[0]);
      r2 = digitalRead(s[1]);
      m1 = digitalRead(s[2]);
      l2 = digitalRead(s[3]);
      l1 = digitalRead(s[4]);
      m2 = digitalRead(s[5]);
     if (distance <= 20)
      mway('9');
 
    else if(r1==LOW&&r2==LOW&&l1==LOW&&l2==LOW)
  mway('9');

  else if(r1==HIGH&&r2==HIGH&&l1==HIGH&&l2==HIGH)
  mway('1');
  else if(r2==LOW&&m1==LOW&&l2==LOW)
  mway('1');

 else if(r1==LOW&&l1==HIGH&&l2==HIGH)
      mway('2'); 
 else if(r2==LOW&&l1==HIGH&&l2==HIGH)
      mway('2'); 
 else if(l1==LOW&&r1==HIGH&&r2==HIGH)
      mway('5'); 
 else if(l2==LOW&&r1==HIGH&&r2==HIGH)
      mway('5'); 
 else if(r1==LOW&&l1==HIGH&&l2==LOW)
      mway('2'); 
 else if(l1==LOW&&r1==HIGH&&r2==LOW)
      mway('5'); 
      
    else if(r1==HIGH&&r2==LOW&&l1==LOW&&l2==LOW)
     mway('5'); 
     else if(r1==HIGH&&r2==HIGH&&l1==LOW&&l2==HIGH)  
     mway('5'); 
      
      
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
