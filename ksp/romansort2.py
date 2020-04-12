# TESTED:
# S=4242; F=romansort5.in; echo $S > $F; echo $S >> $F; seq -s" " $S >> $F
# python3.5 romansort1.py < $F > romansort1-5.out
# python3.5 romansort2.py < $F > romansort2-5.out
# diff romansort1-5.out romansort2-5.out

N = int(input())
Q = int(input())
R = [int(x) for x in input().split()]

# Generate all numbers in (string, value)
# Sort
# For each r in R, output the r-th index
# TODO(p1): Solve this for N up to 2^18 OMG PIPKOS

def ZmotajRomana(result, n):
  # == M
  if n >= 1000:
    result.extend((n // 1000) * ["M"])
    ZmotajRomana(result, n % 1000)
    return
  # CM  (DM is not allowed)
  if n >= 900:
    result.extend(['C', 'M'])
    ZmotajRomana(result, n - 900)
    return 
  # == D
  if n >= 500:
    result.append('D')
    ZmotajRomana(result, n - 500)
    return
  # CD (XD is not allowed :D)
  if n >= 400:
    result.extend(['C', 'D'])
    ZmotajRomana(result, n - 400)
    return
  # == C
  if n >= 100:
    result.extend((n // 100) * ["C"])
    ZmotajRomana(result, n % 100)
    return
  # XC (LC, IC not allowed, vlacikom, do modry)
  if n >= 90:
    result.extend(['X', 'C'])
    ZmotajRomana(result, n - 90)
    return
  # == L
  if n >= 50:
    result.append('L')
    ZmotajRomana(result, n - 50)
    return
  # XL (IL nor VL is allowed)
  if n >= 40:
    result.extend(['X', 'L'])
    ZmotajRomana(result, n - 40)
    return
  # == X
  if n >= 10:
    result.extend((n // 10) * ["X"])
    ZmotajRomana(result, n % 10)
    return
  # IX (VX not allowed)
  if n >= 9:
    result.extend(['I', 'X'])
    ZmotajRomana(result, n - 9)
    return
  # == V
  if n >= 5:
    result.append('V')
    ZmotajRomana(result, n - 5)
    return
  # IV
  if n >= 4:
    result.extend(['I', 'V'])
    ZmotajRomana(result, n - 4)
    return
  # == I
  if n >= 1:
    result.extend(n * ["I"])
    return
  if n == 0:
    return
  print("Pipkos: n=", n, " result=", result)

def ZrobBruteforce(pocet):
    L = []
    for n in range(1, pocet+1):
      roman = []
      ZmotajRomana(roman, n)
      L.append(("".join(roman), n))

      # Trosku Unittest
      if n == 2944:
        assert "MMCMXLIV" == "".join(roman)
      if n == 5462:
        assert "MMMMMCDLXII" == "".join(roman)
    L.sort()

#    for i in range(len(L)):
#      print(i+1, t)

    return L

m = N // 1000
mod = N % 1000
L1000 = ZrobBruteforce(1000)
Lmod = ZrobBruteforce(mod)

# uzavrete intervalisy
s1 = 946  # C, CC, CCC, CCCI, ... LXXXVII, LXXXVIII, M
s2 = 54  # V, VI, VII, ... XXXVII, XXXVIII
b1 = m * s1
b2 = b1 + mod

for r in R:
  if r <= b1:
    print(((r - 1) // s1) * 1000 + L1000[(r - 1) % s1][1])
  else:
    if r <= b2:
      print(m * 1000 + Lmod[r - b1 -1][1])
    else:
      print(((N - r) // s2) * 1000 + L1000[s1 + ((r - b2 - 1) % s2)][1])




  
