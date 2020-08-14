class Queue:
  def __init__(self):

    self.q=[]



  def push(self,value):

    self.q=self.q+[value]

    return 0


  def enqueue(self,T):

    self.q=T

    return 0



  def empty(self):

    if (len(self.q)==0):

      return True

    else:

      return False
