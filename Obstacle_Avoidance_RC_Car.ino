// =========[LIBRARIES]=========
#include <Servo.h>

// =========[VARIABLES & DATA TYPE]=========
// L298N Motor Driver
#define ENA 6
#define ENB 3
#define IN1 7
#define IN2 5
#define IN3 4
#define IN4 2

// Switch
#define SwitchMode 9

// Ultrasonic
#define TRIG 12
#define ECHO 11

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(SwitchMode, INPUT_PULLUP);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  myServo.attach(10);
  myServo.write(90);
  stopCar();

}

void loop() {
  if(digitalRead(SwitchMode) == LOW) // AUTOMATIC OBSTACLE AVOIDANCE
  {
    automaticMode();
  }
  else if(digitalRead(SwitchMode) == HIGH) // MANUAL RC CAR
  {
    manualMode();
  }
}

// =========[MODE FUNCTIONS]=========
// Obstacle Avoidance - Automatic
void automaticMode()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long Duration = pulseIn(ECHO, HIGH);
  int  Distance = Duration / 58;

  Serial.print("Distance: ");
  Serial.println(Distance);

  if (Distance > 25)
  {
    moveForward();
  }
  else
  {
    stopCar();
    delay(200);

    // Check Left;
    myServo.write(150);
    delay(500);
    int leftDistance = Distance;

    // Check Right;
    myServo.write(30);
    delay(500);
    int rightDistance = Distance;

    // Move to center again
    myServo.write(90);
    delay(200);
    if (leftDistance > rightDistance && leftDistance > 25)
    {
      moveLeft();
      delay(300);
    }
    else if (rightDistance > leftDistance)
    {
      moveRight();
      delay(300);
    }
    else
    {
      moveBackward();
      delay(1000);
    }
    stopCar();
  }
}

// RC Car - Manual
void manualMode()
{
  if (Serial.available()) {
    char cmd = Serial.read();

    if(cmd == 'F')
    {
      moveForward();
    }
    else if (cmd == 'B')
    {
      moveBackward();
    }
    else if (cmd == 'L')
    {
      moveLeft();
    }
    else if (cmd == 'R')
    {
      moveRight();
    }
    else if (cmd == 'S')
    {
      stopCar();
    }
  }
}

// =========[MOTOR FUNCTIONS]=========
void moveForward()
{
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward()
{
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveLeft() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}