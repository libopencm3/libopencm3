#! /usr/bin/env python

import serial
import signal
import sys
import time

def signal_handler(signal, frame):
        print 'You pressed Ctrl+C!'
        ser.close();
        sys.exit(0)

signal.signal(signal.SIGINT, signal_handler);

ser = serial.Serial('/dev/cu.usbmodemDEM1', 115200, timeout=0.05);

error = 0

tim = time.time();

cycles = 0

while 1==1:

    ser.write("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*(){}");

    buf = ser.read(75);

    cycles += 1

    if buf != "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*(){}" :
        error+=1

    print "received " + buf + " errors: " + str(error) + " cycles: " + str(cycles) + " runtime: " + str(time.time() - tim)

    #time.sleep(0.1);

ser.close();
