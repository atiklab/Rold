String readString;
int flag=0;
void setup() {
  Serial.begin(115200);
}

void loop() {

  while (Serial.available()) {
   delay(1); 

    char c = Serial.read(); 
    if (c == ',') {
      flag=0;
      break;
    } 
    readString += c; 
  } 


 if (readString[0] == 'a') {
      Serial.println("hello");

    }
    
    

  if (readString.length() >0) {
    Serial.println(readString); 

    readString=""; 
  }
}
