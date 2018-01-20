#define DIGIT1 3
#define DIGIT2 5
#define DIGIT3 6
#define DIGIT4 9
#define DIGIT5 10
#define DIGIT6 11

#define SEGMENTA A0
#define SEGMENTB A1
#define SEGMENTC A2
#define SEGMENTD A3
#define SEGMENTE A4
#define SEGMENTF A5
#define SEGMENTG 8


#define BUTTON 4

#define ON  HIGH
#define OFF LOW

#define DELAYTIME 50

unsigned short hours, minutes, seconds;

unsigned long lastTime; // keeps track of when the previous second happened

int buttonState;             // the current reading from the button pin
int lastButtonState = LOW;   // the previous reading from the button pin
unsigned long button_down_start = 0; // how long the button was held down
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time

void setup() {                
  // initialize all the required pins as output.
  pinMode(DIGIT1, OUTPUT);
  pinMode(DIGIT2, OUTPUT);
  pinMode(DIGIT3, OUTPUT);
  pinMode(DIGIT4, OUTPUT);
  pinMode(DIGIT5, OUTPUT);
  pinMode(DIGIT6, OUTPUT);

  pinMode(SEGMENTA, OUTPUT);
  pinMode(SEGMENTB, OUTPUT);
  pinMode(SEGMENTC, OUTPUT);
  pinMode(SEGMENTD, OUTPUT);
  pinMode(SEGMENTE, OUTPUT);
  pinMode(SEGMENTF, OUTPUT);
  pinMode(SEGMENTG, OUTPUT);


  // button is input
  pinMode(BUTTON, INPUT);
  
  // set the initial time
  hours = 9;
  minutes = 7;
  seconds = 0;
 

  lastTime = millis();
}

void loop() {
  
  // Keep showing the display while waiting for timer to expire  
  while (millis() - lastTime < 1000) {
    clock_show_time(hours, minutes,seconds);

    // blink the colon, every even second
    if (seconds % 2 == 0) {
      clock_show_colon();
    }

    // button presses increase minutes
    int reading = digitalRead(BUTTON);
 
     // If the switch changed, due to noise or pressing:
    if (reading != lastButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    }
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer
      // than the debounce delay, so take it as the actual current state:
      
      if (buttonState != reading) {
        button_down_start = millis(); // record the start of the current button state
      }
      
      buttonState = reading;
      
      // buttonState is now either on or off
      if (buttonState == HIGH) {
        // if the button was held down more than 5 seconds, make it go faster
        if ((millis() - button_down_start) > 5000) {
          seconds += 10;
          if (seconds > 59) seconds = 59;
        }
        
        // button has been pressed
        incrementTime();
      }
    } 
 
    lastButtonState = reading;
  }

  lastTime += 1000;
  
  incrementTime();
}

//
// a call to incrementTime increases time by one second.
//
void incrementTime() {
  
  if (seconds == 59) {
    seconds = 0;
    
    if (minutes == 59) {
      minutes = 0;
      
      if (hours == 12) {          
        hours = 1;
      }
      else {
        hours++;
        

      }
    }
    else {
      minutes++;
    }
  }
  else {
    seconds++;  
  }
}

//
// clock_show_time - displays the given time on the clock display
//   Note that instead of hr/min the user can also send min/sec
//   Maximum hr is 99, Maximum min is 59, and minimum is 0 for both (it's unsigned, heh).
//
void clock_show_time(unsigned short hours, unsigned short minutes,unsigned short seconds) {
  unsigned short i;
  unsigned short delaytime;
  unsigned short num_leds[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
  unsigned short digit[6];
  unsigned short hide_leading_hours_digit;
    
  // convert minutes and seconds into the individual digits
  // check the boundaries
  if (hours > 99) hours = 99;
  if (minutes > 59) minutes = 59;
  if (seconds > 59) seconds = 59;
  // convert hr
  if (hours < 10 && hours > 0) {
    hide_leading_hours_digit = 1;
  }
  else {
    hide_leading_hours_digit = 0;
  }
  
  digit[0] = hours / 10;
  digit[1] = hours % 10; // remainder  seconds
  digit[2] = minutes / 10;
  digit[3] = minutes % 10; // remainder  
  digit[5] = seconds/10;
  digit[6] = seconds%10; // remainder  

  for (i = hide_leading_hours_digit; i < 6; i++) {
    clock_all_off();
    clock_show_digit(i, digit[i]);

    // fewer leds = brighter display, so delay depends on number of leds lit.
    delaytime = num_leds[digit[i]] * DELAYTIME;   
    delayMicroseconds(delaytime);
  }
  
  clock_all_off();
  

  
  
}

//
// clock_all_off - turns off all the LEDs on the clock to give a blank display
//
void clock_all_off(void) {
  
  // digits must be ON for any LEDs to be on
  digitalWrite(DIGIT1, OFF);
  digitalWrite(DIGIT2, OFF);
  digitalWrite(DIGIT3, OFF);
  digitalWrite(DIGIT4, OFF);
  digitalWrite(DIGIT5, OFF);
  digitalWrite(DIGIT6, OFF);
  
  // segments must be OFF for any LEDs to be on
  digitalWrite(SEGMENTA, ON);
  digitalWrite(SEGMENTB, ON);
  digitalWrite(SEGMENTC, ON);
  digitalWrite(SEGMENTD, ON);
  digitalWrite(SEGMENTE, ON);
  digitalWrite(SEGMENTF, ON);
  digitalWrite(SEGMENTG, ON);
  
}

//
// clock_show_digit - turns on the LEDs for the digit in the given position
//      position can be from 0 through 3: 0 and 1 being the hour, 2 and 3 being the seconds
//      value can be from 0 through 9, ie, a valid single digit.
//
//      (if value is out of range, it displays a 9. if digit is out of range display remains blank)
//
void clock_show_digit(unsigned short position, unsigned short value) {
  byte a;
  byte b;
  byte c;
  byte d;
  byte e;
  byte f;
  byte g;

  switch (position) {
    case 0:
      digitalWrite(DIGIT1, ON);
      break;
    case 1:
      digitalWrite(DIGIT2, ON);
      break;
    case 2:
      digitalWrite(DIGIT3, ON);
      break;
    case 3:
      digitalWrite(DIGIT4, ON);
      break;
    case 4:
      digitalWrite(DIGIT5, ON);
      break;
    case 5:
      digitalWrite(DIGIT6, ON);
      break;
  }

  a = !(value == 1 || value == 4);
  b = !(value == 5 || value == 6);
  c = !(value == 2);
  d = !(value == 1 || value == 4 || value == 7);
  e =  (value == 0 || value == 2 || value == 6 || value == 8);
  f = !(value == 1 || value == 2 || value == 3 || value == 7);
  g = !(value == 0 || value == 1 || value == 7);
  
  if (a) digitalWrite(SEGMENTA, OFF);
  if (b) digitalWrite(SEGMENTB, OFF);
  if (c) digitalWrite(SEGMENTC, OFF);
  if (d) digitalWrite(SEGMENTD, OFF);
  if (e) digitalWrite(SEGMENTE, OFF);
  if (f) digitalWrite(SEGMENTF, OFF);
  if (g) digitalWrite(SEGMENTG, OFF);
}

//
// clock_show_colon - shows the colon that separates minutes from seconds
//
void clock_show_colon(void) {
  unsigned short delaytime;


                              // 2 leds = 2 delays needed
  delaytime = DELAYTIME * 2;  // must use variable to have similar delay to rest of clock
  delayMicroseconds(delaytime);   //   because use of variable slows it down slightly.

}

//
// clock_show_alarm - shows the ampm dot (bottom right of clock display)
//
void clock_show_ampm(void) {
  unsigned short delaytime;


                      
  delaytime = DELAYTIME;  // must use variable to have similar delay to rest of clock
  delayMicroseconds(delaytime);   //   because use of variable slows it down slightly.

}

