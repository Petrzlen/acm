def parseip(ipstr):
  iparr = ipstr.split('.') 
  return int(iparr[0]) * (1 << 24) + int(iparr[1]) * (1 << 16) + int(iparr[2]) * (1 << 8) + int(iparr[3]); 

N = int(input())
L = []

for x in range(0, N): 
  linearr = str(input()).split(' ')
  astr = linearr[0]
  ipstr = linearr[2] 
  
  a = 'A' if (astr == "allow") else 'D' 
  m = 0
  if ipstr.find('/') >= 0:
    m = int(ipstr[ipstr.find('/')+1:]) 
    ipstr = ipstr[0:ipstr.find('/')]
  
  ip = parseip(ipstr)
  b = ip - (ip%(1<<m))
  e = b + (1<<m) 
  L.append((a,b,e))
    
R = []
M = int(input())
for M in range(0, M):
  ip = parseip(str(input())) 
  b = False 
  for e in L: 
    if e[1]<=ip and ip<e[2]:
      R.append(e[0]) 
      b = True
      break; 
  
  if not b: 
   R.append('A') 
   
print(''.join(R))
