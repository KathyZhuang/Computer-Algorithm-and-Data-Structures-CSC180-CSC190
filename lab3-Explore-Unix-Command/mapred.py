#define a iist that returens number 1-9
L = range(1,10,1)
print(list(L));

#a function that returens square
def square(x):
   return x*x

#print the list by putting all x into the function and then put the return valueinto a list
M = map(square,L)
print(list(M))

def cube(x):
   return x*x*x
N = map(cube,L)
print(list(N))

def reducingSum(a,b):
   return a+b

def reduce(reducingSum,mylist):
   acc = mylist[0]
   for next in mylist[1:]:
      acc = reducingSum(acc,next)
   return acc


msum = reduce(reducingSum, list(M))
print(msum)
