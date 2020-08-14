
def ge_fw(matrix):
   mout1 = []
   mout2 = []
   row = len(matrix)
   col = len(matrix[0])
   for i in range(0,row,1):
      for j in range(0,col,1):
         mout1 = mout1 + [matrix[i][j]]
      mout2 = mout2 + [mout1]
      mout1 = []
   # short and wide + square matrix
   if row <= col:
      limit = row
   else:
      limit = col
  #find the first row starting with non-zero and change
   for q in range(0,limit,1):
      cnt = q
      passA = False
      while mout2[cnt][q] == 0.0:
         cnt = cnt + 1
         if cnt >= row:
            passA = True
            break
      if passA == False:
         new = mout2[q]
         mout2[q]= mout2[cnt]
         mout2[cnt] = new
      for n in range(q+1,row,1):
         if mout2[q][q]!= 0:
            d1 = (mout2[n][q])/(mout2[q][q])
            for k in range(0,col,1):
               mout2[n][k] = mout2[n][k] - d1*(mout2[q][k])
   return mout2

def ge_bw(matrix):
   mout1 = []
   mout2 = []
   row = len(matrix)
   col = len(matrix[0])
   for i in range(0,row,1):
      for j in range(0,col,1):
         mout1 = mout1 + [matrix[i][j]]
      mout2 = mout2 + [mout1]
      mout1 = []
   #normalize the row & turn the nonzero entires above the 1 into 0s
   if row <= col:
      limit = row
   else:
      limit = col
   for m in range(limit-1,-1,-1):
      passB = False
      cntc = 0
      while (mout2[m][cntc] == 0.0):
         cntc = cntc + 1
         if cntc >= col:
            passB = True
            break
      #normalize
      if (passB == False):
         d2 = (1.0)/(mout2[m][cntc])
         for n in range(cntc,col,1):
            mout2[m][n] = (mout2[m][n])*d2
      #reduce to 0
         for k in range(0,m,1):
            d3 = mout2[k][cntc]
            for q in range(0,col,1):
               mout2[k][q] = mout2[k][q] - d3*mout2[m][q]
   return mout2


