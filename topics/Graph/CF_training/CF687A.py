'''
un-version
'''
scanf =  lambda:map(int,input().split)
n,m = scanf()
eg = [[] for _ in range(n+1)]
for x,y in [scanf() for _ in range(m)]:
    eg[x].append(y)
    eg[y].append(x)
f = range(n+1)
def fd(a):
    if f[a]!=a: f[a] = fd(f[a])
    return f[a]
def un(a,b):
    ra,rb = fd(a),fd(b)
    if ra== rb:return 
    f[ra] = rb

