void moto()
{
  
}
void f()
{
   digitalWrite(rf, HIGH);
   digitalWrite(rb, LOW);
   digitalWrite(lf, HIGH);
   digitalWrite(lb, LOW);
}
void sm()
{
   digitalWrite(rf, LOW);
   digitalWrite(rb, LOW);
   digitalWrite(lf, LOW);
   digitalWrite(lb, LOW);
}
void b()
{
   digitalWrite(rf, LOW);
   digitalWrite(rb, HIGH);
   digitalWrite(lf, LOW);
   digitalWrite(lb, HIGH);
}
void rforward()
{
   digitalWrite(rf, LOW);
   digitalWrite(rb, LOW);
   digitalWrite(lf, HIGH);
   digitalWrite(lb, LOW);
}
void lforward()
{
   digitalWrite(rf, HIGH);
   digitalWrite(rb, LOW);
   digitalWrite(lf, HIGH);
   digitalWrite(lb, LOW);
}
void rbackward()
{
   digitalWrite(rf, LOW);
   digitalWrite(rb, LOW);
   digitalWrite(lf, LOW);
   digitalWrite(lb, HIGH);
}
void lbackward()
{
   digitalWrite(rf, LOW);
   digitalWrite(rb, HIGH);
   digitalWrite(lf, LOW);
   digitalWrite(lb, LOW);
}
