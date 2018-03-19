#!/usr/bin/python

import erpi

print "Start of the Python program"
print erpi.hello("Gushi haha6!")
print "hello1:", erpi.hello1()
val = erpi.integrate(0, 3.1415926, 1000000)
print "The integral result is: ", val
