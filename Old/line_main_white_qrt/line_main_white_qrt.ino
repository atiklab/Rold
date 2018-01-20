#include <QTRSensors.h>
#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   11    // emitter is controlled by digital pin 2


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A0, A1, A2, 9,10, A3, A4, A5},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int s[NUM_SENSORS];
int sv2[NUM_SENSORS];
int lf = 2; 
int lb = 3; 
int rf = 4; 
int rb = 5; 
int led = 13;

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
  for(i=0;i<6;i++)
  pinMode(s[i], INPUT);

      Serial.begin(9600);
     pinMode(led, OUTPUT); 
     delay(1000);

}

void loop() {  
  qtrrc.read(s);

  // print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
 
    
    if(s[i]>600)
    sv2[i]=0;
    else
    sv2[i]=1;
    //Serial.print(sv[i]);
   // Serial.print('\t');
    Serial.print(sv2[i]);
    Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
  Serial.println();
      r1 = digitalRead(sv2[0]);
      r2 = digitalRead(sv2[1]);
      m1 = digitalRead(sv2[2]);
      l2 = digitalRead(sv2[3]);
      l1 = digitalRead(sv2[4]);
      m2 = digitalRead(sv2[5]);
   
       
if(r1==HIGH&&r2==HIGH&&l1==HIGH&&l2==HIGH)
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
