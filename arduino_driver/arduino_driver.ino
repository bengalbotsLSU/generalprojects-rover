// Driver code for arduino

#include "sensors/Ultrasonic_Sensor.hpp"
#include "sensors/pi_comm.hpp"

//TODO: edit
const int trigger_pin = 0;
const int echo_pin = 1;

Ultrasonic_Sensor u_sensor(trigger_pin, echo_pin);

void handle_command(byte command);
bool validate(byte command);

void setup(){
    Serial.begin(9600);
}

void loop() {   
    auto command = read_command();
    Serial.println(command);
    if (validate(command)) {
        handle_command(command);
    }
}

bool validate(byte command) {
    return command > 0 && command < BAD_COMMAND;
}

void handle_command(byte command){
    switch (command) {
        case READ_US: {
            auto res = u_sensor.dist_cm();
            Serial.println(res);
            break;
        }
        case READ_IR: {
            // IR Stuff needs to be merged in
        }
        case TURRET_ROTATE: {
            
        }
        default: {} // fall through
    }
}
