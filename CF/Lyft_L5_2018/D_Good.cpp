/*
 *trick,将array不用的数标记出来,空间重用
 *pow会有精度损失,求解方法见check函数,先-.1然后不断遍历
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+100;
const double eps=1e-2;
const int mod=998244353;
typedef long long ll;
ll a[maxn],oth[maxn];
ll check(ll a,int op){
	ll rt=pow(a,1.0/op)-.1;
	while(1){
		ll res=1;
		for(int i=0;i<op;i++)
			res*=rt;
		if(res>a)return false;
		else if(res==a)return rt;
		else rt++;
	}
}
int main()
{	
	int N,sz=0;
	map<ll,int> mm,res;
	set<ll> fac;
	mm.clear();res.clear();
	scanf("%d",&N);	
	rep(i,1,N)scanf("%lld",&a[i]);
	ll ans=1;
	rep(i,1,N){
		ll x;
		if(a[i]==1)continue;
		if(x=check(a[i],4))mm[x]+=4;
		else if(x=check(a[i],2))mm[x]+=2;
		else if(x=check(a[i],3))mm[x]+=3;
		else oth[sz++]=a[i];
	}
	for(int i=0;i<sz;i++)
		for(int j=1;j<=N;j++){
			if(oth[i]==a[j])continue;
			ll tt=__gcd(oth[i],a[j]);
			if(tt>1)fac.insert(tt);
		}
	for(int i=0;i<sz;i++){
		int ok=0;
		for(auto si:fac){
			if(oth[i]%si==0){
				ok=1;
				mm[si]++;mm[oth[i]/si]++;
				break;
			}
		}
		if(ok==0)res[oth[i]]++;
	}
	for(auto si:mm){
		ans=ans*(si.second+1)%mod;
		//printf(" %lld %d\n",si.first,si.second);
	}
	for (auto u:res)
		ans=(ans*(u.second+1)*(u.second+1))%mod;
	printf("%lld\n",ans);
}
