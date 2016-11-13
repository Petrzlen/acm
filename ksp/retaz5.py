import sys
import string

M = int(sys.stdin.readline())
P = range(0,M+1)
P[1] = 1
sumP = 0
S = 0

#for n in range(2,M+1):
#  P[n]=1
#  for k in range(1,n):
#    P[n] += P[k] * (n+1-k)
#    print P[k] * (n+1-k)
 
for n in range(2,M+1):
  P[n] = 3*P[n-1] + sumP
  sumP += P[n-1]
    
#for i in range(1,M+1):
#  print str(i) + ' ' + str(P[i])
    
for k in range(1,M+1):
  S += P[k]*(M+1-k)
 
print str(1 + 2*S)
