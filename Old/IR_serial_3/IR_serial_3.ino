#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println("HEX: ");
    Serial.println(results.value, HEX);
    Serial.println("DECIMAL: ");
    Serial.println(results.value, DEC);
    Serial.println("BINARY: ");
    Serial.println(results.value, BIN);
    irrecv.resume();
  }
}
