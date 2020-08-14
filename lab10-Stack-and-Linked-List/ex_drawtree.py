from stackLib import*

def traverse_breadth(T):
     x=Stack()
     x.push(T)
     while x.empty != ' ':

          r=x.pop()

          print(r[0])

          for i in r[1:len(r)]:

               x.push(i)
