//Updated on 02 April 2017 by Nudge Me

signed int x;
signed int y;
signed int z;
signed int btna;
signed int btnb;
float a;
float m;


String str;
char dir = 0;


int ML1 = 5;
int ML2 = 6;
int MR1 = 7;
int MR2 = 8;


int EL = 9;   
int ER = 10; 

int el = 0;
int er = 0;

int elp = 0;
int erp = 0;


boolean fast = true;



void setup() {
  
pinMode(ER, OUTPUT); 
pinMode(EL, OUTPUT); 
pinMode(ML1, OUTPUT); 
pinMode(ML2, OUTPUT); 
pinMode(MR1, OUTPUT); 
pinMode(MR2, OUTPUT); 


pinMode(10,OUTPUT);
digitalWrite(10,LOW);

Serial.begin(115200);
Serial.println("Start");
}


void loop() 
{
    while(Serial.available())
    {
      
      char getData = Serial.read();
      
      
        
        if (getData == '~') {
        
          x = Serial.parseInt();
        
            if (Serial.read() == '*') {
        
              y = Serial.parseInt();
        
                if (Serial.read() == '@') {
                
                  z = Serial.parseInt();
                  
                    if (Serial.read() == '#') {
                    
                      process();
                  }                
              } 
           }
        }
        
          
        
    }
    
}





void process(){

  Serial.println("x: " + String(x) + ", y: " + String(y));

  Serial.print("Received x: " );
  Serial.print(x);
  
  Serial.print(", Received y: " );
  Serial.println(y);
  

  //left motor control:
    
  if (fast == false) { er = map(y, 0, 255, 0, 255); }
  else { er = y; }

  if (er < 0) { 
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);  
  } 
  
  else if (er >= 0) { 
    digitalWrite(MR1, LOW);
    digitalWrite(MR2, HIGH);
  } 
  
  erp = abs(er);
  

//right motor control:

  if (fast == false) { el = map(x, 0, 255, 0, 255); }
  else { el = x; }

  if (el < 0) { 
    digitalWrite(ML1, HIGH); 
    digitalWrite(ML2, LOW); 
  } 
  
  else if (el >= 0)  {
    digitalWrite(ML1, LOW); 
    digitalWrite(ML2, HIGH); 
  } 
  
  elp = abs(el);
                                                 
  analogWrite(EL, elp);  
  analogWrite(ER, erp);     
  
  
  Serial.flush(); 
}  
