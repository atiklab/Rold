//Example code for testing a serial bluetooth device using Arduino and a serial terminal on a computer
void setup() {
  // set baud rate to match BT module
  Serial.begin(115200);
}

void loop() {
  
  String t; //string to hold data from BT module 
  while(Serial.available()) { //keep reading bytes while they are still more in the buffer
    t += (char)Serial.read(); //read byte, convert to char, and append it to string
  }
  
  if(t.length()) { //if string is not empty do the following
    
    if(t == "Hi Uno\r\n") { Serial.print("Hello Neil\n"); } //say hello
    else if(t == "Meaning of life?\r\n") { //find out the meaning of life
      delay(1000);
      Serial.print("Money. ");
      delay(1000);
      Serial.print("Guns. ");
      delay(1000);
      Serial.print("Hoes.\n");
      delay(1000);
      Serial.print("Arduino.\n");
   }
   else { Serial.print("Syntax Error\n"); } //send this for any other string
  }
   delay(20);
}
