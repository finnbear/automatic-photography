#include <Servo.h>

// How many pictures to take
int howMany = 50;

// How long to rotate the turntable per picture
int howLong = 200;

Servo servo;

void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  servo.attach(10);
}

void loop() {
  servo.write(0);
  digitalWrite(11, LOW);
  if (digitalRead(9) == LOW) {
    for (int i = 0; i < howMany; i++) {
      // Rotate the turntable into position
      servo.write(30);
      delay(howLong);
      servo.write(0);
      delay(250);
  
      // Take a picture
      pinMode(8, OUTPUT);
      digitalWrite(8, LOW);
      delay(25);
      pinMode(8, INPUT);
  
      // Wait for the picture
      delay(2000);
    }
  }
}
