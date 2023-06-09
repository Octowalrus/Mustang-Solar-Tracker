#include <Servo.h>

//photoresistors
const int backPR = A0; 
const int frontPR = A1; 
const int rightPR = A2; 
const int leftPR = A3; 

Servo FRServo;  //Front Right
Servo FLServo;  //Front Left
Servo BRServo;  //Back Right
Servo BLServo;  //Back Left

int tiltFront;
int tiltBack;
int tiltLeft;
int tiltRight;
int tiltFB;
int tiltLR;

int AmountFR = 0;
int AmountFL = 0;
int AmountBR = 0;
int AmountBL = 0;

bool FRStop = false;
bool FLStop = false;
bool BRStop = false;
bool BLStop = false;

void setup() {
  // put your setup code here, to run once:
  FRServo.attach(3);
  FLServo.attach(5);
  BRServo.attach(6);
  BLServo.attach(9);
  FRServo.write(AmountFR);
  FLServo.write(AmountFL);
  BRServo.write(AmountBR);
  BLServo.write(AmountBL);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkTilt();
  adjustServo();
  delay(30000);
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
  tiltFB = tiltFront - tiltBack;
  tiltLR = tiltLeft - tiltRight;
}

void adjustServo()  {
  while(tiltFB > 0)  {
    AmountFR--;
    AmountFL--;
    AmountBR++;
    AmountBL++;
    checkValues();
    FRServo.write(AmountFR);
    FLServo.write(AmountFL);
    BRServo.write(AmountBR);
    BLServo.write(AmountBL);
    checkTilt();
    if()
  }
  while(tiltFB < 0) {
    AmountFR++;
    AmountFL++;
    AmountBR--;
    AmountBL--;
    checkValues();
    FRServo.write(AmountFR);
    FLServo.write(AmountFL);
    BRServo.write(AmountBR);
    BLServo.write(AmountBL);
    checkTilt();
  }
  while(tiltLR > 0) {
    AmountFR++;
    AmountFL++;
    AmountBR--;
    AmountBL--;
    checkValues();
    FRServo.write(AmountFR);
    FLServo.write(AmountFL);
    BRServo.write(AmountBR);
    BLServo.write(AmountBL);
    checkTilt();
  }
  while(tiltLR < 0) {
    AmountFR++;
    AmountFL++;
    AmountBR--;
    AmountBL--;
    checkValues();
    FRServo.write(AmountFR);
    FLServo.write(AmountFL);
    BRServo.write(AmountBR);
    BLServo.write(AmountBL);
    checkTilt();
  }
}

void checkValues(); {
  if(AmountFR > 90)  {
    AmountFR = 90;
    FRStop = true;
  }
  if(AmountFR < 0)  {
    AmountFR = 0);
    FRStop = true;
  }
  if(AmountFL > 90) {
    AmountFL = 90);
    FLStop = true;
  }
  if(AmountFL < 0)  {
    AmountFL = 0;
    FLStop = true;
  }
  if(AmountBR > 90) {
    AmountBR = 90;
    BRStop = true;
  }
  if(AmountBR < 0)  {
    AmountBR = 0;
    BRStop = true;
  }
  if(AmountBL > 90) {
    AmountBL = 90;
    BLStop = true;
  }
  if(AmountBL < 0)  {
    AmountBL = 0;
    BLStop = true;
  }
}
