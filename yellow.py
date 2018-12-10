#!/usr/bin/env python

from io import *
from urllib import *
from string import *

def urliter() :
    for i in xrange(100) :
        print "%d/100"  % i
        for j in lowercase :
            for k in lowercase :
                yield "http://www.%02d%c%c%c%c.com" % (i, j, k, j, k)

logfile = file("findsomewebsites.log", "w")

for u in urliter() :
    try :
        wp = urlopen(u)
        print "find " + u
        logfile.write(u + "\n")
    except :
        pass

logfile.close()
