#include <AFMotor.h>  // Includes Adafruit Motor Shield library to control DC motors

// Defining input pins connected to the line sensors
#define lefts A4    // Left sensor is connected to analog pin A4
#define rights A5   // Right sensor is connected to analog pin A5

// Creating motor objects for two DC motors (channels M3 and M4 on the shield)
AF_DCMotor motor1(4, MOTOR12_8KHZ);  // Motor 1 on port M4 with 8kHz PWM frequency
AF_DCMotor motor2(3, MOTOR12_8KHZ);  // Motor 2 on port M3 with 8kHz PWM frequency
/*
  Alternative motor assignments (commented out)
  AF_DCMotor motor1(3, MOTOR12_8KHZ); 
  AF_DCMotor motor2(4, MOTOR12_8KHZ);
*/

void setup() {
  // Set the initial speed for both motors (range 0–255)
  motor1.setSpeed(200);
  motor2.setSpeed(200);

  // Define sensor pins as input
  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);

  // Initialize serial communication to monitor sensor values
  Serial.begin(9600);
}

void loop() {
  // Continuously read and print sensor values for debugging
  Serial.println(analogRead(lefts));   // Output left sensor value
  Serial.println(analogRead(rights));  // Output right sensor value

  // Condition 1: Both sensors detect the line (value <= 400)
  if (analogRead(lefts) <= 400 && analogRead(rights) <= 400) {
    // Stop both motors
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }

  // Condition 2: Only the left sensor detects the line
  else if (analogRead(lefts) <= 400 && !(analogRead(rights) <= 400)) {
    // Turn left (left wheel backward, right wheel forward)
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    /*
      Alternative turning method:
      motor1.run(RELEASE);
      motor2.run(FORWARD);
    */
  }

  // Condition 3: Only the right sensor detects the line
  else if (!(analogRead(lefts) <= 400) && analogRead(rights) <= 400) {
    // Turn right (left wheel forward, right wheel backward)
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    /*
      Alternative turning method:
      motor1.run(FORWARD);
      motor2.run(RELEASE);
    */
  }

  // Condition 4: Neither sensor detects the line
  else if (!(analogRead(lefts) <= 400) && !(analogRead(rights) <= 400)) {
    // Move straight ahead (both motors forward)
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    /*
      Alternative direction (if needed):
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
    */
  }
}
