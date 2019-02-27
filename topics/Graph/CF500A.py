#注意一点,如果只有一个分支的dfs实际上就是循环
'''
def dfs(now,vis):
    if now == t-1:
        return 1
    if now>t or vis[now]:
        return 0
    vis[now] = 1;
    if dfs(now+a[now],vis):
        return 1
    else :
        return 0

N,t = map(int,input().split())
a = list(map(int,input().split()))
vis = [0 for i in range(N+10)]

if dfs(0,vis):
  print("YES")
else:
  print("NO")
'''

t,a,s= int(input().split()[1])-1,list(map(int,input().split())),0
while s<t:s+=a[s]
print("YNEOS"[s>t::2])
