// Class for ultrasonic sensor use

const double SOUND_SPEED_CM_US = 0.034;

class Ultrasonic_Sensor {
    public:
        Ultrasonic_Sensor(int t, int e): trigger(t), echo(e) {
            pinMode(t, OUTPUT);
            pinMode(e, INPUT);
        }
        double dist_cm();
    private:
        int trigger;
        int echo;
};

double Ultrasonic_Sensor::dist_cm(){
    
    // Pulse sensor to make it read
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    auto time = pulseIn(echo, HIGH); // time is in microseconds
     
    return (time * SOUND_SPEED_CM_US) / 2.0;
}
