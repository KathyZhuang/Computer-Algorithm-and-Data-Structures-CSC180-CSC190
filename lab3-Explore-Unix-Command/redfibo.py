def fibo(n):
   if ((n==0)or(n==1)):
      return 1
   else:
      return fibo(n-1)+fibo(n-2)

def fiboL(n):
   accu = []
   if n == 0:
      accu += [1]
      return accu
   elif n == 1:
      accu += [1,1]
      return accu
   else:
      return fiboL(n-1)+ [fibo(n)]
def product(a,b):
   return a * b

def reduce(c,d):
   accu = d[0]
   for next in d[1:]:
      accu = c(accu,next)
   return accu

def redfibo(n):
   if n == 0:
      return 1
   elif n == 1:
      return 1
   else:
      return reduce(product,fiboL(n))

#print(redfibo(2))
