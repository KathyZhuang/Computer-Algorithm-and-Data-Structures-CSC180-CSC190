
class stack:
    def __init__(self):
        self.save=[]

    def push(self,x):
        self.save = self.save + [x]
        return True

    def pop(self):
        ls = len(self.save)
        if ls==0:
            return False
        elif ls==1:
            r=self.save[0]
            self.save=[]
            return r
        else:
            r=self.save[ls-1]
            self.save=self.save[0:ls-1]
            return r
   def empty(self):
        ls = len(self.save)
        if ls == 0:
            return True
        else:
            return False
