#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int mod=998244353;
const int maxn=1e5+100;
typedef long long ll;
int N,M;
ll qpow(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;n>>=1;
	}
	return ans;
}
int zz[2][maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		int l,r,x;
		memset(zz,0,sizeof(zz));
		rep(i,1,M){
			scanf("%d%d%d",&l,&r,&x);
			zz[x-2][l]++;
			zz[x-2][r]--;
		}
		ll ans=1;
		for(int i=0;i<2;i++){
			ll sum=0,ok=1e9;
			for(int j=1;j<N;j++){
				sum+=zz[i][j];
				ok=min(sum,ok);
				//printf(" %d ok  %d\n",i,ok);
				if(sum==0)ok=0;
			}
			//printf("here %d\n",ok);
			if(ok!=1e9)ans=ans*qpow(i+2,ok)%mod;
		}
		printf("%lld\n",ans%mod);
	}
}
