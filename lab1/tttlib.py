def genBoard():
   T = [0,0,0,0,0,0,0,0,0]
   return T

def printBoard(T):
   if len(T)!= 9:
      return False
   for k in range(0,9,1):
      if ((T[k]!=0)and(T[k]!=1)and(T[k]!=2)):
         return False
   m = [0,0,0,0,0,0,0,0,0]
   for i in range(0,9,1):
      if T[i] == 1:
         m[i] = "X"
      elif T[i] == 2:
         m[i] = "O"
      elif T[i] == 0:
         m[i] = i
      else:
         return False
   print(" " + str(m[0]) + " " + "|" + " " +str(m[1]) + " " + "|" + " " +str(m[2]) + " ")
   print("---|---|---")
   print(" " + str(m[3]) + " " + "|" + " " + str(m[4])+ " " + "|" + " " + str(m[5]) + " ")
   print("---|---|---")
   print(" " + str(m[6])+ " " + "|" + " " + str(m[7]) + " " + "|" + " " + str(m[8]) + " ")
   return True

def analyzeBoard(T):
   if printBoard(T)==True:
      i = 0
      for m in range(0,9,1):
         if ((T[m]!=0)and(T[m]!=1)and(T[m]!=2)):
            return -1
      if (((T[0]==T[1]==T[2]==1)or(T[3]==T[4]==T[5]==1)or(T[6]==T[7]==T[8]==1)or(T[0]==T[3]==T[6]==1)or(T[1]==T[4]==T[7]==1)or(T[2]==T[5]==T[8]==1)or(T[0]==T[4]==T[8]==1)or(T[2]==T[4]==T[6]==1))and((T[0]==T[1]==T[2]==2)or(T[3]==T[4]==T[5]==2)or(T[6]==T[7]==T[8]==2)or(T[0]==T[3]==T[6]==2)or(T[1]==T[4]==T[7]==2)or(T[2]==T[5]==T[8]==2)or(T[0]==T[4]==T[8]==2)or(T[2]==T[4]==T[6]==2))):
         return 3
      if T[0]==T[1]==T[2]!=0:
         if T[0]==1:
            return 1
         elif T[0]==2:
            return 2
      if i < 3:
         while i < 3:
            if T[i]==T[i+3]==T[i+6]!=0:
               if T[i] == 1:
                  return 1
               elif T[i]== 2:
                  return 2
            i += 1
      if (i%3 != 0)and(i<7):
         i += 1
      elif i%3 == 0:
         if T[i]==T[i+1]==T[i+2]!=0:
            if T[i]== 1:
               return 1
            if T[i]== 2:
               return 2
            i += 1
      if (i%3 != 0)and(i<7):
         i += 1
      elif i%3 == 0:
         if T[i]==T[i+1]==T[i+2]!=0:
            if T[i]== 1:
               return 1
            if T[i]== 2:
               return 2
         i += 1
      if ((T[0]==T[4]==T[8]==1) or (T[2]==T[4]==T[6]==1)):
         return 1
      elif ((T[0]==T[4]==T[8]==2) or (T[2]==T[4]==T[6]==2)):
         return 2
      allOccu = True
      for k in range(0,9,1):
         if T[k]==0:
            allOccu = False
      if allOccu == True:
         return 3
      return 0
   else:
      return -1
                               
