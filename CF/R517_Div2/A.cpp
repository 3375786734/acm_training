#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define f first
#define s second
using namespace std;
//const int maxn=;
int main()
{
	int w,h,k,ans=0;
	scanf("%d%d%d",&w,&h,&k);
	for(int i=1;i<=k;i++){
		ans+=(h+w-4)*2+4;
		w-=4;h-=4;
	}
	printf("%d\n",ans);
}
