int lf = 3; 
int lb = 2; 
int rf = 5; 
int rb = 4;
int led = 13;
int i;
int state=0,line=0,pline=0;
int flag=0; 
int stateStop=0;
int s[6]={A0,A1,A2,A3,A4,A5};
int s1[6], v[6];
long int sum,ps=0,ts=0;
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
  
  
  drive: 
  sum=0;
  for(int i=1;i<6;i++)
  {
    s1[i]=digitalRead(s[i]);
    if (s1[i]==HIGH)
    v[i]=1;
    else
    v[i]=0;
    sum=sum*10+v[i];
    Serial.print(v[i]);
    Serial.print("\t");
  }
  Serial.print(sum);
 Serial.println();


if(sum==00000)
line='s';
else if(sum==11011)
line='f';
else if((sum==10011)||(sum==10111))
line='l';
else if((sum==111)||(sum==1111))
line='l';
else if((sum==11001)||(sum==11101))
line='r';
else if((sum==11100)||(sum==11110))
line='r';
else
line='s';

mway(line);

if((sum==11111)||(sum==11000)||(sum==10001)||(sum==10000)||(sum==00011)||(sum==00001))
{sum=ts;
line =pline;
mway(line);
goto drive;
}
if(ts!=sum)
{
   ts=sum;
   pline=line;
   
}

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
