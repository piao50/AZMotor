#!/usr/bin/env python

import json
import collections

import io
try:
    
    to_unicode = unicode
except NameError:
    to_unicode = str

print 'hello, gushi'

data = collections.OrderedDict()

for i in range(0,5):
    row = collections.OrderedDict()
    row['1'] = ','.join(['1',str(1000 * i),'1000'])
    row['2'] = ','.join(['1',str(1000 * i),'1000'])
    row['3'] = ','.join(['1',str(1000 * i),'1000'])
    data[str(i).zfill(2)] = row

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
