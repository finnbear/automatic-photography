#include <Servo.h>

// How many pictures to take
int howMany = 20;

// How long to rotate the turntable per picture
int howLong = 250;

Servo servo;

void setup() {
  pinMode(8, INPUT);
  pinMode(10, OUTPUT);
  
  servo.attach(10);
}

void loop() {
  for (int i = 0; i < howMany; i++) {
    // Rotate the turntable into position
    servo.write(20);
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

  delay(1000 * 60);
}
