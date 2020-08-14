import sys
def readLines():
   FIN = "datain"
   f = open(FIN,'r')
   lines = f.readlines()
   for line in lines:
      print(line.split('\n')[0])
   f.close()

def openFile():
   FIN = "datain"
   try:
      print("here")
      f = open(FIN, 'r')
   except:
      print("ERR:file",FIN,"is not present or can't be opened")
   f.close()
def writeFile():
   FIN = "dataout"
   try:
      g = open(FIN,'w')
      g.write("This is content\n")
      g.write("This is more content\n")
   except:
      print("ERR:file",FIN,"is not present or can't be opened")
   g.close()
writeFile()
