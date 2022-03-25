# Module for communication with Arduino over Serial

import serial 
import enum

class Command(Enum):
    READ_US = 1
    READ_IR = 2
    #Add more as needed

class ArduinoComm:
    def __init__():
        self.s = serial.Serial('/dev/ttyACM0', 9600)
        self.s.open()

    def read_byte_from_arduino():
        return self.s.read()

    def read_n_bytes(n):
        return self.s.read(n)

    def write_to_arduino(self,command):
        assert isinstance(command, Command)
        self.s.write(serialize(command))
        response = self.s.readline()
        return response