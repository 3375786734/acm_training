n,m,k = map(int,input().split())
eg = []
for x,y,c in [map(int,input().split()) for _ in range(m)]:
    eg.append([x-1,y-1,c])
    eg.append([y-1,x-1,c])
vis = [0 for _ in range(n)]
if k>0:
    klist  = list(map(int,input().split()))
    for i in klist:
        vis[i-1] =1
minv = 1e9+100
for i in eg:
    if minv>i[2] and vis[i[0]]!=vis[i[1]] #((vis[i[0]] ==0 and vis[i[1]]) or (vis[i[0]] and vis[i[1]]==0)):
            minv = i[2]
print(minv) if minv != 1e9+100 else print(-1)
