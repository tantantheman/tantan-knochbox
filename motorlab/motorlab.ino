#include <ESP32Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 2038;
Stepper myStepper(stepsPerRevolution, 32, 33, 25, 26);
Servo myServo;  

int numKnocks = 0;
int sequenceSolved = 0;

int puzzleSequence[5] = {1, 2, 3, 4, 5};

int servoPosition = 0;
int stepperRotations = 0;

void setup() {
  myServo.attach(27);
  Serial.begin(115200);
  myStepper.setSpeed(6);
}

void loop(){

  if (sequenceSolved == 1)
  {
    for (int i = 0; i < 5; i++){
      puzzleSequence[i] = random(1, 5);
    }
  }
  
  // stepper rotates
  stepperRotations++;
  servoPosition = (servoPosition + 10) % 180;

  // log values
  Serial.print(stepperRotations);
  Serial.print(',');
  Serial.println(servoPosition);

  // set motor positions
  myStepper.step(stepsPerRevolution);
  myServo.write(servoPosition);
  
}
