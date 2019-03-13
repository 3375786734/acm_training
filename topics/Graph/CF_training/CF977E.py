n,m = map(int,input().split())
eg,vis = [[] for _ in range(n+1)],set()
for x,y in [map(int,input().split()) for _ in range(m)]:
    eg[x].append(y)
    eg[y].append(x)
cnt = 0
def dfs(now):
    q = [now]
    ok = True
    while q:
        fa,sz = q.pop(),0
        if fa in vis:continue
        vis.add(fa)
        if len(eg[fa])!=2 : ok = False
        for i in eg[fa]:
            if i not in vis:
                q.append(i)
    return ok
for i in range(1,n+1):
    if i not in vis:
        if dfs(i):cnt +=1
print(cnt)
