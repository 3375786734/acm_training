io = lambda: map(int,input().split())
n,m = io()
p,vis,eg = [0] + list(io()),[0 for _ in range(n+1)],[[] for _ in range(n+1)]
for x,y in [io() for _ in range(n-1)]:
    eg[x].append(y),eg[y].append(x)
cnt = p[1]

def dfs(now,lay):
    if vis[now] :return 
    ok,vis[now] = 0,1
    print("now at {} {}".format(now,lay))
    for i in eg[now]:
        if not vis[i]: 
            dfs(i,0 if (p[i]==0 and lay<=m) else (lay+p[i]))
            ok = 1
    if ok == 0 and lay<=m: 
        cnt+=1
        print("here at {}".format(now))
if __name__ == '__main__':
    dfs(1,p[1])
    print(cnt)
