 // Include the capacitive touch library
#include <CapacitiveSensor.h>

// Include the servo motor library
#include <Servo.h>

// Set pin 2 as send and pin 4 as receive
CapacitiveSensor touch = CapacitiveSensor(2, 4);

// Create the servo object
Servo myservo;

// Set the touch threshold
long threshold = 1000;

// Remember whether the sensor was touched
bool wasTouched = false;

// Run once when Arduino starts
void setup() {
  // Start Serial Monitor
  Serial.begin(9600);

  // Connect the servo to pin 9
  myservo.attach(9);

  // Start with the door closed
  myservo.write(0);
}

// Repeat continuously
void loop() {
  // Read the capacitive touch sensor
  long value = touch.capacitiveSensor(30);

  // Print the sensor reading
  Serial.println(value);

  // Check whether the sensor is touched
  bool isTouched = value > threshold;

  // Check for a new touch
  if (isTouched && !wasTouched) {

    // Move the servo to 90 degrees
    myservo.write(90);

    // Print door status
    Serial.println("Door Open");

    // Keep the door open for 3 seconds
    delay(3000);

    // Move the servo back to 0 degrees
    myservo.write(0);

    // Print door status
    Serial.println("Door Closed");
  }

  // Save the current touch state
  wasTouched = isTouched;

  // Wait 50 milliseconds before reading again
  delay(50);
}
