# Main file for pi

import arduino_comm

ard_comm = arduino_comm.ArduinoComm()
while (True):
    print(ard_comm.write_to_arduino(arduino_comm.Command.READ_US))