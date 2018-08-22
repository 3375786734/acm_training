/*题解详见Bestcoder:
 *前i对情侣中有k对在一起的情形数记为:dp[i][k]
 *1.如果该对情侣放在一起,可以插空k个位置,这样对数保持
 *  如果插空到其他地方,那么对数将增加
 *2.如果不在一起,可以分别拆0对,1对,2对
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=1e3+100;
const int maxm=1e4+100;
ll dp[maxn][maxn];
ll fac[maxm],inv[maxm],d[maxm],b[maxm];
int N,D;
ll qpow(ll a,ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1)ans=ans*a%mod;
		n>>=1;a=a*a%mod;
	}
	return ans;
}

void init()
{
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=1e4;i++)
		fac[i]=fac[i-1]*i%mod;
	/*
	inv[10000]=qpow(fac[10000],mod-2);
	for(int i=10000-1;i>=1;i--)
		inv[i]=(1ll*inv[i+1]*(i+1))%mod;
	*/
	inv[2]=qpow(fac[2],mod-2);
	b[0]=1;
	for(int i=1;i<=10000;i++)
		b[i]=b[i-1]*2%mod;
	dp[1][0]=0,dp[1][1]=1;
	for(int i=1;i<=1e3;i++)
          for(int k=0;k<=i;k++)
              {
                  ll tmp=2*i+1-k;
                  dp[i+1][k]=(dp[i+1][k]+dp[i][k]*k%mod)%mod;
                  dp[i+1][k+1]=(dp[i+1][k+1]+dp[i][k]*tmp%mod)%mod;
                  if(k>=1)dp[i+1][k-1]=(dp[i+1][k-1]+dp[i][k]*k%mod*tmp%mod)%mod;
                  dp[i+1][k]=(dp[i+1][k]+dp[i][k]*((tmp-1)*tmp/2)%mod)%mod;
                  if(k>=2)dp[i+1][k-2]=(dp[i+1][k-2]+dp[i][k]*(k*(k-1)/2)%mod)%mod;             
			  }
}
int main()
{
	init();
	while(~scanf("%d%d",&N,&D)){
		ll ans=0;
		d[0]=1;
		for(int i=1;i<=N;i++)
			d[i]=d[i-1]*D%mod;
		/*
		dp[1][1]=1;dp[1][0]=0;
		for(int i=1;i<=N;i++)
			for(int k=0;k<=i;k++)
			{
				ll tmp=2*i+1-k;
				dp[i+1][k]=(dp[i+1][k]+dp[i][k]*k%mod)%mod;
				dp[i+1][k+1]=(dp[i+1][k+1]+dp[i][k]*tmp%mod)%mod;
				if(k>=1)dp[i+1][k-1]=(dp[i+1][k-1]+dp[i][k]*k%mod*tmp%mod)%mod;
				dp[i+1][k]=(dp[i+1][k]+dp[i][k]*(tmp-1)%mod*tmp*inv[2]%mod)%mod;
				if(k>=2)dp[i+1][k-2]=(dp[i+1][k-2]+dp[i][k]*k%mod*(k-1)*inv[2]%mod)%mod;
			}
		*/
		for(int i=0;i<=N;i++)
			ans=(ans+d[i]*dp[N][i]%mod)%mod;
		ans=ans*b[N]%mod;
		printf("%lld\n",ans%mod);
	}
}
