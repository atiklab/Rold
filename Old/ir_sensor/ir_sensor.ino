
/*---------------------------
IR LED and phototransistor beam test and calibration

debug stuff:
min/max val = whatever the value is when it changes
LED is always on
----------------------------*/
// defines for pins
#define IRoutputPin 2        // digital output pin
#define IRinputAnalogPin 0   // analog input pin
#define LEDsignalPin 13      // LED signal pin

// int and long values
int val = 0;           // variable to store the value read from input pin
int minVal = 1000;
int maxVal = 0;
int oldVal= 0;

// strings
String outputString;
String intro = "JTD IR test and calibration init";
boolean needIntro = true;
String signalBase = "Signal Strength: ";
String minBase = "Min: ";
String maxBase = "Max: ";

void setup()
{
  pinMode(IRoutputPin,OUTPUT);
  digitalWrite(IRoutputPin,HIGH);
  pinMode(LEDsignalPin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // print header
   if (needIntro == true)
    {Serial.println(intro);
    needIntro = false;}
  digitalWrite(LEDsignalPin, HIGH);    // turn signal LED on

// read value of analog input   
  val = analogRead(IRinputAnalogPin);    // read the input pin
  //Serial.println(val);             // debug value
  
  if (val != oldVal)          // if the new value is different than the old value, then do stuff
  {

   String outputString = signalBase + val;     // concatenates output for signal strength
  Serial.println(outputString);
    outputString = minBase + minVal;     // concatenates output for min
  Serial.println(outputString);
    outputString = maxBase + maxVal;     // concatenates output for max
  Serial.println(outputString);
    oldVal = val;
    
  delay(500);                      // wait half a second
  }

    
    if (val < minVal)      // conditional if val is less than prior minVal
  {  //String outputString = minBase + val;     // concatenates output
  Serial.println(outputString);
    minVal = val;}
    
  if (val > maxVal)      // conditional if val is greater than prior maxVal
  {  String outputString = maxBase + val;     // concatenates output
  //Serial.println(outputString);
    maxVal = max(maxVal, val);}
}
