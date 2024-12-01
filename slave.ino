void setup() {
  Serial.begin(9600); // Start hardware Serial for HC-05 communication
  Serial.println("Slave ready. Waiting for joystick input...");
}

void loop() {
  if (Serial.available()) { // Check for incoming data from HC-05
    String receivedData = Serial.readStringUntil('\n'); // Read data until newline
    Serial.println("Joystick Direction: " + receivedData); // Print received data
  }
}
