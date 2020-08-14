import random
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
   i = 0
   for m in range(0,9,1):
      if ((T[m]!=0)and(T[m]!=1)and(T[m]!=2)):
         return -1
   if T[0]==T[1]==T[2]!=0:
      return T[0]
   if T[3]==T[4]==T[5]!=0:
      return T[3]
   if T[6]==T[7]==T[8]!=0:
      return T[6]
   if T[0]==T[3]==T[6]!=0:
      return T[0]
   if T[1]==T[4]==T[7]!=0:
      return T[1]
   if T[2]==T[5]==T[8]!=0:
      return T[2]
   if T[0]==T[4]==T[8]!=0:
      return T[0]
   if T[2]==T[4]==T[6]!=0:
      return T[2]
   allOccu = True
   for k in range(0,9,1):
      if T[k]==0:
         allOccu = False
   if allOccu == True:
      return 3
   return 0
   
def genNonLoser(T,player):
   K = [] #generate a new list
   K = list(T)
   if player == 1:
      oppo = 2
   elif player == 2:
      oppo = 1
   for i in range (0,9,1):
         if K[i]== 0:
            K[i]=oppo
            if analyzeBoard(K)== oppo:
               return i
            else:
               K[i]=0
   return -1

#test code: print(genNonLoser([1,1,0,2,0,2,1,2,0],2))
#test code:printBoard([2,1,1,1,1,0,2,2,0])
#test code: print(genWinningMove([2,1,1,1,1,0,2,2,0],2))
#test code: print(genWinningMove([1,1,0,2,0,2,1,2,0],2))

def genWinningMove(T,player):
   M = list(T)
   for i in range (0,9,1):
      if ((player == 1)or(player == 2)):
         if M[i]==0:
            M[i]=player
            if analyzeBoard(M)==player:
               return i
            else:
               M[i]=0
   return -1

def genRandomMove(T,player):
   J = []
   L = []
   J = list(T)
   pos = 0
   for m in range(0,9,1):
      if J[m]==0:
         L += [m]
   if len(L)==0:
      return -1
   else:
      if ((player==1)or(player==2)):
         pos = L[random.randint(0,len(L)-1)]
         return pos
   return -1
#test code:print(genRandomMove([1,2,1,0,2,0,0,1,0],2))

def genOpenMove(T,player):
   J = list(T)
   if((player!=1)and(player!=2)and(allOccupied==True)):
      return -1
   if J[4]== 0:
      return 4
   else:
      for i in [0,2,6,8]:
         if J[i]== 0:
            return i
         else:
            return -1
#test code: print(genRandomMove([0,0,1,2,0,0,0,0,0],2))


