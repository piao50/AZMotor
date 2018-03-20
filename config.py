#!/usr/bin/env python

import json
import io
try:
    to_unicode = unicode
except NameError:
    to_unicode = str

print 'hello, gushi'

data = {'a':1, 'b':2, 'c':3}

#print data.keys()
#print data.has_key('d')

#for i in range(0,30):
#    data[chr(i+ord('A'))] = i

for i in range(0,30):
    data[str(i)] = "[%d] %s" % (i, 'gushi')

#print data

for key in sorted(data.iterkeys()):
    print "%s: %s" % (key, data[key])

with open('xyz_motor.json','w') as f:
    s = json.dumps(data,
                     indent=4,
                     separators=(',',':'),
                     ensure_ascii=False)
    f.write(to_unicode(s))

with open('xyz_motor.json') as f:
    loaded = json.load(f)    

print(data == loaded)    
    
print 'bye, gushi'
