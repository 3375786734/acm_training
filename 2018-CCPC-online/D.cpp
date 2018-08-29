#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int maxn=1e5;
ll num[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=1e5;i++)num[i]=1ll*i*i;
	while(T--)
	{
		int a,n;
		scanf("%d%d",&n,&a);
		if(n>2||n==0)printf("-1 -1\n");
		else if(n==2){
			if(a%2==0)printf("%lld %lld\n",1ll*(a/2)*(a/2)-1,1ll*(a/2)*(a/2)+1);
			else{
				if((1ll*a*a+1)/2<=1e9)printf("%lld %lld\n",(1ll*a*a-1)/2,(1ll*a*a+1)/2);
				else printf("-1 -1\n");
			}
		}
		else if(n==1){
			printf("1 %d\n",1+a);
		}
	}
}
