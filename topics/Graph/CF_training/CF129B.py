n,m = map(int,input().split())
G,cnt = [[0]*n for _ in range(n)],0
for a,b in [map(int,input().split()) for _ in range(m)]:
    a,b = a-1,b-1
    G[a][b],G[b][a] = 1,1
'''
#不是很高效的方法
while 1:
    flag,psl =0, [-1 for _ in range(n)]
    for i in range(n):
        sz,ps = 0,-1
        for j in range(n):
            sz+= G[i][j]
            ps = j if G[i][j] else ps
        if sz == 1:
            flag,psl[i] = 1,ps
    for i in range(n):
        if psl[i]>-1:G[i][psl[i]],G[psl[i]][i],psl[i] = G[i][psl[i]]-1,G[psl[i]][i]-1,-1
    if flag: cnt+=1
    else :break
print(cnt)
'''
while 1:
    c = [i for i in range(n) if sum(G[i])==1]
    if not len(c):
        break
    for i in c:
        for j in range(n):  #应为这里将点删除,同时没有重边,直接赋0
            G[i][j],G[j][i] = 0,0
    cnt +=1
print(cnt)
