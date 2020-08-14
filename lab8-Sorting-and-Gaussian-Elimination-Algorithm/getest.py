from ge import *

m1 = []
matrix = []
idx = 0
row = int(input('how many rows?'))
col = int(input('how many cols?'))
for r in range(0,row,1):
   for c in range(0,col,1):
      m1 = m1 + [idx]
      idx = idx + 1
   matrix = matrix + [m1]
   m1 = []
print(matrix)
print(ge_fw(matrix))
print(ge_bw(ge_fw(matrix)))
