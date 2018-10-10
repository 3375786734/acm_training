#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll qpow(ll a,ll n)
{
	ll ans=1;
	while(n){
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;n>>=1;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,D;
		scanf("%d%d",&N,&D);
		if(D==1)printf("%lld\n",(ll)(N+2)*qpow(4,mod-2)%mod);
		else printf("%lld\n",(ll)(3*N+6)*qpow(8,mod-2)%mod);
	}
}
