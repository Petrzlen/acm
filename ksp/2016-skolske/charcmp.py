def get_input():
  h = input().split()
  r = int(h[0])
  c = int(h[1])
  if (r == 0 or c == 0): return None

  m = list()
  m.append('@' * (c+4))
  m.append('@' + '.' * (c+2) + '@')
  for i in range(r):
      m.append('@.' + input() + '.@')
  m.append('@' + '.' * (c+2) + '@')
  m.append('@' * (c+4))
#  print("\n".join(m))
  return m

def hash_point(p):
    return 1024 * p[0] + p[1]

def dfs(m, start, d):
    todo = [start]
    C = list()
    N = list()
    vis = set()
    while len(todo) > 0:
        n = todo.pop()
        if hash_point(n) in vis: continue
        vis.add(hash_point(n))
        if m[start[0]][start[1]] == m[n[0]][n[1]]:
            C.append(n)
        else:
            N.append(n)
            continue
        for move in d:
            todo.append([n[0] + move[0], n[1] + move[1]])
    return C,N

Wdir = [[0,1],[0,-1],[-1,0],[1,0]]
Bdir = Wdir + [[-1,-1],[-1,1],[1,1],[1,-1]]
def get_tree(m):
    todo = [[1,1]]
    comp = [[-1 for i in range(len(m[0]))] for j in range(len(m))]
    cid = 0
    T = list()
    while len(todo) > 0:
        n = todo.pop()
        if comp[n[0]][n[1]] >= 0: continue  # visited
        c = m[n[0]][n[1]]
        if c == '@': continue
        # assert(len(T) == cid)
        T.append(set())
        C,N = dfs(m, n, Wdir if c == '.' else Bdir)
        for p in C:
            comp[p[0]][p[1]] = cid
#            print("\n".join(["\t".join([str(i) for i in line]) for line in comp]))
        for p in N:
            parent = comp[p[0]][p[1]]
            # everybody has only one parent
            if parent != -1:
                T[parent].add(cid)
            todo.append(p)  # if visited, will be removed later
#        print(str(len(C)) + " " + str(len(N)) + " " + str(len(todo)))
#        print("\n".join(["\t".join([str(i) for i in line]) for line in m]))
#        print("\n".join(["\t".join([str(i) for i in line]) for line in comp]))
        cid += 1
    return T

def tree_to_str(T, n):
    return str(len(T[n])) + "#" + "@".join(sorted([tree_to_str(T, c) for c in T[n]]))


while True:
  m1 = get_input()
  if m1 is None: break
  m2 = get_input()
  
  t1 = get_tree(m1)
  t2 = get_tree(m2)

#  print(t1)
#  print(t2)
  s1 = tree_to_str(t1, 0)
  s2 = tree_to_str(t2, 0)
#  print(s1)
#  print(s2)
  print("yes" if s1 == s2 else "no")

#  break  # TODO
