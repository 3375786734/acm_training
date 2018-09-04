/*
 *容易想到这个lowbit的关系,然后注意到lowbit的递推关系
 * lowbit(2x)=lowbit(x)+1;
 */
//#include <bits/stdc++.h>
#include <cstdio>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
const int mod=1e9+7;
ll N;
ll gg(ll x){
	if(x<=1)return x;
	else return gg(x/2)+x;
}
//O(\log^2 N)
ll bsrch(ll N){
	ll l=(N/2)-30,r=(N/2)+30,ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
//		printf("now at %lld\n",mid);
		if(gg(mid)>=N){
			ans=mid;r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
ll sum(ll s,ll t,ll k){
	return  ((s+t)*k/2)%mod;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&N);
		N--;   //边界有两个1
		if(N<=1){
			printf("%d\n",N==0?1:2);
			continue;
		}
		ll up=bsrch(N),res=N-gg(--up);
//		printf("up %lld res %lld\n",up,res);
		ll flag=0,ans=1;
		for(int i=0;;i++){
			if((1<<i)<=up)flag=i;
			else break;
		}
		for(ll i=0;i<=flag;i++){
			ll b1=1<<i,b2=b1*2,uu=(up+b1)/b2;
//			printf("i %d uu %lld\n",i,uu);
			ans=(ans+(i+1)*sum(b1,b2*uu-b1,uu)%mod)%mod;
		}
		ans=(ans+(up+1)*res%mod)%mod;
		printf("%lld\n",ans%mod);
	}
}
