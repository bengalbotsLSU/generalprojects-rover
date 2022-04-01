# Module for communication with Arduino over Serial

import serial 
import enum
import sys
import struct 

class Command(enum.Enum):
    READ_US = 1
    READ_IR = 2
    #Add more as needed

class ArduinoComm:
    def __init__(self):
        self.s = serial.Serial('/dev/ttyACM0', 9600)

    def read_byte_from_arduino():
        return self.s.read()

    def read_n_bytes(n):
        return self.s.read(n)

    def write_to_arduino(self,command):
        assert isinstance(command, Command)
        self.s.write(struct.pack('>B',command.value))
        response = self.s.readline()
        return response