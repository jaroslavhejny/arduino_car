#include "motor.h";
#include "ultraSonicSensor.h";
#include "myServo.h";
#include "ir_recieve.h";
#include <Servo.h>;
#include <Wire.h>;
#include <IRremote.h>;

Servo myArduServo;
// motor
extern const int Lpwm_pin;
extern const int Rpwm_pin;
extern const int pinLB;
extern const int pinLF;
extern const int pinRB;
extern const int pinRF;
int counter = 0;
extern const int pinIR;
unsigned long startTime;
unsigned long currentTime;
bool dir = true;


// UltraSonic sensor
#define TRIG_PIN A1
#define ECHO_PIN A0
int Ult_distance = 100;

// IR
IRrecv irrecv(pinIR);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(pinLB, OUTPUT);
  pinMode(pinLF, OUTPUT);
  pinMode(pinRB, OUTPUT);
  pinMode(pinRF, OUTPUT);
  pinMode(Lpwm_pin, OUTPUT);
  pinMode(Rpwm_pin, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myArduServo.attach(A2);
  irrecv.enableIRIn();
};

void loop() {
  currentTime = millis();
  // Ult_distance = checkdistance();
  counter = ir_reciever();
  switch (counter) {
    case 1:
      // arr up
      go_forward(255);
      break;
    case 2:
      // arr down
      go_backward(255);
      break;
    case 3:
      // arr left
      rotate_left(255);
      break;
    case 4:
      // arr right
      rotate_right(255);
      break;
    case 5:
      // repeat button
      break;
    case 6:
      // star
      rotate_servo_exact(0);
      break;
    case 7:
      // hash
      rotate_servo_exact(180);
      break;
    case 8:
      // zero
      rotate_servo_exact(90);
      break;
    default:
      stop_motor(1);
      break;
  }
  /*
  if (Ult_distance == 30) {
    Serial.println("ult distance"); Serial.print(Ult_distance);
    stop_motor(1);
    counter = 0;
  }
  */
};