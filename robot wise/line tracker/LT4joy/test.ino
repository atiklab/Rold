void time_test()
{
  mway3(cspeed,-cspeed);
    delay(tm);
    mway3(0,0);
    delay(50);


    mway3(-cspeed,cspeed);
    delay(2*tm);
    mway3(0,0);
    delay(50);


    mway3(cspeed,-cspeed);
    delay(tm+10);
    mway3(0,0);
    //delay(50);

  }

  //      state = Serial.read(); 
//       flag=0;  
//      //digitalWrite(13, HIGH);
//
//
//   
//           if (state == '0') mspeed=0;
//      else if (state == '1') mspeed=90;
//      else if (state == '2') mspeed=150;
//      else if (state == '3') mspeed=190;
//      else if (state == '4') mspeed=220;
//      else if (state == '5') mspeed=255;
//      else if (state == 'F') mway3(mspeed,mspeed);
//      else if (state == 'B') mway3(-mspeed,-mspeed);
//      else if (state == 'R') mway3(mspeed,-mspeed);
//      else if (state == 'L') mway3(-mspeed,mspeed);
//      else if (state == 'S') mway3(0,0);  
//      else if (state == 'G') mway3(0,mspeed);
//      else if (state == 'H') mway3(-mspeed,0);
//      else if (state == 'I') mway3(mspeed,0);
//      else if (state == 'J') mway3(0,-mspeed);
//
//
//
//       else if (state == 'a'){
//         if (val<170)
//         val = val + 10;
//         myservo1.write(val);
//          digitalWrite(13, HIGH);
//         Serial.print(val);
//          Serial.println("Up");
//          flag=1;
//          delay(40);
//       
//       }
//      else if (state == 'b') {
//        if (val>10)
//        val = val - 10;
//        myservo1.write(val);
//         digitalWrite(13, LOW);
//          Serial.print(val);
//          Serial.println("Down");
//          flag=1;
//           delay(40);
//        
//      }
//             else if (state == 'c'){
//         if (val2<170)
//         val2 = val2 + 10;
//         myservo.write(val2);
//         Serial.print(val2);
//          Serial.println("Up");
//          flag=1;
//          delay(40);
//       
//       }
//      else if (state == 'd') {
//        if (val2>10)
//        val2 = val2 - 10;
//        myservo.write(val2);
//          Serial.print(val2);
//          Serial.println("Down");
//          flag=1;
//           delay(40);
//        
//      }
//        
//
//
//

