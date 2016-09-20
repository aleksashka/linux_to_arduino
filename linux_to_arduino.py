#!/usr/bin/python
import serial, time
ser = serial.Serial('/dev/ttyUSB0', 9600)
print("Waiting for serial initialization")
time.sleep(2)
print("Done")

ser.write('121')
