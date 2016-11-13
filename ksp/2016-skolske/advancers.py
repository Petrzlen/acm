def is_possible(v):
    global C, S
    s = sum([i for i in C if(i < v)])
    c = sum([1 for i in C if(i >= v)])
#    print(str(v) + ": " + str(s) + " " + str(c))
    return c + (s // v) >= S

def bin_search(a, b):
#    print(str(a) + " " + str(b))
    if (a + 1 >= b):
        return a
    m = (a + b) // 2
    return bin_search(m, b) if is_possible(m) else bin_search(a, m)

q = int(input())
for qi in range(q):
    l1 = input().split()
    t = int(l1[0])
    S = int(l1[1])  # we can ignore this
    l2 = input().split()
    C = [int(i) for i in l2]
    print(bin_search(0, 9223372036854775807))

