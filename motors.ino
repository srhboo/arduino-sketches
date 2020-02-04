#include <Servo.h>

Servo myservo;
int pos = 0; // default servo position
int buttonPin = 10; // pin for the button

void setup() {
 pinMode(11, OUTPUT); // DC motor pin
 pinMode(12, OUTPUT); // DC motor pin
 pinMode(buttonPin, INPUT); // button pin
 myservo.attach(9); // servo motor pin
}

void loop() {
  // if the button is pressed, do a cycle of servo motor sweep
  if (digitalRead(buttonPin) == HIGH)
  {
    digitalWrite(12, LOW); // make sure DC motor is not spinning

    // taken from arduino example sweep
    for (pos = 0; pos <= 180; pos += 1)
    {                                  // goes from 0 degrees to 180 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else {
    // if the button is not pressed, spin the DC motor
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
}