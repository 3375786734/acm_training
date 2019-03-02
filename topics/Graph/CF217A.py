n = int(input())
G = [[0,0] for _ in range(n)]
f = list(range(n+1))
def fd(a):
    if f[a]!=a:f[a]  = fd(f[a])
    return f[a]

def un(a,b):
    ra,rb = fd(a),fd(b)
    if ra==rb:return
    f[ra] = rb

for i in range(n):
    x,y = map(int,input().split())
    G[i] = [x,y]

for i in range(n):
    for j in range(i):
        if G[i][0] == G[j][0] or G[i][1] == G[j][1]:
            un(i+1,j+1)
print(sum(1 for i in range(1,n+1) if f[i]==i)-1)
