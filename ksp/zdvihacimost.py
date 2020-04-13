n=int(input())
MAX_T=123456
INF=987654321
NONE=987654322
lode=[]
for i in range(n):
  lode.append(int(input()))

S=[]
for i in range(2):
  S.append([])
  for j in range(n+1):
    S[i].append([])
    # 0..20 -> opening
    # 20..80 -> ship passing
    # 20 == 80
    # 81..99 -> closing
    for k in range(100):
      S[i][j].append(NONE)

S[0][0][0]=0
for t in range(1,MAX_T):
  a = t % 2
  b = (t+1) % 2
  for j in range(n+1):
    for k in range(100):
#      if lode[j]+1800 < t and ((k<=20) or (81<=k)):  # pipkos
#        S[a][j][k]=INF
#        continue
      if k == 0:
        S[a][j][k] = min(S[b][j][k],S[b][j][99])
        continue
      if k == 20:
        S[a][j][k] = 1 + min(S[b][max(j-1,0)][79], S[b][j][19], S[b][j][20])
        continue
      if k == 21:
        S[a][j][k] = 1 + S[b][j][20] if lode[j] <= t and lode[j] + 1800 >= t else INF
        continue
      if k == 80:
        S[a][j][k] = 1 + S[a][j][20]
        continue
      S[a][j][k] = 1 + S[b][j][k-1]

print(S[(MAX_T-1)%2][n][0])


