# autonomous_assistiveRobot
An Arduino-based autonomous robot system that actively detects and avoids obstacles using ultrasonic sensors and DC motors. This project integrates real-time decision-making using sensor fusion and is designed to be expanded with ESP32-based Bluetooth app control.

---

## Project Overview

The robot uses three ultrasonic sensors (front, left, right) to detect objects in its surroundings. Depending on the sensor readings, it decides whether to move forward, turn left/right, or reverse. Directional LEDs indicate the movement chosen by the robot. The robot is driven by two DC motors connected via an L298N motor driver and controlled using PWM output.

---

## Key Hardware Components

| Component            | Description                        |
|----------------------|------------------------------------|
| Arduino Uno R4       | Main controller (motor + sensors)  |
| ESP32 (optional)     | For wireless app control           |
| 3x Ultrasonic Sensors| Proximity detection (front/side)   |
| L298N Motor Driver   | Dual H-bridge DC motor controller  |
| 2x DC Motors         | Differential drive robot movement  |
| 4x LEDs              | Indicate robot direction           |
| Power Supply         | 7–12V Li-Ion battery or DC source  |

---

## Pin Configuration

### Motor Driver (L298N)
| Motor Driver Pin | Arduino Pin |
|------------------|-------------|
| ENA (PWM)        | D10         |
| IN1              | D7          |
| IN2              | D8          |
| IN3              | D12         |
| IN4              | D13         |
| ENB (PWM)        | D9          |

### Ultrasonic Sensors
| Sensor Position | Trig Pin | Echo Pin |
|-----------------|----------|----------|
| Front           | D2       | D3       |
| Left            | D4       | D5       |
| Right           | D6       | D7       |

### Movement LEDs
| LED             | Arduino Pin |
|-----------------|-------------|
| Forward LED     | D5          |
| Left LED        | D4          |
| Right LED       | D3          |
| Backward LED    | D2          |


---

## Features
- Uses real-time distance detection for pathfinding.
- Autonomous motor control logic.
- Directional LED indicators.
- UART-based communication between Arduino and ESP32 (for Bluetooth app control).

---
# Images 
<img width="622" height="606" alt="Screenshot 2025-10-11 233840" src="https://github.com/user-attachments/assets/d0220dc5-0b2a-4c5b-90dc-811da15915e3" />

![IMG_20251011_142205](https://github.com/user-attachments/assets/4a66f096-8cba-4063-8b2d-a4442790d8a7)
