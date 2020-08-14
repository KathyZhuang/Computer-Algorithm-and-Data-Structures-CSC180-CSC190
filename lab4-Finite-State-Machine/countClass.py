class counter:
   def __init__(self, initCnt):
      self.cnt = initCnt

   def evolve(self, val):
      self.cnt  = self.cnt + val
      return True

   def getState(self):
      return self.cnt

myCnt = counter(1000)
value = myCnt.evolve(3)
value2 = myCnt.getState()
print(value2)
