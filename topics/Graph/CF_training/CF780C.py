n = int(input())
eg,ans = [[] for _ in range(n+1)],[0 for _ in range(n+1)]
for x,y in [map(int,input().split()) for _ in range(n-1)]:
    eg[x].append(y)
    eg[y].append(x)
cnt = max(len(eg[i]) for i in range(1,n+1))+1
def dfs():
    q,vis,col = [1],set(),set()
    ans[1] = 0
    while q:
        fa = q.pop()
        if fa in vis:continue
        vis.add(fa)
        col.clear()
        col.add(ans[fa])
        for i in eg[fa]:
            if i in vis:col.add(ans[i])
        for i in eg[fa]:
            if i not in vis:
                ans[i] = ans[fa]
                while ans[i] in col: ans[i] = (ans[i]+1)%cnt
                col.add(ans[i])
                q.append(i)
print(cnt)
dfs()
for i in range(1,n+1):ans[i] += 1
print(" ".join(map(str,ans[1:n+1])))
