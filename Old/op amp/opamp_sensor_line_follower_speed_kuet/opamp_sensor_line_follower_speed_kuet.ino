int lf = 3; 
int lb = 2; 
int rf = 5; 
int rb = 4;
int led = 13;
int cpeed=150;
int bcpeed=130;
int lspeed=0;
int aspeed=0,bspeed=0;
int i;
int state=0;
int flag=0; 
int stateStop=0;
int s[6]={A0,A1,A2,A3,A4,A5};
int s1[6], v[6];
long int sum,rs,ls,ps=0,ts=0;
void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(led, OUTPUT);
  for(int i=0;i<6;i++)
  pinMode(s[i], INPUT);
  Serial.begin(9600);
delay(1000);
}

void loop() {
  sum=0;rs=0;ls=0;
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
  ls=v[1]*10+v[2];
  rs=v[4]*10+v[5];
  Serial.print(sum);
 Serial.println();

drive: 
 if(sum==ts)
  {
    if(cpeed <255)
   cpeed = cpeed +1;
    else
    cpeed =250;
  }
  else
  cpeed =bcpeed;
if(sum==00000)
mway('s');
else if(sum==11011)
mway('f');
else if((sum==10011)||(sum==10111))
mway('l');
else if((sum==111)||(sum==1111))
mway('l');
else if((sum==11)||(sum==11))
mway('l');
else if((sum==11001)||(sum==11101))
mway('r');
else if((sum==11100)||(sum==11110))
mway('r');
else if((sum==11000)||(sum==10000))
mway('r');


else if((sum==11111)||(sum==11000)||(sum==10001)||(sum==10000)||(sum==00011)||(sum==00001))
{sum=ts;
goto drive;
}
else
mway('s');
 if(ts!=sum)
   ts=sum;

}
void mway(int state)
{

if (state == 'f') {
        analogWrite(lf, cpeed);
        digitalWrite(lb, LOW); 
        analogWrite(rf, cpeed);
        digitalWrite(rb, LOW);
          Serial.println("Go Forward!");
    }
    else if (state == 'l') {
        analogWrite(lf, lspeed);
        digitalWrite(lb, LOW); 
        analogWrite(rf, cpeed);
        digitalWrite(rb, LOW);
          Serial.println("SL");
    }
    else if (state == 'L') {
        analogWrite(lf, lspeed);
        digitalWrite(lb, HIGH); 
        analogWrite(rf, cpeed);
        digitalWrite(rb, LOW);
          Serial.println("HL");
    }
        else if (state == 'm') {
        analogWrite(lf, lspeed);
        digitalWrite(lb, HIGH); 
        analogWrite(rf, lspeed);
        digitalWrite(rb, LOW);
          Serial.println("BL");
     }
    else if (state == 'b') {
        analogWrite(lf, lspeed);
        digitalWrite(lb, HIGH); 
        analogWrite(rf, lspeed);
        digitalWrite(rb, HIGH);
          Serial.println("BACK");
    }
    else if (state == 'r') {
        analogWrite(lf, cpeed);
        digitalWrite(lb, LOW); 
        analogWrite(rf, lspeed);
        digitalWrite(rb, LOW);
          Serial.println("SR");
    }
    else if (state == 'R') {
        analogWrite(lf, cpeed);
        digitalWrite(lb, LOW); 
        analogWrite(rf, lspeed);
        digitalWrite(rb, HIGH);
          Serial.println("HR");
    }
    else if (state == 'q') {
        analogWrite(lf, lspeed);
        digitalWrite(lb, LOW); 
        analogWrite(rf, lspeed);
        digitalWrite(rb, HIGH);
          Serial.println("BR");
    }

    else if (state == 's') {
        analogWrite(lf, lspeed); 
        digitalWrite(lb, LOW); 
        analogWrite(rf, lspeed);
        digitalWrite(rb, LOW);
        digitalWrite(led, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
}

