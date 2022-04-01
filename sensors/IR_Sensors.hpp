// Class for infared sensors

int isObstacle = HIGH;

class IR_Sensor {
  public:
    IR_Sensor (int obstaclePin): obstaclePin(obstaclePin) {
      pinMode(obstaclePin, INPUT);
    }
    bool isObs(obstaclePin);
};

bool IR_Sensor::isObs(int obstaclePin) {
  isObstacle = digitalRead(obstaclePin); // Reads Sensor Pin
  if (isObstacle == LOW){ // Returns true if pin read obstacle
    return true;
  }
  return false; // Returns false if no obstace is read
}