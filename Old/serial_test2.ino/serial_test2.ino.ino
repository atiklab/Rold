String readString;
int flag=0;
void setup() {
  Serial.begin(115200);
}

void loop() {

  //expect a string like wer,qwe rty,123 456,hyre kjhg,
  //or like hello world,who are you?,bye!,
  while (Serial.available()) {
   delay(1);  //small delay to allow input buffer to fill

    char c = Serial.read();  //gets one byte from serial buffer
    if (c == ',') {
      flag=0;
      break;
    }  //breaks out of capture loop to print readstring
    readString += c; 
  } //makes the string readString  


 if (readString[0] == 'a') {
      Serial.println("hello");

    }
    
    

  if (readString.length() >0) {
    Serial.println(readString); //prints string to serial port out

    readString=""; //clears variable for new input
  }
}
