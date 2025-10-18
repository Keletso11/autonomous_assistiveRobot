// Motor driver pins
int ENA = 10;
int IN1 = 7;
int IN2 = 8;
int IN3 = 12;
int IN4 = 13;
int ENB = 9;

// LED pins
int ledForward = 2;
int ledBackward = 5;
int ledLeft = 3;
int ledRight = 4;

void setup() {
  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // LED pins
  pinMode(ledForward, OUTPUT);
  pinMode(ledBackward, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);

  Serial.begin(9600); // Communication with ESP32
}

void loop() {
  // Wait for command from ESP32 (Bluetooth control or autonomous)
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }
}

// Execute motor + LED actions
void executeCommand(char cmd) {
  stopMotors(); // Stop first before changing direction

  switch (cmd) {
    case 'F': // Forward
      moveForward();
      digitalWrite(ledForward, HIGH);
      break;

    case 'B': // Backward
      moveBackward();
      digitalWrite(ledBackward, HIGH);
      break;

    case 'L': // Turn Left
      turnLeft();
      digitalWrite(ledLeft, HIGH);
      break;

    case 'R': // Turn Right
      turnRight();
      digitalWrite(ledRight, HIGH);
      break;

    case 'S': // Stop
      stopMotors();
      break;

    default:
      stopMotors();
      break;
  }

  // Turn off all LEDs after 3 seconds
  delay(3000);
  digitalWrite(ledForward, LOW);
  digitalWrite(ledBackward, LOW);
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, LOW);
}

// Motor control functions
void moveForward() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
