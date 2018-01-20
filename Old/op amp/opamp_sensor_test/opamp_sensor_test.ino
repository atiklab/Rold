int s[6]={A0,A1,A2,A3,A4,A5};
int s1[6], v[6];
long int sum;
void setup() {
  for(int i=0;i<6;i++)
  pinMode(s[i], INPUT);
  Serial.begin(115200);
}

void loop() {
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

}
