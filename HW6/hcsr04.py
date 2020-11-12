#!/usr/bin/env python
# -*- coding: utf-8 -*-

import Adafruit_BBIO.GPIO as GPIO
import time

def distanceMeasurement(TRIG,ECHO):

    GPIO.output(TRIG, True)
    time.sleep(0.00001)
    GPIO.output(TRIG, False)

    while GPIO.input(ECHO) == 0:
        pulseStart = time.time()
    while GPIO.input(ECHO) == 1:
        pulseEnd = time.time()

    pulseDuration = pulseEnd - pulseStart
    distance = pulseDuration * 17150
    distance = round(distance, 2)
    return distance

#Configuration
GPIO.setup("P9_15",GPIO.OUT) #Trigger
GPIO.setup("P9_12",GPIO.IN)  #Echo

#Security
GPIO.output("P9_11", False)
GPIO.output("P9_15", False)
time.sleep(0.5)
try:
    while True:
        recoveredDistance = distanceMeasurement("P9_11","P9_13")
        print ("Distance1: ", recoveredDistance, "cm")
       
    time.sleep(1)
except KeyboardInterrupt:
    print "Measurement stopped by user"
    GPIO.cleanup()