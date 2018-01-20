int state=0;
int flag=0; 
int stateStop=0;


void mway(int state)
{
int lspeed=  SPEED;
int rspeed=  SPEED;
if (state == 'f') {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0); 
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);
          Serial.println("Go Forward!");
    }
    else if (state == 'l') {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);
          Serial.println("SL");
    }
    else if (state == 'L') {
        analogWrite(lf, 0);
        analogWrite(lb, lspeed); 
        analogWrite(rf, rspeed);
        analogWrite(rb, 0);
          Serial.println("HL");
    }
        else if (state == 'm') {
        analogWrite(lf, 0);
        analogWrite(lb, lspeed); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
          Serial.println("BL");
     }
    else if (state == 'b') {
        analogWrite(lf, 0);
        analogWrite(lb, lspeed); 
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);
          Serial.println("BACK");
    }
    else if (state == 'r') {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
          Serial.println("SR");
    }
    else if (state == 'R') {
        analogWrite(lf, lspeed);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);
          Serial.println("HR");
    }
    else if (state == 'q') {
        analogWrite(lf, 0);
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, rspeed);
          Serial.println("BR");
    }

    else if (state == 's') {
        analogWrite(lf, 0); 
        analogWrite(lb, 0); 
        analogWrite(rf, 0);
        analogWrite(rb, 0);
        //analogWrite(led, 0);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
}
