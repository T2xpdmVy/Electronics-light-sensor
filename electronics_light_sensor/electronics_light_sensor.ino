#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards
//array Values = [180,0,90]
int pos = 0;    // variable to store the servo position
void move_to(int degree, int wait = 1.83333333333) { // new function to add delay and move the panel without need to write a for loop every time
  int change_in_degrees = degree - myservo.read();
  for (int pos = 0; pos <= change_in_degrees; pos +=change_in_degrees/abs(change_in_degrees) ) {
    myservo.write(pos);
    delay(wait);
  }
}
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}


void loop() {// can someone run this and test it
  move_to(90);
  move_to(180);
  move_to(270);
  move_to(360);
  move_to(0);
}
