#!/usr/bin/env python

import json
import io
try:
    to_unicode = unicode
except NameError:
    to_unicode = str

print 'hello, gushi'

data = {}

for i in range(0,11):
    data[str(i).zfill(2)] = {'x':1,'y':2,'z':3}

#print data

for key in sorted(data.iterkeys()):
    print "%s: %s" % (key, data[key])

with open('xyz_motor.json','w') as f:
    s = json.dumps(data,
#                     indent=4,
                     separators=(',',':'),
                     ensure_ascii=False)
    f.write(to_unicode(s))

with open('xyz_motor.json') as f:
    loaded = json.load(f)    

print(data == loaded)    
    
print 'bye, gushi'
