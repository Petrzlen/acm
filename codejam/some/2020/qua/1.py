import sys

T  = int(input())

for t in range(1, T+1):
    N = int(input())
    trace = 0
    r_rep = 0
    c_rep = 0
    cols_unique = []
    for i in range(N):
        row_unique = set()
        for j, x in enumerate([int(s) for s in input().split(" ")]):
            if i == 0:
                cols_unique.append(set())
            if i == j:
                trace += x
            cols_unique[j].add(x)
            row_unique.add(x)
        if len(row_unique) != N:
            r_rep += 1

    for j in range(N):
        if len(cols_unique[j]) != N:
            c_rep += 1

    print(f"Case #{t}: {trace} {r_rep} {c_rep}") 
