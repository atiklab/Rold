#define NUM_SENSORS   6
int led =9;
int val=255;
int sensors[]={A0, A1, A2, A4, A3, A5};
unsigned int sv[NUM_SENSORS];
int sv2[NUM_SENSORS];
unsigned long int sum=0;
void setup() {
  pinMode(led, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  analogWrite(led, val);
}

// the loop routine runs over and over again forever:
void loop() {
  sum=0;
  // read the input on analog pin 0:
  for (int i=0;i<NUM_SENSORS;i++){
    
  sv[i] = analogRead(sensors[i]);
  // print out the value you read:
  Serial.print(sv[i]);
  Serial.print('\t');
  }
   
   if(sv[0]>200)
   sv2[0]=0;
   else
   sv2[0]=1;
   if(sv[1]>650)
   sv2[1]=0;
   else
   sv2[1]=1;
   if(sv[2]>600)
   sv2[2]=0;
   else
   sv2[2]=1;
  if(sv[3]>660)
   sv2[3]=0;
   else
   sv2[3]=1;
   if(sv[4]>500)
   sv2[4]=0;
   else
   sv2[4]=1;
   if(sv[5]>300)
   sv2[5]=0;
   else
   sv2[5]=1;
   for (int i=0;i<6;i++)
   sum=sum*10+sv2[i];
   //Serial.print(sum);
   Serial.println();
  delay(1);        // delay in between reads for stability
}
