/*
 *trick,将array不用的数标记出来,空间重用
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+100;
const double eps=1e-2;
const int mod=998244353;
typedef long long ll;
ll a[maxn],oth[maxn];
ll cb(int a){
	return a*a*a;
}
ll sq(ll a){
	return (ll)a*a;
}
bool issqrt(ll a){
	if(a<=1)return false;
	if(fabs(sq(pow(a,1.0/2))-a)<eps)return true;
	else return false;
}
bool iscbrt(ll a){
	if(a<=1)return false;
	//printf("%lf",pow(a,1.0/3));
	if(fabs(cb(pow(a,1.0/3))-a)<eps)return true;
	else return false;
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
		if(a[i]==1)continue;
		if(issqrt(a[i])){
			if(issqrt(sqrt(a[i]))){
				mm[(ll)pow(a[i],1.0/4)]+=4;
			}
			else{
				mm[(ll)pow(a[i],1.0/2)]+=2;
				//printf("here %lld",a[i]);
			}
		}
		else if(iscbrt(a[i])){
			mm[(ll)pow(a[i],1.0/3)]+=3;
		}
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
