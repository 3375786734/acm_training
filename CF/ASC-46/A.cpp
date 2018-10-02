/*
 *WA :cuz
 *
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=5000;
typedef long long ll;
typedef pair<ll,ll> PP;
typedef pair<PP,ll> NN;
int N,M;
ll x[maxn],y[maxn];
ll a[maxn],b[maxn],c[maxn];
struct Node{
	ll xx,yy,zz;
	bool operator<(const Node &a)const{
		if(xx==a.xx&&yy==a.yy)return zz<a.zz;
		else if(xx==a.xx)return yy<a.yy;
		else return xx<a.xx;
	}
	bool operator==(const Node &a)const {
		return (xx==a.xx&&yy==a.yy)&&zz==a.zz;
	}
};
map<Node,int> mm;
ll sq(ll a){
	return a*a;
}
ll dq(ll a,ll b,ll x,ll y){
	return sq(a-x)+sq(b-y);
}
int main()
{
	freopen("astronomy.in","r",stdin);
	freopen("astronomy.out","w",stdout);
	while(~scanf("%d",&N)&&N!=0){
		mm.clear();
		for(int i=1;i<=N;i++)
			scanf("%lld%lld",&x[i],&y[i]);
		for(int i=1;i<=N;i++)
			for(int j=i+1;j<=N;j++)
				{
					ll a=dq(0,0,x[i],y[i]),b=dq(0,0,x[j],y[j]);
					ll c=dq(x[i],y[i],x[j],y[j]);
					mm[(Node){a,b,c}]++;
					//if(a!=b)mm[(Node){b,a,c}]++;
					//printf("++%lld %lld %lld\n",a,b,c);
				}
		scanf("%d",&M);
		for(int i=1;i<=M;i++){
			int ans=0;
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			Node t=(Node){a[i],b[i],c[i]},tt=(Node){b[i],a[i],c[i]};
			if(mm.count(t))ans+=mm[t];
			if(mm.count(tt))ans+=mm[tt];
			if(a[i]==b[i])ans/=2;
			printf("%d\n",ans);
		}
	}
}
