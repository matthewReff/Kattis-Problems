from math import *
argList = raw_input()
argList = argList.split()

m = int(argList[0])
n = int(argList[1])
t = int(argList[2])


factorials = [1]
for i in range (1,14):
    factorials.append(factorials[i-1] * i)
 
valid = True
if t == 1:
    if n > 14 or factorials[n] > m:
        valid = False
elif t == 2:
    if 2 ** n > m:
        valid = False
elif t == 3:
    if n ** 4 > m:
        valid = False
elif t == 4:
    if n ** 3 > m:
        valid = False
elif t == 5:
    if n ** 2 > m:
        valid = False
elif t == 6:
    if n * log(n,2) > m:
        valid = False 
elif t == 7:
    if n > m:
        valid = False

if valid:
    print "AC"
else:
    print "TLE"
