R=lambda: map(int,input().split())
n,m = R()
c = [0] +list(R())
f = list(range(n+1))
'''
如果这里写成递归的形式会爆栈
'''
def fd(a):
    rt,tmp = a,a
    while f[rt]!=rt:rt = f[rt]
    while f[a]!=a:
        tmp = f[a]
        f[a] = rt
        a = tmp
    return rt
        
for _ in range(m):
    x,y = R()
    rx ,ry = fd(x),fd(y)
    if c[rx]>c[ry]:
        f[rx] = ry
    else:
        f[ry] = rx
print(sum(c[i] for i in range(n+1) if f[i]==i))
