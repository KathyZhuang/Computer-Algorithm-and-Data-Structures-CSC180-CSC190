import sys


FIN=""
FOUT=""
COL =""
DIR =""


nargs=len(sys.argv)
skip=False
for i in range(1,nargs):
   if not skip:
      arg=sys.argv[i]
      print("INFO: processing",arg)
      if arg == "--fin":
         if i != nargs-1:
            FIN=sys.argv[i+1]
            skip = True
      elif arg == "--fout":
         if i != nargs-1:
            FOUT=sys.argv[i+1]
            skip= True
      elif arg == "--col":
         if i != nargs-1:
            COL=sys.argv[i+1]
            skip=True
      elif arg == "--dir":
         if i != nargs-1:
            DIR=sys.argv[i+1]
            skip=True
      else:
         print("ERR: unknown arg:",arg)
   else:
      skip=False
#take in the value from CSVFILE-IN
try:
   f = open(FIN,'r')
except:
   print("ERR: file", FIN, "is not present or cannot be opened")
lines= f.readlines()
f.close()
accum=[]
for i in lines:
   j=i.split('\n')[0]  # first get rid of the '\n'
   k=j.split(',')      # now split on the comma
   r=[]
   for x in k:
      r = r + [float(x)]
   accum = accum + [r] # accumulate
#sort the list using column and direction
if DIR == '+':
   up = True
elif DIR == '-':
   up== False
else:
   print("ERR:", DIR , "is an invalid input")

try:
   col = int(COL)
except:
   print("ERR:", COL , "is an invalid input")
if col >= len(accum):
   print("ERR:", COL , "is an invalid input")
   exit()
def genSortKey(col,up):
   def key(x):
      return x[col] if up else -x[col]
   return key
sortKey = genSortKey(col,up)

#write the above sorted list into CSVFILE-OUT
try:
   g = open(FOUT,'w')
except:
    print("ERR: file", FOUT, "is not present or cannot be opened")
g.write(str(sorted(accum,key= sortKey)))
g.close()

print("INFO: FIN",FIN)
print("INFO: FOUT",FOUT)
print("INFO: COL",COL)
print("INFO: DIR",DIR)

