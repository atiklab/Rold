#include <IRremote.h>

int RECV_PIN = 11;
int state ;
int led = 13;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    long int decCode = results.value;
    Serial.println("HEX: ");
    Serial.println(results.value, HEX);
    Serial.println(results.value);
    irrecv.resume();
  }
}
