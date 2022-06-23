#include "myServo.h"


 int pos = 0;
void rotate_servo(int x) {
   // myArduServo.write(270);
  
  for (pos = 0; pos <= 180; pos += 1) {
    myArduServo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myArduServo.write(pos);
    delay(15);
  }
}

void stop_servo(int x){
  myArduServo.write(pos);
}