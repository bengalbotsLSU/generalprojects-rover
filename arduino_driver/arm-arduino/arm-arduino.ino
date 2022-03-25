#include <Servo.h>

// Various Settings
#define serialDataRate 9600

// Servo Pins
#define servoPinTurret 3 // A
#define servoPinLowerArm 5 // B
#define servoPinUpperArm 6 // C
#define servoPinArmRotation 9 // D
#define servoPinWrist 10 // E
#define servoPinWristRotation 11 // F

// Servos
Servo turret;
Servo lowerArm;
Servo upperArm;
Servo armRotation;
Servo wrist;
Servo wristRotation;


void setup() {
  // Attach the Servos
  turret.attach(servoPinTurret);
  lowerArm.attach(servoPinLowerArm);
  upperArm.attach(servoPinUpperArm);
  armRotation.attach(servoPinArmRotation);
  wrist.attach(servoPinWrist);
  wristRotation.attach(servoPinWristRotation);

  // Open the Serial Port
  Serial.begin(serialDataRate);
}

void loop() {
  // Check for Serial Data in Buffer
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');

    processCommand(command);
  }
}

void processCommand(String cmd) {
  Serial.println("RECEVIED " + cmd);

  char id = cmd.charAt(0);
  int position = cmd.substring(1).toInt();

  setArmPosition(id, position);
}

void setArmPosition(char servoID, int position) {
  switch (servoID) {
    case 'A':
      turret.write(position);
      break;
    case 'B':
      lowerArm.write(position);
      break;
    case 'C':
      upperArm.write(position);
      break;
    case 'D':
      armRotation.write(position);
      break;
    case 'E':
      wrist.write(position);
      break;
    case 'F':
      wristRotation.write(position);
      break;
    default:
      Serial.println("ERROR Invalid arm servo id of " + String(servoID));
      break;
  }
}
