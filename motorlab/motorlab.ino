#include <ESP32Servo.h>
#include <Stepper.h>
#include <timer.h>

auto timer = timer_create_default(); // create a timer with default settings

const int stepsPerRevolution = 2038;
const int incrementSteps = 407.6;
Stepper myStepper(stepsPerRevolution, 32, 33, 25, 26);
Servo myServo;  

const int buttonPin = 4;

const int thingOn = 1;
const int thingOff = 0;

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int numZeros = 0;
int firstPress = 1;

int numKnocks = 0;
int sequenceSolved = 0;
int readyToGo = 1;
int placeInSequence = 0;

int puzzleSequence[5] = {1, 2, 3, 4, 5};

int servoPosition = 0;
int stepperRotations = 0;

void setup() {
  myServo.attach(27);
  Serial.begin(115200);
  myStepper.setSpeed(6);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if (sequenceSolved == 1)
  {
    readyToGo = 0;
    for (int i = 0; i < 5; i++){
      puzzleSequence[i] = random(4, 10);
      Serial.print("new random sequence = ");
      Serial.println(puzzleSequence[i]);
    }
    sequenceSolved = 0;
    readyToGo = 1;
  }

  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      if (firstPress == 1)
      {
        numZeros = 0;
        firstPress = 0;
      }
      Serial.println(thingOn, DEC);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println(thingOff, DEC);
    } 
   }
   else 
   {
    numZeros++;
    //Serial.println(thingOff, DEC); 
    Serial.println(numZeros);
   } 

  if (buttonPushCounter == puzzleSequence[placeInSequence])
  {
    buttonPushCounter = 0;
    numZeros = 0;
    firstPress = 1;
    Serial.println("one place solved");
    myStepper.step(incrementSteps);
    if (placeInSequence == 4)
    {
      Serial.println("PUZZLE SOLVED");
      placeInSequence = 0;
      sequenceSolved = 1;
      //myStepper.step(incrementSteps);

    }
    placeInSequence++;
    
  }

  lastButtonState = buttonState;
  // stepper rotates
 // stepperRotations++;
 // servoPosition = (servoPosition + 10) % 180;
  
/* if (numZeros >4000 && firstPress != 1)
 {
  Serial.println("NOWNOWNOWNOWNOWOWN");
  delay(100);
  numZeros = 0;
 } */
 if (numZeros > 5000 && firstPress != 1)
 {
 if (buttonPushCounter < puzzleSequence[placeInSequence])
 {
    servoPosition = map(buttonPushCounter, 0, 1.0, 0, 180);
    //percentage of accuracy mapped to servo range
    myServo.write(servoPosition);
    delay(50);
    servoPosition = 0;
    myServo.write(servoPosition);
 }
 else 
 {
    servoPosition = 180;
    myServo.write(servoPosition);
    delay(50);
    servoPosition = 0;
    myServo.write(servoPosition);
 } 
 }

  // set motor positions
  //myStepper.step(stepsPerRevolution);
  //myServo.write(servoPosition);

  
  
}
