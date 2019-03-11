n,m = map(int,input().split())
maxn = 3e4+1
lay = [0 for _ in range(int(3e4+1))]
vis = [0 for _ in range(int(3e4+1))]
def bfs(now):
    cnt,head,tail = 0,0,0
    que = [0 for i in range(int(1e5))]
    que[tail],tail = now,tail+1
    while tail>head:
        fa,head = que[head],head+1
        if vis[fa] == 1:continue
        vis[fa] = 1
        if fa == m: return lay[fa]
        if fa>0 and fa<3e4:
            if fa-1>0 :que[tail],tail,lay[fa-1] = fa-1,tail+1,lay[fa]+1
            if fa*2<3e4 :que[tail],tail,lay[fa*2] = fa*2,tail+1,lay[fa]+1
    return -1
print(bfs(n))
