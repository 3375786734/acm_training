'''
N,S = map(int,input().split())
a = []
b = []
a = list(map(int,input().split()))
b = list(map(int,input().split()))
ok =0
if a[0] == 0:
    ok = 0
elif a[S-1] ==1:
    ok =1
elif b[S-1] == 1:
    for i in range(S,N):
        if a[i]==b[i]:
            ok =1
else:
    ok = 0

if ok:
    print("YES")
else:
    print("NO")
'''
S,N = map(int,input())
a,b = list(map(int,input().split())),list(map(int,input().split()))
if a[0] and (a[S-1] or (b[S-1] and any(a[i] and b[i] for i in range(S,N)))):
    print("YES")
else:
    print("NO")
