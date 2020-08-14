import random
class conway:
   def __init__(self,x,y,z):
      self.numlist = x
      self.numint = y
      self.val = z
      self.mylist1 = []
      self.mylist2 = []
      for n in range(0,self.numlist,1):
         for m in range(0,self.numint,1):
            if self.val == "zeros":
               value = 0
               self.mylist1 += [0]
            elif self.val == "ones":
               self.mylist1 += [1]
            elif self.val == "random":
               self.mylist1 += [random.randint(0,1)]
         self.mylist2 += [self.mylist1]#2ithout bracket, that will be a list of int, not separate lists
         self.mylist1 = [] #clean up mylist 1
      print(self.mylist2) # generate the same list of number???


   def getDisp(self):
      self.stringval = ""
      for i in range(0,self.numlist,1):
         for j in range(0,self.numint,1):
            if self.mylist2[i][j]== 0:
               self.stringval += " "
            elif self.mylist2[i][j]== 1:
               self.stringval += "*"
            if j == self.numint - 1:
               self.stringval += "\n"
      return self.stringval

   def printDisp(self):
      print(self.stringval)
      return True

   def setPos(self, row, col, val):
      if ((val == 0)or(val == 1)):
         if ((row < self.numlist)and(col < self.numint)):
            self.mylist2[row][col]= val
            return True
         else:
            return False

   def getNeighbours(self,row,col):
      self.mylist3 = []
      up = row -1
      down = row + 1
      if up == -1:
         up = self.numlist - 1
      if down == self.numlist:
         down = 0
      left = col - 1
      right = col + 1
      if left  == -1:
         left = self.numint - 1
      if right == self.numint:
         right = 0
      self.mylist3 = [self.mylist2[up][left]]+[self.mylist2[up][col]]+[self.mylist2[up][right]]+[self.mylist2[row][left]]+[self.mylist2[row][col]]+[self.mylist2[row][right]]+[self.mylist2[down][left]]+[self.mylist2[down][col]]+[self.mylist2[down][right]]
      return self.mylist3

m = conway(10,12,'zeros')
print(m.setPos(9,11,1))
m.getDisp()
m.printDisp()
print(m.getNeighbours(0,0))

