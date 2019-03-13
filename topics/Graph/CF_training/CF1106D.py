import heapq as hq
n,m = map(int,input().split())
eg = [[] for _ in range(n+1)]
for x,y in [map(int,input().split()) for _  in range(m)]:
    if x == y :continue
    eg[x].append(y)
    eg[y].append(x)
q,ans,vis = [1],[],set()
while q:
    fa = hq.heappop(q)
    if fa in vis:continue
    ans.append(fa)
    vis.add(fa)
    for i in eg[fa]:
        hq.heappush(q,i)
print(" ".join(map(str,ans)))
