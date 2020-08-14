
def bubbleSort(array):
   n = len(array)
   if n == 0:
      return [False,array]
   rval = []
   for j in range(0,n,1):
      rval = rval + [array[j]]
   swapped = False
   while swapped == False:
      for i in range(1,n,1):
         if rval[i-1]>rval[i]:
            new = rval[i-1]
            rval[i-1] = rval[i]
            rval[i] = new
      allSwapped = True
      for m in range(1,n,1):
         if rval[m-1] > rval[m]:
            allSwapped = False
      if allSwapped  == True:
         swapped = True
      else:
         swapped = False
   return [True, rval]
