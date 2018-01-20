#include <QTRSensors.h>
#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A0, A1, A2, 7,8, A3, A4, A5},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sv[NUM_SENSORS];
int sv2[NUM_SENSORS]={1,1,1,1,1,1,1,1};
unsigned long int sum=0,ts=0,ps=0;
int lf = 5; 
int lb = 6; 
int rf = 10; 
int rb = 11; 
int led = 13;
int vSpeed =200;
int state=0;
int flag=0; 
int stateStop=0;

void setup()
{
  delay(500);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200); // set the data rate in bits per second for serial data transmission
  delay(1000);
  
}


void loop()
{
  // read raw sensor values
  qtrrc.read(sv);
sum=0;
  // print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (int i = 0; i < NUM_SENSORS; i++)
  {
   
    
   if(sv[i]>300)
    sv2[i]=1;
    else
    sv2[i]=0;
    Serial.print(sv[i]);
    Serial.print('\t');
  sum=sum*10+sv2[i];
  // Serial.print(sv2[i]);
   Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
    Serial.print(sum);
    Serial.print('\t');
   // Serial.print(ts);
  Serial.println();

 
  
}


void mway(int state)
{

if (state == 'f') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("Go Forward!");
    }
    else if (state == 'l') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("SL");
    }
    else if (state == 'L') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
          Serial.println("HL");
    }
        else if (state == 'm') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
          Serial.println("BL");
     }
    else if (state == 'b') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("BACK");
    }
    else if (state == 'r') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, LOW);
          Serial.println("SR");
    }
    else if (state == 'R') {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("HR");
    }
    else if (state == 'q') {
        digitalWrite(lf, LOW);
        digitalWrite(lb, LOW); 
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
          Serial.println("BR");
    }

    else if (state == 's') {
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
