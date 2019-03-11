#倒着回去才是正解,因为倒着回去只有一个分支.
n = int(input())
a = [int(input()) for _ in range(n)]
ans =  -1
for i in range(n):
    tmp,sz = i,0
    while tmp>=0:
        tmp,sz = a[tmp]-1,sz+1
    ans = max(ans,sz)
print(ans)
