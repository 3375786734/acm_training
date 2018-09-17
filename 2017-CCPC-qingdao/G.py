
T=int(input())

for i in range(T):
    N,M=[x for x in map(int,raw_input().split())]
    k=N//M
    if k*M==N:
        print N//M
    else:
        tmp=k+1
        if k%2==0:
            print tmp|k
        else:
            res=N-N//tmp*tmp
            rres=res//M
            if rres*M==res:
             print (tmp+rres)|tmp
            else:
             print (tmp+rres)|(tmp+rres+1)|tmp
        
