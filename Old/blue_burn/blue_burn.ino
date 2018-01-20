#include <SoftwareSerial.h>
SoftwareSerial BSerial(10, 11); // RX | TX


void setup() {
    Serial.begin(9600);
    //Serial.begin(38400); 
    Serial.println("AT+INIT");    
    delay(500);   
    Serial.println("AT+NAME=Eduino");   
    delay(500);   
    Serial.println("AT+UART=115200,0,0");   
    delay(500);   
    Serial.println("AT+POLAR=1,0");   
    delay(500);
    
}

void loop() {
}
