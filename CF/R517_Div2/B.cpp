#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define f first
#define s second
using namespace std;
//const int maxn=;
const int maxn=1e5+100;
int a[maxn],b[maxn];
int t[maxn],t2[maxn];
int aa[maxn],bb[maxn],sza,szb;
int main()
{	
	int N,ok=1;
	scanf("%d",&N);
	rep(i,1,N-1)scanf("%d",&a[i]);
	rep(i,1,N-1)scanf("%d",&b[i]);
	rep(i,1,N-1)
		if(b[i]>a[i]){
			printf("NO\n");
			return 0;
		}
	rep(i,1,1){
		if(a[i]==3){
			//printf("here\n");
			t[i]=3;t[i+1]=b[i];
		}
		else if(a[i]==2){
			if(b[i]==2)t[i]=t[i+1]=2;
			else if(b[i]==0)t[i]=0,t[i+1]=2;
			else ok=0;
		}
		else if(a[i]==1){
			if(b[i]==1)t[i]=t[i+1]=1;
			else  t[i]=0,t[i+1]=1;
		}
		else t[i]=t[i+1]=0;
	}
	t2[1]=t[2],t2[2]=t[1];
	if(ok==0){
		printf("NO\n");
		return 0;
	}
	//memset(ans,0,sizeof(ans));
	rep(i,2,N-1){
		int flag=0;
		for(int j=0;j<=3;j++)
			if(((t[i]&j)==b[i])&&((t[i]|j)==a[i])){
				t[i+1]=j;
				flag=1;
				break;
			}
		if(flag==0){
			ok=0;
			break;
		}
	}
	if(ok==1){
		printf("YES\n");
		rep(i,1,N)
			printf("%d%c",t[i],i==N?'\n':' ');
		return 0;
	}
	//memset(ans,0,sizeof(ans));
	//printf("here\n");
	ok=1;
	rep(i,2,N-1){
		int flag=0;
        for(int j=0;j<=3;j++){
			//if(i==3&&j==0)printf("%d %d %d\n",t2[i]&j,b[i],t2[i]|j==a[i]);
			if(((t2[i]&j)==b[i])&&((t2[i]|j)==a[i])){
                t2[i+1]=j;
                flag=1;
                break;
            }
		}
        if(flag==0){
            ok=0;
			break;
        }
	}
	if(ok==0)printf("NO\n");
	else {
		printf("YES\n");
		rep(i,1,N)
			printf("%d%c",t2[i],i==N?'\n':' ');
	}
}
