// Module for Arduino to receive commands from Pi

enum Command { // match the python form, add new commands BEFORE BAD_COMMAND
    READ_US = 1,
    READ_IR = 2,
    TURRET_ROTATE,
    LOWER_ARM_ROTATE,
    MID_ARM_ROTATE,
    UPPER_ARM_ROTATE,
    WRIST_A_ROTATE,
    WRIST_B_ROTATE,
    BAD_COMMAND
};

byte read_command() {
    if(Serial.available()) {
        return Serial.read();
    }
    return BAD_COMMAND;
}

