#include "ultraSonicSensor.h"
const int pinIR=12;

enum Arrows {
    arr_up = 16736925, 
    arr_down = 16754775,
    arr_left = 16720605,
    arr_right = 16761405,
    repeat_char = 4294967295,
    ok_button = 16712445,
    one = 16738455,
    two = 16750695,
    three = 16756815,
    four = 16724175,
    five = 16718055,
    six = 16743045,
    seven = 16716015,
    eight = 16726215,
    nine = 16734885,
    zero = 16730805,
    star = 16728765,
    hash = 16732845,
  };

int ir_reciever(){
  int direction = 0;
  if (irrecv.decode(&results)) {
    if (results.value != Arrows(repeat_char)){
      Serial.println(results.value != Arrows(repeat_char));
      switch (results.value) {
        case arr_up:
          Serial.println("up");
          direction = 1;
          break;
        case arr_down:
          Serial.println("down");
          direction = 2;
          break; 
        case arr_left:
          Serial.println("left");
          direction = 3;
          break;
        case arr_right:
          Serial.println("right");
          direction = 4;
          break;
        case repeat_char:
          direction = 5;
          Serial.println("repeat");
          break;
        case ok_button:
          Serial.println("ok");
          break;
        case one:
          Serial.println("one");
          break;
        case two:
          Serial.println("two");
          break;
        case three:
          Serial.println("three");
          break;
        case four:
          Serial.println("four");
          break;
        case five:
          Serial.println("five");
          break;
        case six:
          Serial.println("six");
          break;
        case seven:
          Serial.println("seven");
          break;
        case eight:
          Serial.println("eight");
          break;
        case nine:
          Serial.println("nine");
          break;
        case zero:
          Serial.println("zero");
          break;
        case star:
          Serial.println("star");
          break;
        case hash:
          Serial.println("hash");
          break;
        default:
          Serial.println(results.value);
      }
    };
    irrecv.resume();
    return direction;
  };


};