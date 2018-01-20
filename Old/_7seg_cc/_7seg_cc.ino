
int segcc[7]={14,15,16,17,18,19,20};
int ndiscc[]={2,3,4,5,6,7};
int a;
int motor =3;
int level[5]={13,10,11,12,9};
int dig=6;
void setup() 
{
  for( a=0;a<7;a++)  
  {
  pinMode(segcc[a],OUTPUT);
  }
  for( a=0;a<dig;a++) 
  {
  pinMode(ndiscc[a],OUTPUT);
  }
  for( a=0;a<5;a++) 
  {
  pinMode(level[a],INPUT);
  }
pinMode(motor,OUTPUT);
}
void loop()
{

display7cc();

}

