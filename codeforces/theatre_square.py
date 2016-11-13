q = [long(x) for x in raw_input().strip().split(' ')]
n = q[0]
m = q[1]
a = q[2]  

print ((n + a - 1) // a) * ((m + a - 1) // a)
