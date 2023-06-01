#include <Servo.h>

const int backPR = A0; 
const int frontPR = A1; 
const int rightPR = A2; 
const int leftPR = A3; 

Servo backServo;
Servo frontServo;
Servo rightServo;
Servo leftServo;

int tiltFront;
int tiltBack;
int tiltLeft;
int tiltRight;

void setup() {
  // put your setup code here, to run once:
  backServo.attach(3);
  frontServo.attach(5);
  rightServo.attach(6);
  leftServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  

}

void checkTilt()  {
  tiltFront = analogRead(frontPR);
  tiltFront = map(tiltFront, 0, 1023, 0, 10);
  tiltBack = analogRead(backPR);
  tiltBack = map(tiltBack, 0, 1023, 0, 10);
  tiltLeft = analogRead(leftPR);
  tiltLeft = map(tiltLeft, 0, 1023, 0, 10);
  tiltRight = analogRead(rightPR);
  tiltRight = map(tiltRight, 0, 1023, 0, 10);
}