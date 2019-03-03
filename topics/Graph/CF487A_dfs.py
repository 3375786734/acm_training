scanf = lambda:map(int,input().split())
n,m = scanf()
eg = [[] for _ in range(n+1)]
for x,y in [scanf() for _ in range(m)]:
    eg[x].append(y)
    eg[y].append(x)
q,lay = [],[0 for _ in range(n+1)]

def dfs(now,lay):
    
    for i in eg[now]:
        if not dfs():return 0
    return 1
ok = 1
for i in range(1,n+1):
    if not lay[i]:
        if not dfs(i,lay[i] = 1):ok =0
if not ok:print(-1)
else:
    nn = 
