scanf = lambda:map(int,input().split())
n,m  = scanf()
f = [list(range(n+1)) for _ in range(m+2)]
def fd(a,c):
    if f[c][a]!=a:f[c][a] = fd(f[c][a],c)
    return f[c][a]
def un(a,b,c):
    ra,rb = fd(a,c),fd(b,c)
    if ra==rb:return
    f[c][ra] = rb
def swap(a,b):
    tmp = a
    a = b
    b = tmp
for a,b,c in [map(int,input().split()) for _ in range(m)]:
    un(a,b,c)
q = int(input())
for x,y in [map(int,input().split()) for _ in range(q)]:
    print(sum(1 for i in range(1,m+1) if fd(x,i) == fd(y,i)))
