class queue:
   def __init__(self):
      self.store = []
      self.cnt = 0

   def enqueue(self,x):
      self.store = self.store + [x]
      self.cnt = self.cnt + 1
      return self.cnt

   def dequeue(self):
      if (self.cnt == 0):
         return -1
      else:
         r = self.store[0]
         self.store = self.store[1:]
         self.cnt = self.cnt -1
         return r
   def empty(self):
      if (self.cnt == 0):
         return True
      else:
         return False
   def queueCnt(self):
      return self.cnt

class stack:
   def __init__(self):
      self.store = []
      self.cnt = 0

   def push(self,x):
      self.store = self.store + [x]
      self.cnt = self.cnt + 1
      return self.cnt

   def pop(self):
      if (self.cnt == 0):
         return -1
      else:
         r = self.store[len(self.store)-1]
         self.store = self.store[:len(self.store)-1]
         self.cnt = self.cnt -1
         return r

   def empty(self):
      if (self.cnt == 0):
         return True
      else:
         return False

class graph:
   def __init__(self):
      self.store = []

   def addVertex(self,n):
      if(n<0):
         return -1
      for i in range(0,n,1):
         self.store += [[]]
      return len(self.store)

   def addEdge(self,from_idx,to_idx,directed,weight):
      if(from_idx <0)or(to_idx<0)or(weight==0):
         return False
      self.store[from_idx] += [[to_idx,weight]]
      if(directed == False):
         self.store[to_idx] += [[from_idx,weight]]
      return True

   def traverse(self,start,typeBreadth):
      if typeBreadth == True:
         L = []
         A = []
         if start == None:
            #print("self.store is")
            #print(self.store)
            for v in range(0,len(self.store),1):
               C = queue()
               D = [False]*len(self.store)
               P = [False]*len(self.store)
               if D[v] == False:
             #     print("v is")
             #     print(v)
                  C.enqueue(v)
                  D[v] == True
               while C.empty()!=True:
                  w = C.dequeue()
               #   print("w is")
              #    print(w)
                  if P[w]==False:
                     A += [w]
                     P[w] = True
                  for m in self.store[w]:
                     x = m[0]
                     if D[x] == False:
                        C.enqueue(x)
                        print("x is")
                        print(x)
                        D[x] = True
               acc = 0
               for m in L:
                  if A == m:
                     acc += 1
               if acc == 0:
                  L += [A]
               A = []
         else:
            C = queue()
            D = [False]*len(self.store)
            P = [False]*len(self.store)
            if D[start] == False:
               C.enqueue(start)
               D[start] == True
            while C.empty() !=True:
               w = C.dequeue()
               if P[w]==False:
                  L += [w]
                  P[w] = True
               for m in self.store[w]:
                  x = m[0]
                  if D[x] == False:
                     C.enqueue(x)
                     D[x] = True
      if typeBreadth == False:
         L = []
         A = []
         if start == None:
            for v in range(0,len(self.store),1):
               S = stack()
               ST = stack()
               D = [False]*len(self.store)
               P = [False]*len(self.store)
               if D[v] == False:
                  S.push(v)
                  D[v] == True
               while S.empty() !=True:
                  w = S.pop()
                  if P[w]==False:
                     A += [w]
                     P[w] = True
                  for m in self.store[w]:
                     x = m[0]
                     if D[x] == False:
                        ST.push(x)
                        D[x] = True
                  while ST.empty() != True:
                     S.push(ST.pop())
               acc = 0
               for m in L:
                  if A == m:
                     acc += 1
               if acc == 0:
                  L += [A]
               A = []
         else:
            S = stack()
            ST = stack()
            D = [False]*len(self.store)
            P = [False]*len(self.store)
            if D[start] == False:
               S.push(start)
               D[start] == True
            while S.empty() !=True:
               w = S.pop()
               if P[w]==False:
                  L += [w]
                  P[w] = True
               for m in self.store[w]:
                  x = m[0]
                  if D[x] == False:
                     ST.push(x)
                     D[x] = True
               while ST.empty() != True:
                  S.push(ST.pop())
      return L

   def connectivity(self,vx,vy):
      t1 = False
      t2 = False
      for e in self.traverse(vx,False):
         if e == vy:
            t1 = True
      for f in self.traverse(vy,False):
         if f == vx:
            t2 = True
      if t1 == True:
         e1 = True
      else:
         e1 = False
      if t2 == True:
         e2 = True
      else:
         e2 = False
      return [e1,e2]

   def path(self,vx,vy):
      l1 = []
      l2 = []
      if(self.connectivity(vx,vy)[0] == False):
         l1 = []
      if (self.connectivity(vx,vy)[1] == False):
         l2 = []
      if(self.connectivity(vx,vy)[0] == True):
         L = self.traverse(vx,False)
         for m in L:
            if(m != vy)and(self.connectivity(m,vy)[0] == True):
               l1 += [m]
            else:
               break
         l1 += [vy]
      if(self.connectivity(vx,vy)[1] == True):
         A = self.traverse(vy,False)
         for m in A:
            if(m != vx)and(self.connectivity(m,vx)[0] == True):
               l2 += [m]
            else:
               break
         l2 += [vx]
      return [l1,l2]

x = graph()
#print(x
x.addVertex(9)
print(x.addEdge(1,2,True,1))
print(x.addEdge(1,3,True,2))
print(x.addEdge(1,4,True,10))
print(x.addEdge(2,5,True,1))
print(x.addEdge(2,6,True,3))
print(x.addEdge(4,7,True,5))
print(x.addEdge(4,8,True,8))
print(x.addEdge(6,5,True,5))
print(x.addEdge(7,1,True,5))
print(x.addEdge(7,6,True,5))


#print(x.addVertex(7))
#print(x.addEdge(0,1,True,1))
#print(x.addEdge(0,2,True,2))
#print(x.addEdge(2,3,True,10))
#print(x.addEdge(3,0,True,1))
#print(x.addEdge(4,1,True,2))
#print(x.addEdge(1,5,True,10))
#print(x.addEdge(5,5,True,10))
#print(x.addEdge(4,6,True,10))
print(x.connectivity(4,5))
print("path:")
print(x.path(7,5))
print(x.traverse(None,False))

#a = [1,2,3,4,5]
#b = a[:len(a)-1]
#print(b)



