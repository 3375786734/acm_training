#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define f first
#define s second
using namespace std;
typedef long long ll;
const int maxn=6e5+100;
ll a[maxn],b[maxn],aa[maxn],bb[maxn],sza,szb;
int main()
{
	ll a,b,flag=0;
	scanf("%lld%lld",&a,&b);
	if(a<b)swap(a,b),flag=1;

	ll ans = (ll)(-1+sqrt(8.0*a-1)/2.0);
	ll res=b-(ans+1)*(ans)/2;
	for(ll i=1;i<=ans;i++)
		if(i<ans)bb[szb++]=i;
		else bb[szb++]=res+ans;
	if(a>=(res*(res+ans*2-1)/2)){
		for(ll i=0;i<res;i++)
			aa[sza++]=i+ans;
		ll rr= a - (res*(res+ans*2-1)/2),m=ans+res+1,n=ans+res;
		ll bbb=m-n,ccc=-2*rr-m*n;
		ll kkk= (-bbb+sqrt(bbb*bbb-4.0*ccc))/2.0;
		for(ll i=ans+res+1;i<=kkk;i++)
			aa[sza++]=i;
	}
	else {
		ll sum=0;
		for(ll i=ans;;i++){
			sum+=i;
			if(sum>a)break;
			aa[sza++]=i;
		}
	}
	if(flag==0){
		printf("%lld\n",sza);
		for(ll i=0;i<sza;i++)
			printf("%lld%c",aa[i],i==sza-1?'\n':' ');
		printf("%lld\n",szb);
		for(ll i=0;i<szb;i++)
			printf("%lld%c",bb[i],i==szb-1?'\n':' ');
	}
	if(flag==1){
			printf("%lld\n",szb);
        for(ll i=0;i<szb;i++)
            printf("%lld%c",bb[i],i==szb-1?'\n':' ');
		printf("%lld\n",sza);
        for(ll i=0;i<sza;i++)
            printf("%lld%c",aa[i],i==sza-1?'\n':' ');
	}

}
