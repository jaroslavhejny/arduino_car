#include "motor.h";
#include "ultraSonicSensor.h";
#include "myServo.h";
#include "ir_recieve.h";
#include <Servo.h>;
#include <Wire.h>;
#include <IRremote.h>;

Servo myArduServo;
// motor
extern const int  Lpwm_pin;
extern const int  Rpwm_pin;
extern const int pinLB;
extern const int pinLF;
extern const int pinRB;
extern const int pinRF;
int counter = 0;
extern const int pinIR;

// UltraSonic sensor
#define TRIG_PIN A1
#define ECHO_PIN A0
int Ult_distance=0;

// IR
IRrecv irrecv(pinIR);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(pinLB,OUTPUT);
  pinMode(pinLF,OUTPUT);
  pinMode(pinRB,OUTPUT);
  pinMode(pinRF,OUTPUT);
  pinMode(Lpwm_pin,OUTPUT);
  pinMode(Rpwm_pin,OUTPUT); 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myArduServo.attach(A2); 
  irrecv.enableIRIn();
}

void loop() {
  // go_forward(255);
  // delay(1000);
  // stop_motor(1);
  // delay(2000);
  // rotate_servo(1);
  counter = ir_reciever();
  switch (counter) {
    case 1: 
      go_forward(255);
      break;
    case 2:
      go_backward(255);
      break;
    case 3: 
      rotate_left(255);
      break;
    case 4:
      rotate_right(255);
      break;
    case 5:
      go_forward(255);
      break;
    default:
      // stop_motor(1);
      break;
  }
  if (Ult_distance < 30){
      Serial.println(Ult_distance);
      // stop_motor(1);
  }

}
