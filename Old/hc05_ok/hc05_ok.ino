////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
AT+NAME=Eduino
AT+UART=115200,0,0
AT+PSWD=2017
AT+POLAR=1,0
AT+INIT



AT : Ceck the connection.
AT+NAME : See default name
AT+ADDR : see default address
AT+VERSION : See version
AT+UART : See baudrate
AT+ROLE: See role of bt module(1=master/0=slave)
AT+RESET : Reset and exit AT mode
AT+ORGL : Restore factory settings
AT+PSWD: see default password



*/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {

Serial.begin(9600);

pinMode(9,OUTPUT); digitalWrite(9,HIGH);

Serial.println("Enter AT commands:");

mySerial.begin(38400);

}

void loop()

{

if (mySerial.available())

Serial.write(mySerial.read());

if (Serial.available())

mySerial.write(Serial.read());

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

