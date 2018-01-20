int speed = 10; 
int pauseDelay = 2000;  
char requestString[] = " ECE ";  
int index = 0;  //this is the current charachter in the string being displayed
int offset = 0; //this is how many columns it is offset by


int rowA[] = {9,8,7,6,5,4,3,2};         
int colA[] = {17,16,15,14,13,12,11,10};  
const int A = 0;  const int B = 1;  const int C = 2;  const int D = 3;  const int E = 4;
const int Z = 5;

//Punctuation
const int  _ = 6;
 
//Extra Charchters
const int  FULL =7;
byte data[] = {0,0,0,0,0,0,0,0};        

const int _A[] = {B0001000,
                  B0010100,
                  B0100010,
                  B1000001,
                  B1111111,
                  B1000001,
                  B1000001,
                  B0000000};

const int _B[] = {B1111110,
                  B0100001,
                  B0100001,
                  B0111110,
                  B0100001,
                  B0100001,
                  B1111110,
                       B0000000};

const int _C[] = {B0011111,
                  B0100000,
                  B1000000,
                  B1000000,
                  B1000000,
                  B0100000,
                  B0011111,
                       B0000000};

const int _D[] = {B1111100,
                  B0100010,
                  B0100001,
                  B0100001,
                  B0100001,
                  B0100010,
                  B1111100,
                       B0000000};

const int _E[] = {B1111111,
                  B1000000,
                  B1000000,
                  B1111100,
                  B1000000,
                  B1000000,
                  B1111111,
                       B0000000};
const int _Z[] = {B1111111,
                  B0000010,
                  B0000100,
                  B0001000,
                  B0010000,
                  B0100000,
                  B1111111,
                  B0000000};                  

const int __[] = {B0000000,
                  B0000000,
                  B0000000,
                  B0000000,
                  B0000000,
                  B0000000,
                  B0000000,
                       B0000000};

const int _FULL[] = {B1111111,
                     B1111111,
                     B1111111,
                     B1111111,
                     B1111111,
                     B1111111,
                     B1111111,
                       B0000000};                
const int* letters[] = {_A,_B,_C,_D,_E,_Z,__, _FULL};
void setup()
{ 
  
  for(int i = 0; i <8; i++){  //Set the 16 pins used to control the array as OUTPUTs
    pinMode(rowA[i], OUTPUT);
    pinMode(colA[i], OUTPUT);
  }
}

//repeats   
void loop()
{
   if (Serial.available() > 0){
    ;//requestString =(char) Serial.read();
   }
 updateMatrix();
}



void updateMatrix(){
  loadSprite();
  showSprite(speed);
}


//An array holding the powers of 2 these are used as bit masks when calculating what to display
const int powers[] = {1,2,4,8,16,32,64,128};

//Loads the current scroll state frame into the data[] display array
void loadSprite(){
  int currentChar = getChar(requestString[index]);
  int nextChar = getChar(requestString[index+1]);
  
  for(int row=0; row < 8; row++){                    //iterate through each row
    data[row] = 0;                                   //reset the row we're working on
    for(int column=0; column < 8; column++){         //iterate through each column
     data[row] = data[row] + ((powers[column] & (letters[currentChar][row] << offset)));   //loads the current charachter offset by offset pixels 
     data[row] = data[row] + (powers[column] & (letters[nextChar][row] >> (8-offset) ));   //loads the next charachter offset by offset pixels
    }
  }
  offset++;                                          //increment the offset by one row
  if(offset==8){offset = 0; index++; if(index==sizeof(requestString)-2){index=0;}}         //if offset is 8 load the next charachter pair for the next time through
}

void showSprite(int speed2){
 for(int iii = 0; iii < speed2; iii++){                 //show the current frame speed2 times
  for(int column = 0; column < 8; column++){            //iterate through each column
   for(int i = 0; i < 8; i++){                          
       digitalWrite(rowA[i], LOW);                      //turn off all row pins  
   }
   for(int i = 0; i < 8; i++){ //Set only the one pin
     if(i == column){     digitalWrite(colA[i], LOW);}  //turns the current row on
     else{                digitalWrite(colA[i], HIGH); }//turns the rest of the rows off
   }

   for(int row = 0; row < 8; row++){                    //iterate through each pixel in the current column
    int bit = (data[column] >> row) & 1;
    if(bit == 1){ 
       digitalWrite(rowA[row], HIGH);                   //if the bit in the data array is set turn the LED on
    }

   }
   delayMicroseconds(pauseDelay);                       //leave the column on for pauseDelay microseconds (too high a delay causes flicker)
  } 
 }
}

//returns the index of a given charachter
//for converting from a string to a lookup in our array of charachter bitmaps
int getChar(char charachter){
 int returnValue = Z;
 switch(charachter){
  case 'C': returnValue = C; break;
  case 'c': returnValue = C; break;
  case 'D': returnValue = D; break;
  case 'd': returnValue = D; break;
  case 'E': returnValue = E; break;
  case 'e': returnValue = E; break;
  case 'Z': returnValue = Z; break;
  case 'z': returnValue = Z; break;
  case ' ': returnValue = _; break;      
  }
  return returnValue;
}


