n,m =  map(int,input().split())
eg = [[0]*n for _ in range(n)]
for x,y in [map(int,input().split()) for _ in range(m)]:
    eg[x-1][y-1],eg[y-1][x-1] = 1,1
print((n+1)*n/2-m)
for i in range(n):
    for j in range(n):
        if eg[i][j]==0:print(i+1,j+1)
