from tttlib import *
T = genBoard()
printBoard(T)
while True:
   moveX = int(input("X move?"))
   while ((moveX < 0) or (moveX > 8) or (len(T)!= 9)or(T[moveX]!=0)):
      moveX = int(input("please enter again"))
   if T[moveX] == 0:
      T[moveX] = 1
      #printBoard(T)
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

   moveO = int(input("O move?"))
   while ((moveO < 0) or (moveO > 8) or (len(T)!= 9)or (T[moveO]!=0)):
       moveO = int(input("please enter again"))
   if T[moveO] == 0:
      T[moveO] = 2
      #printBoard(T)
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
print("Game ends")
