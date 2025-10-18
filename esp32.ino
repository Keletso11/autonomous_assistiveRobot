#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

// --- Ultrasonic pins ---
int trigFront =14;
int echoFront =27;
int trigLeft =26;
int echoLeft =25;
int trigRight =33;
int echoRight =32;

// --- Safety threshold ---
const int safeDistance = 20; // in cm

void setup() {
  Serial.begin(9600);          // UART to Arduino Nano
  SerialBT.begin("AssistBot"); // Bluetooth name
  Serial.println("ESP32 Bluetooth ready. Connect to 'AssistBot'.");

  // Setup ultrasonic pins
  pinMode(trigFront, OUTPUT);
  pinMode(echoFront, INPUT);
  pinMode(trigLeft, OUTPUT);
  pinMode(echoLeft, INPUT);
  pinMode(trigRight, OUTPUT);
  pinMode(echoRight, INPUT);
}

void loop() {
  // Bluetooth Command Control
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.write(command); // Send to Arduino Nano
    Serial.print("Sent to Arduino: ");
    Serial.println(command);
  }

  // Check distance automatically
  int front = readUltrasonic(trigFront, echoFront);
  int left = readUltrasonic(trigLeft, echoLeft);
  int right = readUltrasonic(trigRight, echoRight);

  // Automatic stop or avoidance
  if (front < safeDistance && front > 0) {
    Serial.write('S'); // Stop robot
    SerialBT.println("Obstacle detected ahead!");
    delay(500);

    // Choose turn direction based on space
    if (left > right) {
      Serial.write('L'); // Turn left
      SerialBT.println("Turning left to avoid obstacle");
      delay(3000);
    } else {
      Serial.write('R'); // Turn right
      Serial.println("turning right to avoid obstacle");
      delay(3000);
    }
    Serial.write('F'); // Continue forward after turn
  }

  //  feedback from Arduino → phone
  if (Serial.available()) {
    char c = Serial.read();
    SerialBT.write(c);
  }

  delay(100); // Small delay to prevent flooding
}

// --- Function to read ultrasonic distance ---
int readUltrasonic(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 20000); // Timeout after 20ms
  if (duration == 0) return 999; // No reading
  int distance = duration * 0.034 / 2;
  return distance;
}
