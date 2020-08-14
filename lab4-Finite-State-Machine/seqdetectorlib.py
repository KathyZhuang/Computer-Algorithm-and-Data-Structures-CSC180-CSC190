class seqdetector():
   def __init__(self):
      self.mylist = []
   def evolve(self,word):
      self.mylist = self.mylist + [word]
      newstring = ""
      w = 0
      while w < len(self.mylist):
         if ((self.mylist[w] == "here")and(len(self.mylist)-w == 8)):
            for m in range(w, w+8,1):
               newstring = newstring + str(self.mylist[m]) + " "
               if newstring == "here are the solutions to the next exam ":
                  return True
         w += 1
      return False
