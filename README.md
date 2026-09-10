# Obstacle Avoidance RC Car
This project is an Arduino-based smart RC car that can operate in two different modes: Manual Control Mode and Automatic Obstacle Avoidance Mode. The car uses an Ultrasonic Sensor to detect obstacles and a Servo Motor to scan the surrounding area and select a suitable direction.

# 🔹How It Works
- **Automatic Mode**

The Ultrasonic Sensor continuously measures the distance between the car and nearby obstacles. If the path is clear, the car moves forward. When an obstacle is detected within 25 cm, the car stops, and the Servo Motor rotates the Ultrasonic Sensor to scan the left and right sides. The Arduino compares the available distances and selects the best direction to avoid the obstacle. If no clear path is available, the car moves backward.

- **Manual Mode**

The car receives control commands through Serial or Bluetooth communication. The user can control the movement of the car by sending commands to move forward, backward, left, right, or stop. The Arduino processes these commands and controls the DC motors through the L298N Motor Driver.

# 🔹Features
- Dual operating modes: Manual & Automatic
- Automatic obstacle detection and avoidance
- Real-time distance measurement using Ultrasonic Sensor
- Left and right path scanning using Servo Motor
- Automatic direction selection based on available space
- Manual wireless control through Serial/Bluetooth commands
- Motor speed control using PWM
- Forward, backward, left, right, and stop movements

# 🔹Components
- Arduino UNO
- L298N Motor Driver
- DC Motors
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Mode Selection Switch
- Bluetooth Module (HC-05)
- 4WD RC Car Chassis
- 12V Battery
- Jumper Wires

# 🔹Libraries
- [Servo.h](https://docs.arduino.cc/libraries/servo/)

# 🔹Future Enhancements
- Add OLED display for distance and mode visualization
- Add Wi-Fi control using ESP32
- Add Line Following Mode
