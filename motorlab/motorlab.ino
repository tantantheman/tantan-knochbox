#include <ESP32Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 2038;
Stepper myStepper(stepsPerRevolution, 32, 33, 25, 26);
Servo myServo;  

int servoPosition = 0;
int stepperRotations = 0;

void setup() {
  myServo.attach(27);
  Serial.begin(115200);
  myStepper.setSpeed(6);
}

void loop(){

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
