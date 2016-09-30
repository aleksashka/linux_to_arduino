#!/usr/bin/python
import serial, time
ard = serial.Serial('/dev/ttyUSB0', baudrate=9600, timeout=1)

#TODO Check if arduino ready by bidirectional communication:
# e.g. send 0xFF, until 0xFF is received
#TODO Check if extra bytes is processed fine
time.sleep(2)

ard.write(bytearray([1,4,0,0,0,255]));
ard.write(bytearray([1,4,1,0,0,255]));
ard.write(bytearray([1,4,2,0,0,255]));
time.sleep(1);
ard.write(bytearray([0,1,0]));
ard.write(bytearray([0,1,1]));
ard.write(bytearray([0,1,2]));
time.sleep(1);
ard.write(bytearray([1,4,0,0,255,0]));
ard.write(bytearray([1,4,1,0,255,0]));
ard.write(bytearray([1,4,2,0,255,0]));
time.sleep(1);
ard.write(bytearray([0,1,0]));
ard.write(bytearray([0,1,1]));
ard.write(bytearray([0,1,2]));
