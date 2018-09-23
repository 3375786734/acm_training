#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int mod=998244353;
const int maxn=1e3+10;
ll dp[maxn][maxn][5];
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	dp[1][1][0]=dp[1][1][3]=1;
	dp[1][2][1]=dp[1][2][2]=1;
	rep(i,2,N){
		rep(k,1,2*i){
			dp[i][k][0]=(dp[i-1][k-1][3]+dp[i-1][k][1]+dp[i-1][k][2]+dp[i-1][k][0])%mod;
			dp[i][k][1]=(dp[i-1][k-1][0]+dp[i-1][k-1][3]+dp[i-1][k][1]+dp[i-1][k-2<0?0:k-2][2])%mod;
			dp[i][k][2]=(dp[i-1][k-1][0]+dp[i-1][k-1][3]+dp[i-1][k][2]+dp[i-1][k-2<0?0:k-2][1]);
			dp[i][k][3]=(dp[i-1][k][1]+dp[i-1][k][2]+dp[i-1][k-1][0]+dp[i-1][k][3])%mod;
		}
	}
	ll ans=0;
	for(int i=0;i<4;i++)
		ans+=dp[N][K][i];
	printf("%lld\n",ans);
}
