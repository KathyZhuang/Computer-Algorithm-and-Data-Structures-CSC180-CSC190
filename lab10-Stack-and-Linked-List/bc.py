from stackLib import*

def bc(instr):
   x = stack()
   for i in range(0,len(instr),1):
      if (instr[i] == '(')or(instr[i] == '[')or(instr[i] == '{'):
         x.push(instr[i])
      elif instr[i] == ')':
         if x.pop() != '(':
            return [False,i]
      elif instr[i] == ']':
         if x.pop() != '[':
            return [False,i]
      elif instr[i] == '}':
         if x.pop() != '{':
            return [False,i]
   return [True,0]
