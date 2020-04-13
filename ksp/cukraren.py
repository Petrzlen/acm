from heapq import heappush

n=int(input())
cisla=[ int(x) for x in input().split() ]
h=[]
r=0
for i in range(len(cisla)):
    heappush(h, cisla[i]-i)
    r += h[0] + i
print(r)
  
