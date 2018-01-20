
int seg[7]={14,15,16,17,18,19,20};
int ndis[]={5,6,7};
int a;
int motor =3;
int level[5]={13,10,11,12,9};
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
//collect();
display7();

}

