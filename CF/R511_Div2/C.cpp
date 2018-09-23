#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b ) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
typedef set<ll>::iterator SI;
const int maxn=3e5+100;
const int maxm=1.5*1e7+100;
ll a[maxn];
int ss[maxm],vis[maxm];
set<ll>nn;
int main()
{
	int N;
	ll ggc=-1,MM=-100;
	scanf("%d",&N);
	rep(i,0,N-1){
		scanf("%lld",&a[i]);
		if(i==1)ggc=__gcd(a[i],a[i-1]);
		if(i>1)ggc=__gcd(a[i],ggc);
		MM=max(MM,a[i]);
		nn.insert(a[i]);
	}
	sort(a,a+N);
//	printf("%d\n",ggc);
	SI si=nn.lower_bound(ggc+1);
	for(ll i=ggc+1;i<=MM;i++)
	{
		ll cnt=1;
		if(vis[i]==1)continue;
		while(i<=MM/cnt)
		{
			int l=lower_bound(a,a+N,i*cnt)-a;
//			printf("here %d %d\n",a[l],i*cnt);
			if(a[l]==i*cnt)
			{
				int r=upper_bound(a,a+N,i*cnt)-a;
				ss[i]+=r-l;
			}
			cnt++;
			vis[i*cnt]=1;
		}
	}

	int ans=-100;
	for(ll i=ggc+1;i<=MM;i++)
		ans=max(ans,ss[i]);
	if(ans>0)printf("%d\n",N-ans);
	else printf("-1\n");
	/*
	int cur=,ans=0;
	rep(i,2,N){
		if(__gcd(cur,a[i])<=ggc)ans++;
		elsei cur=__gcd(cur,a[i]);
	}
	if(cur<=ggc)printf("-1\n");
	else printf("%d\n",ans);
	*/
}

