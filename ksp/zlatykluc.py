
# http://stackoverflow.com/questions/5607284/how-to-add-with-tuples
def myadd(xs,ys):
  return tuple(x + y for x, y in zip(xs, ys))
def smer(xs, ys):
  return tuple(0 if x == y else 1 for x,y in zip(xs, ys))
#def is_unit(xs):
# d = 0
# for x in xs:
#   if x != 0:
#     d += 1  # not really dimension but fine
# return d == 1

def Kluc():
  # TODO Misof, why, line break would so much nicer then: 3 +x +y +z
  #S = int(input())
  #if S <= 0:
  #  return None
  pos = (0, 0, 0)
  useky = []
  tokens = 1
  M = {}
  while tokens < S:
    for t in input().split():
      print(tokens, "/", S, t, pos)
      tokens += 1
      # In python, tuples are immutable
      if t == "+x": new_pos = myadd(pos, (1, 0, 0))
      if t == "-x": new_pos = myadd(pos, (-1, 0, 0))
      if t == "+y": new_pos = myadd(pos, (0, 1, 0))
      if t == "-y": new_pos = myadd(pos, (0, -1, 0))
      if t == "+z": new_pos = myadd(pos, (0, 0, 1))
      if t == "-z": new_pos = myadd(pos, (0, 0, -1))
      if t[0] in ['+', '-']:
        useky.append((pos, new_pos))
        pos = new_pos
      else:
        if t not in M:
          M[t] = pos
        else:
          pos = M[t]

  # merge overlapping coordinates, pipkos pipkos pipkos zabudol som
  # no staci zistit ci maju rovnaky smer (je ich len 6), 
  # a ci su overlapping a ked ano, tak zobrat min a max
  u1 = 1
  while u1 < len(useky) - 1:
    overlap = False
    u2 = u1 + 1
    print(u1, u2)
    while u2 < len(useky):
      U1 = useky[u1]
      U2 = useky[u2]
      s1 = smer(U1[0], U1[1])
      s2 = smer(U2[0], U2[1])
      if s1 != s2:  # hope this workz
        u2 += 1
        continue
      s3 = smer(U1[0], U2[0])
      if s1 != s3:
        u2 += 1
        continue
      print("On same line: ", useky[u1], " and ", useky[u2])
      if U1[1] < U2[0] or U2[1] < U1[0]:
        u2 += 1
        continue
      print("  Merge")
      useky[u1] = (min(U1[0],U2[0]),max(U1[1],U2[1]))
      print("  Result: ", useky[u1])
      # TODO speed up
      del useky[u2]
      overlap = True
      u2 += 1
    if not overlap:
      u1 += 1

  return useky

while True:
  kluc1 = Kluc()
  if kluc1 is None:
    break
  kluc2 = Kluc()
  print(kluc1, kluc2)

  # pre kazde posunutie
    # pre kazdy rotaciu (!nie zrkadlove zobrazenie)

    # porovnaj by sort (kluce su rovnake ak multimnozina useciek je rovnaka)
