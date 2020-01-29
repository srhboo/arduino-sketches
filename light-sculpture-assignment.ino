// BUTTON
const int buttonPin = 2;
const int buttonValueWhenPressed = LOW; // two pin button

// MEGA BULB 1
// super bright RGB led
int one_brightRedPin = 7;
int one_brightGreenPin = 8;
int one_brightBluePin = 9;

int one_bigRedPin = 6;
int one_smallOrangePin;

// MEGA BULB 2
int two_orangeAPin = 3;
int two_orangeBPin = 4;
int two_bluePin = 5;

// MEGA BULB 3
int three_bigOrangePin = 10;

// define pins to involve in fading per mode
int twoModePins[] = {two_orangeAPin, two_bluePin};
int threeModePins[] = {three_bigOrangePin};

// MODES
int currentModeIndex = 0;
String modes[] = {"off", "all", "harmony"};

int buttonState = 1; // variable for reading if button is pushed

void setup()
{
  pinMode(buttonPin, INPUT);     // set up button
  digitalWrite(buttonPin, HIGH); // two pin button, set up with pullup enabled

  // setup MEGA BULB 1
  pinMode(one_brightRedPin, OUTPUT);
  pinMode(one_brightGreenPin, OUTPUT);
  pinMode(one_brightBluePin, OUTPUT);
  pinMode(one_bigRedPin, OUTPUT);

  // setup MEGA BULB 2
  pinMode(two_orangeAPin, OUTPUT);
  pinMode(two_orangeBPin, OUTPUT);
  pinMode(two_bluePin, OUTPUT);

  // setup MEGA BULB 3
  pinMode(three_bigOrangePin, OUTPUT);
}

void loop()
{
  int buttonReading = digitalRead(buttonPin);
  if (buttonReading == buttonValueWhenPressed && buttonReading != buttonState)
  { // check if button has been pressed to switch mode, also prevent double switching if held down
    buttonState = buttonReading; // update the button state to check per loop
    currentModeIndex = (currentModeIndex + 1) % 3; // go to next mode, loop around if end is reached
  }

  // do different light program based on mode
  if (modes[currentModeIndex] == "off")
  {
    turnOff();
  }
  else if (modes[currentModeIndex] == "all")
  {
    allOn();
  }
  else
  {
    harmony();
  }
}

// fade code taken from arduino example
void slowFadeIn(int ledsToBrighten[], int numberOfLeds)
{
  // slowly fade in all listed leds
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 3)
  {
    for (int currentLed = 0; currentLed < numberOfLeds; currentLed++)
    {
      analogWrite(ledsToBrighten[currentLed], fadeValue);
      delay(50);
    }
  }
}

void slowFadeOut(int ledsToDim[], int numberOfLeds)
{
  // slowly dim all listed leds
  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5)
  {
    for (int currentLed = 0; currentLed < numberOfLeds; currentLed++)
    {
      analogWrite(ledsToDim[currentLed], fadeValue);
      delay(30);
    }
  }
}

void turnOff()
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void allOn()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}

void harmony()
{
  //purple
  analogWrite(one_brightRedPin, 200);
  analogWrite(one_brightBluePin, 100);
  digitalWrite(one_brightGreenPin, LOW);
  delay(1000);

  // lime
  analogWrite(one_brightRedPin, 255);
  analogWrite(one_brightGreenPin, 150);
  digitalWrite(one_bigRedPin, HIGH);
  delay(1000);

  // light blue
  analogWrite(one_brightGreenPin, 150);
  analogWrite(one_brightBluePin, 150);
  digitalWrite(one_brightRedPin, LOW);
  delay(1000);

  slowFadeIn(threeModePins, 1);
  slowFadeIn(twoModePins, 2);
  slowFadeOut(twoModePins, 2);
  slowFadeOut(threeModePins, 1);
}
