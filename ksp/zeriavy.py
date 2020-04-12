(p, z) = [int(x) for x in input().split()]
Z = []
I = [i for i in range(0, p)]
# http://stackoverflow.com/questions/2612802/how-to-clone-or-copy-a-list
A = I[:]
for i in range(0, z):
    Z.append([int(x) for x in input().split()])
Z.sort()
for coord in Z:
    (x, y) = [x - 1 for x in coord]
    I[y + 1] = I[y]
    A[y] = A[y + 1]
#    print (x, y, I[y +1], A[y])
print(' '.join([str(A[i] - I[i] + 1) for i in range(0, p)]))

    


