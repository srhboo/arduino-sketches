int redLed = 10;
int yellowLed = 9;
int greenLed = 8;
int buttonSwitch = 11;
int lightSensor = 5;
int lightReading;

void setup() {
  Serial.begin(9600);
  // red LED on pin 10
  pinMode(redLed, OUTPUT);
  // yellow LED on pin 9
  pinMode(yellowLed, OUTPUT);
  // green LED on pin 8
  pinMode(greenLed, OUTPUT);
  // button on pin 11
}

void loop() {
  Serial.println(digitalRead(buttonSwitch));
  if (digitalRead(buttonSwitch) == HIGH) {
  // if button is pressed, read light sensor and turn on an LED
    lightReading = analogRead(lightSensor);
    // get the reading
    if(lightReading >= 880) {
      // if there's lots of light turn on red LED and turn off the others
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, LOW);
    } else if (lightReading < 900 && lightReading >= 750) {
      // if there's medium light turn on yellow LED and turn off the others
      digitalWrite(yellowLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
    } else {
      // if there's low light turn on green LED and turn off the others
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
    }
  } else {
    // if button is not pressed, do a blinking pattern
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(yellowLed, HIGH);
    delay(500);
    digitalWrite(greenLed, HIGH);
    delay(1000);
    digitalWrite(redLed, LOW);
    delay(500);
    digitalWrite(yellowLed, LOW);
    delay(500);
    digitalWrite(greenLed, LOW);
    delay(500);
    delay(1000);
  }
  
}