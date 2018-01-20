int lf = 6; 
int lb = 7; 
int rf = 9; 
int rb = 10;
int led = 13;
int i;
int state=0,line=0;
int flag=0; 
int stateStop=0;
int s[]={A0,A1,A2,A3};
int s1[6], v[6];
long int sum,ps=0,ts=0,ls=0,rs=0;
void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  for(int i=0;i<6;i++)
  pinMode(s[i], INPUT);
  Serial.begin(9600);
}

void loop() {
  sum=0;
  for(int i=0;i<4;i++)
  {
    s1[i]=digitalRead(s[i]);
    if (s1[i]==HIGH)
    v[i]=1;
    else
    v[i]=0;
    sum=sum*10+v[i];
   ls=v[0]*10+v[1];
   rs=v[2]*10+v[3];
    Serial.print(v[i]);
    Serial.print("\t");
  }
  Serial.print(sum);
 Serial.println();

drive: 
if(ls==rs)
 mway('f');
 else if(ls<rs)
 mway('r');
 else if(ls>rs)
 mway('l');

if((sum==11111)||(sum==11000)||(sum==10001)||(sum==10000)||(sum==00011)||(sum==00001))
{sum=ts;
goto drive;
}
if(ts!=sum)
   ts=sum;

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
