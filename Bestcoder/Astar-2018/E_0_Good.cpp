/*思路是,用排序后的dp顺序放到树状数组中,但是因为>当前下表的长为k-1的已经在上一次更新
 * 因此会出现多的计算次数,但是我们可以把k-1的更新放到计算k之后,这样就可以避免计算k-1中大于当前指标的值了
 *
 * 这里使用了sqrt(N)的随机优化！！
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=3e4;
const int mod=1e9+7;
int a[maxn];
ll bit[maxn],ans[maxn];
int dp[maxn][2];
int N,K;
int lowbit(int a){
	return a&(-a);
}
int add(int ps,int a){
	for(int i=ps;i<=N;i+=lowbit(i))
		bit[i]=(bit[i]+a)%mod;
}
ll que(int x)
{
	ll ans=0;
	for(int i=x;i>0;i-=lowbit(i))
		ans=(ans+bit[i])%mod;
	return ans;
}
//O(n*n*logn)
int main()
{
	int T,cas=0;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		MEM(bit,0);MEM(ans,0);
		scanf("%d",&N);
		rep(i,1,N)scanf("%d",&a[i]);
		rep(i,1,N)dp[i][1]=1;
		ans[1]=N;
		printf("Case #%d:",++cas);
		for(int j=2;j<=N;j++){
			//剩下的sqrt(N)不需要再更新了,否则会TLE
			if(ans[j-1]==0)break;
			for(int i=j-1;i<=N;i++){
				dp[i][j&1]=que(a[i]-1);
				ans[j]=(ans[j]+dp[i][j&1])%mod;
				//这样更新就不会出现>i的指标被计数的问题
				add(a[i],dp[i][(j-1)&1]);
//				printf("now %d %d dp %d\n",i,j,dp[j]);
			}
			MEM(bit,0);
		}
		rep(i,1,N)printf(" %lld",ans[i]);
		printf("\n");
	}
}
