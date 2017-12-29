#include <Servo.h>

int shots = 36;

int howMany = 20;
int howLong = 250;


Servo servo;

void setup() {
  pinMode(8, INPUT);
  pinMode(10, OUTPUT);
  
  servo.attach(10);
}

void loop() {
  for (int i = 0; i < howMany; i++) {
    servo.write(20);
    delay(howLong);
    servo.write(0);
    delay(250);

    pinMode(8, OUTPUT);
    digitalWrite(8, LOW);
    delay(25);
    pinMode(8, INPUT);
    
    delay(2000);
  }

  delay(1000 * 60);
}
