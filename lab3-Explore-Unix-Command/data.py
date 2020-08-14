def genSortKey(col,up):
   def key(x):
      return x[col] if up else -x[col]
   return key
col = 2
up = True
sortKey = genSortKey(col,up)

f = open('data','r')
lines=f.readlines()
f.close()
accum=[]
for i in lines:
   j=i.split('\n')[0]  # first get rid of the '\n'
   k=j.split(',')      # now split on the comma
   r=[]
   for x in k:
      r = r + [int(x)]
   accum = accum + [r] # accumulate

print(sorted(accum))
print(sorted(accum,key = sortKey))
