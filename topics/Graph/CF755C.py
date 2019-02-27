n = int(input())
a = list(map(int,input().split()))
f = list(range(n+1))
def fd(a):
    rt,tmp = a,a
    while f[rt]!=rt: rt = f[rt]
    while f[a]!=a:
        tmp = f[a]
        f[a] = rt
        a = tmp
    return rt
def un(a,b):
    ra,rb = fd(a),fd(b)
    if ra ==rb:return 
    else: f[ra] = rb
for i in range(n):
    un(i+1,a[i])
print(sum(1 for i in range(1,n+1) if f[i]==i))
