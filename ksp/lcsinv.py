import operator
import string

(n, l) = [int(x) for x in input().split()]
s = str(input())
# print(n, l, s)

if l > n:
  print("IMPOSSIBLE")
  exit()

# PIPKOS, how to solve (abcdefgh...xyz)^N ?
# Hm, for n < N, it's impossible, because anything will match at least the first N of B
# For n = N we can do a^Na...
# For n > N we can do a^Nba..., a^(N-1)baba....
# The idea would be taking the least frequent character,
#   init the solution to z^n, and then filling in gaps
# abczdefzghizjkl  with l=7
# abczdzzzzzzzzzz
# Lets try, it's pretty straightforward.

freq = {}
for c in string.ascii_lowercase:
  freq[c] = 0
for c in s:
  freq[c] += 1

min_freq = min(freq.values())
if min_freq > l:
  print("IMPOSSIBLE")
  exit()

min_char = None
for c, val in freq.items():
  if val == min_freq:
    min_char = c
    break

# precondition: min_freq <= l <= n
# Make it a list, as strings are immutable in Python.
result = n * [min_char]
i = 0
for j in range(l - min_freq):
  while s[i] == min_char:
    i += 1
  result[i] = s[i]
  i += 1
  # print(i, j)
print("".join(result))

