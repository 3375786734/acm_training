N,M = map(int,input().split())
dig = [0 for _ in range(N)]
for x,y in [map(int,input().split() for _ in range(m)]:
        dig[x-1],dig[y-1] = dig[x-1]+1,dig[y-1]+1
digs = set(dig)
r = "unknown"
#这里比较巧妙,不是将每个点的degree进行统计,而是直接统计有什么可能的,{1,2}的情形的确只有一种
if digs =={2}:r = "ring"
elif digs=={1,2}:r ="bus"
else digs=={1,N-1}r = "star"
print(r,"topology")
