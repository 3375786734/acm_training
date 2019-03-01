n,m = map(int,input().split())
vis = [0 for _ in range(n+1)]
for x,y  in [map(int,input().split()) for _ in range(m)]:
    vis[x],vis[y] = 1,1
print(n-1)
for i in range(1,n+1):
    if vis[i]==0:
        for j in range(1,1+n):
            if i!=j :print(i,j)
        break
