/*
  Blink- Wack A Mole
  by Sara Artese
*/

#include "Timer.h"

Timer t;

int randNumber;
int score;

// constants won't change. They're used here to set pin numbers:
const int buttonRed = 4;     // the number of the pushbutton pin
const int ledRed =  11;     // the number of the LED pin

const int buttonYellow = 2;     
const int ledYellow =  9;      

const int buttonGreen = 0;     
const int ledGreen =  7; 

// variables will change:
int buttonStateRed = 0;         // variable for reading the pushbutton status
int buttonStateYellow = 0; 
int buttonStateGreen = 0; 

void setup() {
  // initialize the red pins:
  pinMode(ledRed, OUTPUT);
  pinMode(buttonRed, INPUT);

  // initialize the yellow pins:
  pinMode(ledYellow, OUTPUT);
  pinMode(buttonYellow, INPUT);

  // initialize the green pins:
  pinMode(ledGreen, OUTPUT);
  pinMode(buttonGreen, INPUT);
  
  score = 0;
  t.every(2000, moleMove,10);
  t.after(20000, endGame);
}

void loop() {
  t.update();
  
  // read the state of the pushbutton value:
  buttonStateRed = digitalRead(buttonRed);
  buttonStateYellow = digitalRead(buttonYellow);
  buttonStateGreen = digitalRead(buttonGreen);

  // check if the pushbutton is pressed:
  if (buttonStateRed == HIGH) {
    // turn LED off:
      digitalWrite(ledRed, LOW);
  } 
   if (buttonStateYellow == HIGH) {
    // turn LED off:
      digitalWrite(ledYellow, LOW);
      
  } 
   if (buttonStateGreen == HIGH) {
      // turn LED off:
      digitalWrite(ledGreen, LOW); 
  } 

}


void moleMove()
{
  randNumber = random(6);
  Serial.println(randNumber);
  
  if (randNumber == 0) {
    // turn LED on:
    digitalWrite(ledRed, HIGH);
  } 
   if (randNumber == 2) {
    // turn LED on:
    digitalWrite(ledYellow, HIGH);
  }
   if (randNumber == 1) {
    // turn LED on:
    digitalWrite(ledGreen, HIGH);
  }
  if (randNumber == 3) {
    // turn LED on:
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, HIGH);
  }
  if (randNumber == 4) {
    // turn LED on:
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH);
  }
  if (randNumber == 5) {
    // turn LED on:
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, HIGH);
  }
}

void endGame(){
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, HIGH);
  }

