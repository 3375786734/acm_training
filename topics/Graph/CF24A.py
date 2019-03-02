n = int(input())
p,c,ss = [[] for _ in range(n+1)],[[0]*(n+1) for _ in range(n+1)], 0
for x,y,z in [map(int,input().split()) for _ in range(n)]:
    p[x].append(y),p[y].append(x)
    c[x][y],ss= z,ss+z
tmp ,vis,cir = 1,[0 for _ in range(n+1)],[]
while 1:
    ok = 0
    cir.append(tmp)
    vis[tmp] = 1
    if not vis[p[tmp][0]] :tmp,ok = p[tmp][0],1
    elif not vis[p[tmp][1]]: tmp,ok = p[tmp][1],1
    if not ok : break
ns = sum(c[cir[i]][cir[i+1]] for i in range(-1,n-1))
print(min(ns,ss-ns))
