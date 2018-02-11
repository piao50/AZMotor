#!/usr/bin/python

import erpi

print "Start of the Python program"
print erpi.hello("Gushi")
val = erpi.integrate(0, 3.1415926, 1000000)
print "The integral result is: ", val

import AZ
print "Start of AZ Module"
print AZ.hello("Nuctech")
val = AZ.integrate(0,3.1415926, 200)
print "The integral result of AZ is: ", val
