int lf=5;
int lb=6;
int rf=10;
int rb=11;
int s[4]={A3,A2,A1,A0};
int s1[4];
unsigned long int sum=0,ts=0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 6,9,10,11 as  output.
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
    for(int i=0;i<4;i++)
  pinMode(s[i], INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
      for(int i=0;i<4;i++)
      {
       s1[i]=digitalRead(s[i]);
       //Serial.print(s1[i]);
      }
      
  sum=0;
   for (int i=0;i<4;i++)
   sum=sum*10+s1[i];
        Serial.print(sum);
       Serial.println("");


if ((sum==110)||(sum==0))
f();
else if((sum==1111))
sm();
else if((sum==11)||(sum==1))
rforward();
else if((sum==1100)||(sum==1000))
lforward();
       
}
