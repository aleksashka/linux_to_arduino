#!/usr/bin/python
import serial, time
ard = serial.Serial('/dev/ttyUSB0', baudrate=9600, timeout=1)

#TODO Check if arduino ready by bidirectional communication:
# e.g. send 0xFF, until 0xFF is received
#TODO Check if extra bytes is processed fine
time.sleep(2)

#ard.write(bytes([0, 4]))
#ard.write(bytes([40]))
#ard.write(bytearray([0,4,2,0,255,255]));
ard.write(bytearray([0,4,2,0,255,255,0,4,2]));
time.sleep(1);
ard.write(bytearray([0,4,2,0,255,255,0,4,2]));
#print (str(ard.read()))
