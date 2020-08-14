from sort import *
import random

length = int(input("what's the length of the array?"))
array = []
for x in range(0,length,1):
   array =array + [random.randint(1,30)]
print(array)
print(bubbleSort(array))
