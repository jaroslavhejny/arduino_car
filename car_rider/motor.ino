#include "motor.h"
const int Lpwm_pin=5;
const int Rpwm_pin=6;
const int pinLB=2;  
const int pinLF=4;             //pin of controlling turning---- IN2 of motor driver board
const int pinRB=7;            //pin of controlling turning---- IN3 of motor driver board
const int pinRF=8;   

void go_forward(unsigned char speed_val) {  // speed_val：0~255
  digitalWrite(pinRB, HIGH);
  digitalWrite(pinRF, LOW);
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinLF, LOW);
  // analogWrite(Lpwm_pin, speed_val);
  // analogWrite(Rpwm_pin, speed_val);
}

void go_backward(unsigned char speed_val) {
  digitalWrite(pinRB, LOW);
  digitalWrite(pinRF, HIGH);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLF, HIGH);
  analogWrite(Lpwm_pin, speed_val);
  analogWrite(Rpwm_pin, speed_val);
}

void rotate_left(unsigned char speed_val) {
  digitalWrite(pinRB, HIGH);
  digitalWrite(pinRF, LOW);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLF, HIGH);
  analogWrite(Lpwm_pin, speed_val);
  analogWrite(Rpwm_pin, speed_val);
}
void rotate_right(unsigned char speed_val) {
  digitalWrite(pinRB, LOW);
  digitalWrite(pinRF, HIGH);
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinLF, LOW);
  analogWrite(Lpwm_pin, speed_val);
  analogWrite(Rpwm_pin, speed_val);
}
void stop_motor(unsigned char speed_val) {
  digitalWrite(pinRB, LOW);
  digitalWrite(pinRF, LOW);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLF, LOW);
}