import binary_tree
class tree:
   def __init__(self,x):
      self.store = [x,[]]
      self.ls = []
      self.q = queue()
   def AddSuccessor(self,x):
      self.store[1] = self.store[1] + [x]
      return True
   def Print_DepthFirst(self):
      self.PD_helper("   ")
      return True

   def PD_helper(self,prefix):
      print(prefix + str(self.store[0]))
      for j in self.store[1]:
         j.PD_helper(prefix + "   ")
      return True
   def Get_LevelOrder(self):
      L = [self.store[0]]
      T = self.store[1]
      while len(T) != 0:
         m = T
         T = []
         for i in m:
            L = L + [i.store[0]]
            T = T + i.store[1]
      return L

   def Get_LevelOrder_tester(self):
      self.GL_helper()
      return self.ls
   def GL_helper_tester(self):
      self.ls = self.ls + [self.store[0]]
      for i in self.store[1]:
         print(self.store[1])
         i.GL_helper()
      return True

def ConvertToBinaryTree(x):
   b = binary_tree(x.store[0])
   if len(x.store[1]) == 2:
      b.AddLeft(ConvertToBinaryTree(x.store[1][0]))
      b.AddRight(ConvertToBinaryTree(x.store[1][1]))
   return b

def ConvertToTree(x):
   tr = tree(x.store[0])
   status = True
   if len(x.store) == 3:
      tr.AddSuccessor(ConvertToTree(x.store[1])[1])
      tr.AddSuccessor(ConvertToTree(x.store[2])[1])
   if (len(x.store) != 1) and (len(x.store) != 3):
      status = False
   return [status,t]
