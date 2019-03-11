n,m = map(int,input().split())
eg = [[] for _ in range(n+1)]
for x,y in [map(int,input().split()) for _  in range(m)]:
    eg[x].append(y)
    eg[y].append(x)
for i in range(1,n+1):eg[i].sort()
vis,ans = [0 for i in range(n+1)],[]
def dfs(now):
    if vis[now]:return 
    vis[now]=1
    ans.append(now)
    for i in eg[now]:
        dfs(i)
dfs(1)
print(" ".join(map(str,ans)))
'''
q,vis,ans = [1],[0 for _ in range(n+1)],[]
while q:
    fa = q.pop()
    if vis[fa]:continue
    ans.append(fa)
    vis[fa] = 1
    for i in eg[fa]:
        q.append(i)
print(" ".join(map(str,ans)))
'''

