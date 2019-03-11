R=lambda: map(int,input().split())
n,m = R()
c = list(R())
eg = [[] for _ in range(m)]
for x,y in [map(int,input().split())]:
    eg[x].append(y)
    eg[y].append(x)
vis = [0 for _ in range(n)]
tim = 0

def dfs(now):
    if vis[now]!=0:return 
    vis[now] = tim
    for i in eg[now]:dfs(i)
for i in range(N):
    tim += 1
    if vis[i]!=0:dfs(i)

inf = 1e9+200
minv =[inf for _ in range(n)]
for i in range(N):
    minv[vis[i]] = min(minv[vis[i]],c[i])
for i in range(1,tim):
    ans += minv[i]
print(ans)

