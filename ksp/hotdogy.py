(n, p, r) = [int(x) for x in input().split()]
P = set([int(x) for x in input().split()]
R = set([int(x) for x in input().split()]
G = [[] for x in range(0, n))]
for i in range(0, n):
    for x in input().split()]
V = [False for i in range(0, n)]
Q = [1]
R = []
while not Q.empty():
    node = Q.pop()
    if V[node]:
      continue
    R.append(node)
    V[node] = True
    for n in G[node]:
      Q.append(n)


