class queue:
   def __init__(self):
      self.store = []
      self.cnt = 0

   def enqueue(self,x):
      self.store = self.store + [x]
      self.cnt = self.cnt + 1
      return self.cnt

   def dequeue(self):
      if (self.cnt == 0):
         return [False,0]
      else:
         r = self.store[0]
         self.store = self.store[1:]
         self.cnt = self.cnt -1
         return [True,r]
   def empty(self):
      if (self.cnt == 0):
         return True
      else:
         return False
