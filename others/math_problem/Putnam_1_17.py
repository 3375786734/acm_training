def dfs(dep,N,ans,arr):
    if dep == N:
        bit =1
        for i in range(0,N):
            bit  = bit*5
        if ans%bit == 0:
            return ans
        else :
            return -1
    tmp = 0
    for i in arr:
        tmp = dfs(dep+1,N,ans*10+i,arr)
        if tmp != -1:
            return tmp
    return -1

arr  = [5,6,7,8,9]
for i in  range(0,10):
    ans = dfs(0,i,0,arr)
    if ans != -1:
        print("case {}: {}".format(i,ans))
    else :
        print("No")
