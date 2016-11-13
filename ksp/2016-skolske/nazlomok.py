from decimal import *
from fractions import gcd

PREC=200
ENOUGH=50
getcontext().prec = PREC

T = int(input())
for t in range(0, T):  
  s = str(input())
  lb = s.find('(') 
  rb = s.find(')')
  n = (s[0:lb] + s[lb+1:rb] * PREC)[0:PREC] 
    
  nom = "1" 
  denom = str(Decimal('1.0') / Decimal(n)) # B / A
  #print("denom=" + denom)  
    
  while True: 
    a_is_1 = True
      
    if "." in denom: # maybe A > 1
      zv = denom[denom.find(".")+1:] 
      for i in range(0,min(ENOUGH, len(zv))): 
        if zv[i] != '0': # decimal part not "zero" 
          a_is_1 = False
  
    if a_is_1:
      if "." in nom: # maybe A > 1
        zv = nom[nom.find(".")+1:] 
        for i in range(0,min(ENOUGH, len(zv))): 
          if zv[i] != '0': # decimal part not "zero" 
            a_is_1 = False
            
    if a_is_1:
      break 
      
    n = "0." + zv
    mul = str(Decimal('1.0') / Decimal(n))
    nom = str(Decimal(mul) * Decimal(nom))
    denom = str(Decimal(mul) * Decimal(denom))
    resolve = nom 
    
    #print("zv=" + zv) 
    #print("mul=" + str(mul))
    #print("nom=" + nom) 
    #print("denom=" + denom) 

  A = int(float(nom))
  B = int(float(denom))
  G = gcd(A,B)
  
  print(str(int(A//G)) + "/" + str(int(B//G)))
  
