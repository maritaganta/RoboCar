// Joystick pins
const int joystickX = A0;
const int joystickY = A1;
const int joystickButton = 2; // Button pin

void setup() {
  Serial.begin(9600); // Start hardware Serial for HC-05 communication
  pinMode(joystickX, INPUT);
  pinMode(joystickY, INPUT);
  pinMode(joystickButton, INPUT_PULLUP); // Use pull-up resistor for button
  Serial.println("Master ready.");
}

void loop() {
  int xValue = analogRead(joystickX);
  int yValue = analogRead(joystickY);
  bool buttonPressed = !digitalRead(joystickButton); // Inverted logic due to pull-up
  String direction = "";

  // Determine direction
  if (yValue > 800) direction = "UP";
  else if (yValue < 200) direction = "DOWN";
  else if (xValue > 800) direction = "RIGHT";
  else if (xValue < 200) direction = "LEFT";
  else direction = "CENTER";

  // Add button status to the output
  if (buttonPressed) {
    direction += " + BUTTON";
  }

  // Send direction over Bluetooth
  Serial.println(direction);
  delay(200); // Adjust delay as needed
}
