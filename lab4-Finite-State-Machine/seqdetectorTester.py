from seqdetectorlib import *
...

def main():
   x=seqdetector()
   n=0
   words_list = ['here','are','the','solutions','to','the','next','exam']
   for i in words_list:
      status=x.evolve(i)
      if status == True:
         print(n)
      n = n+1
   return True

main()
