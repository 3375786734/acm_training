import math
n,m = map(int,input().split())
minv = n-2*m if n>=2*m else 0
maxv = minv
prek = int((1+math.sqrt(1+8*m))/2)
for i in range(prek-2,prek+2):
    if m<=(i*(i-1)/2) and i>=0:
        maxv = max(n-i,maxv)
print(minv,maxv)
