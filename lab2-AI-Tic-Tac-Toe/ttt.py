from tttlib import *
player = 2
T = genBoard()
while True:
   printBoard(T)
   moveX = int(input("X move?"))
   while ((moveX < 0) or (moveX > 8) or (len(T)!= 9)or(T[moveX]!=0)):
      moveX = int(input("please enter again"))
   if T[moveX] == 0:
      T[moveX] = 1
   state = analyzeBoard(T)
   if state == -1:
      print("error")
      break
   if state == 1:
      print("X win")
      break
   elif state == 3:
      print("draw")
      break

   printBoard(T)
   print("Print O move")
   if genWinningMove(T,player)!=-1:
      T[genWinningMove(T,player)]=2
   elif genNonLoser(T,player)!=-1:
      T[genNonLoser(T,player)]=2
   elif genOpenMove(T,player)!=-1:
      T[genOpenMove(T,player)]=2
   elif genRandomMove(T,player)!=-1:
      T[genRandomMove(T,player)]=2
   state = analyzeBoard(T)
   if state == -1:
      print("error")
      break
   if state == 2:
      print("O wins")
      break
   elif state == 3:
      print("draw")
      break
printBoard(T)
print("Game ends")
