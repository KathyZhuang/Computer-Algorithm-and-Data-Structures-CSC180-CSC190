import binary_tree
import tree

addSuccessor(y)
x.AddSuccessor(z)
c = tree(5)
m = tree(33)
y.AddSuccessor(m)
z.AddSuccessor(c)
print(x)
x.Print_DepthFirst()
lst = x.Get_LevelOrder()
for i in range(0,len(lst),1):
   print(lst[i])

q=binary_tree(1)
q.AddLeft(binary_tree(2))
a=binary_tree(3)
a.AddLeft(binary_tree(4))
a.AddRight(binary_tree(5))
q.AddRight(y)
q.Print_Depth(0)
ls = q.GetLevelOrder()
for i in range(0,len(ls),1):
   print(ls[i])
