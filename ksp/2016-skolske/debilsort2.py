a = int(input())
mod = 1000000000

if a < 30:
  if a == 1:
    print(str(1))
  else:
    x = 5
    i = 2
    while i < a:
      x = x * 2 + 2
      i += 1
    print(str(x))
else:
  x = 3582
  a -= 11
  a %= 1562511 - 11
  i = 0
  while i < a:
    x = (2*x + 2) % mod
    i += 1
  print(str(x + mod)[1:])
  
