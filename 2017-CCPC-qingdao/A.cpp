/*
 *idea:注意到是在一个圆上进行移动,因此坐标等价于时间,以m为模,先将坐标进行变换
 *然后暴力枚举以每一个位置为初始时所需的时间,复杂度是O(P),因为可以在O(1)时间内进行转移.
 *
 *转移之后,后面的所有会减小q*cur的时间,前面的所有经过的,会增加m-cur的时间
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int maxn=2e5;
int N,M,P;
ll d[maxn],tt[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&M,&P);
		rep(i,1,N)scanf("%lld",&tt[i]);
		int a,b;
		ll sum=0,ans=1e18;
		rep(i,1,P){
			scanf("%d%d",&a,&b);
			if(tt[a]-1<b%M)d[i]=M-(b%M-tt[a]+1);
			else d[i]=tt[a]-1-b%M;
			sum+=d[i];
		}
		sort(d+1,d+P+1);
		rep(i,1,P)
			ans=min(ans,sum+1ll*M*(i-1)-P*d[i]);
		printf("%lld\n",ans);
	}
	
}
