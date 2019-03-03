n = int(input())
eg = [[] for _ in range(n+1)]
dep,vv = [-1 for _ in range(n+1)],[1 for _ in range(n+1)]
for x,y in [map(int,input().split()) for _ in range(n-1)]:
    eg[x].append(y)
    eg[y].append(x)
q,dep[1] = [1],0
while q:
    fa = q.pop()
    for  i in eg[fa]:
        if dep[i]==-1:
            dep[i] = dep[fa]+1
            if fa==1:vv[i] = vv[fa]*len(eg[fa])
            else :vv[i] = vv[fa]*(len(eg[fa])-1)
            q.append(i)
ans = sum(dep[i]/vv[i] for i in range(1,n+1) if (len(eg[i])==1 and i!=1))
print(ans)
