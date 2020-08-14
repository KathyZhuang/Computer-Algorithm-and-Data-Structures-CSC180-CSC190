from counterlib import *

def testCounter(objectName,evolveNumber):
   objectName.evolve(evolveNumber)
   val = objectName.getState()
   return val

x = counter(1000)
y = counter(50)
z = counter(-33)
print(testCounter(x,3))
print(testCounter(z,10))
print(testCounter(y,2))
