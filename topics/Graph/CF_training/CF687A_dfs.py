n,m = map(int,input().split())
eg,lay =[[] for _ in range(n+1)],[0 for _ in range(n+1)]
for x,y  in [map(int,input().split()) for _ in range(m)]:
    eg[x].append(y),eg[y].append(x)
def dfs(now,lab):
    '''
    if not lay[now]:return 0
    for i in eg[now]:
        if lab*lay[i]==1:return 1
        if not lay[i]:
            lay[i] = -lab
            if dfs(i,lay[i]):return 1
    return 0
    '''
    q,lay[now] = [now],1
    while q:
        fa= q.pop()
        lab = lay[fa]
        for i in eg[fa]:
            if lab*lay[i] == 1:return 1
            elif not lay[i]: 
                lay[i] = -lab
                q.append(i)
    return 0

ok = 1
for i in range(1,n+1):
    if lay[i]==0:
        if dfs(i,1):ok = 0

if not ok:print(-1)
else:
    nn = [i for i in range(1,n+1) if lay[i]==1]
    pn = [i for i in range(1,n+1) if lay[i]==-1]
    print(len(nn))
    print(" ".join(map(str,nn)))
    print(len(pn))
    print(" ".join(map(str,pn)))
