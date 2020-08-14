class binary_tree:
   def __init__(self,x):
      self.store = [x]

   def AddLeft(self,x):
      self.store = self.store + [x]
      return True


   def AddRight(self,x):
      self.store = self.store + [x]
      return True

   def Print_Depth(self,x):
      print(x*"   ",end="")
      print(self.store[0])
      if len(self.store)==3:
         self.store[1].Print_Depth(x+1)
         self.store[2].Print_Depth(x+2)
      return True

   def PD_helper_tester(self,pref):
      print(pref+str(self.store[0]))
      for m in self.store[1]:
         m.PD_helper("   "+pref)
      return True

   def Get_LevelOrder(self):
      L = [self.store[0]]
      T = [self.store[1]]+[self.store[2]]
      while len(T) != 0:
         t = T
         T = []
         for i in t:
            L = L + [i.store[0]]
            if len(i.store) == 3:
               T = T + [i.store[1]] + [i.store[2]]
      return L
