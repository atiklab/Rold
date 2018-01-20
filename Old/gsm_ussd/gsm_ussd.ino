#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX
char incoming_char;
void setup() {
   mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());  

}
