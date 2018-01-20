
int seg[7]={A0,8,A2,A3,A4,A5,2};
int ndis[]={5,6,7};
int a;
int motor =3;
int level[5]={9,10,11,12,13};
void setup() 
{
  for( a=0;a<7;a++)  
  {
  pinMode(seg[a],OUTPUT);
  }
  for( a=0;a<3;a++) 
  {
  pinMode(ndis[a],OUTPUT);
  }
  for( a=0;a<5;a++) 
  {
  pinMode(level[a],INPUT);
  }
pinMode(motor,OUTPUT);
}
void loop()
{
  //test();
//collect();
display7();

}

