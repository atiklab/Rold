/*
The circuit:
* RX is digital pin 10 (connect to TX of GSM Modem)
* TX is digital pin 11 (connect to RX of GSM Modem)
*/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 9); // RX, TX
char callnum[]={"ATD+8801830259379;"};
void setup()
{
// Open serial communications and wait for port to open:
Serial.begin(9600);

Serial.println("Calling through GSM Modem");

// set the data rate for the SoftwareSerial port
mySerial.begin(9600);
delay(2000);
mySerial.println(callnum); //"ATD+8801830259379;" ATD81290255XX; -- watch out here for semicolon at the end!!

Serial.println("Called ATD+8801830259379");
}

void loop() // run over and over
{
// print response over serial port
if (Serial.available())
mySerial.write(Serial.read());
if (mySerial.available())
Serial.write(mySerial.read());
}
