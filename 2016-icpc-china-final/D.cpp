#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=3e5+100;
ll a[maxn],pre[maxn];
int val[maxn],N,K;
bool check(int mid)
{
	for(int i=1;i<=mid;i++)
		val[i] = pre[i] = 0;
	int pos=1;
	while(1){
		rep(i,1,mid){
			while(pos<=N&&pre[i]*2>a[pos])pos++;
			if(pos>N)break;
			pre[i] = a[pos++];
			val[i]++;
		}
		if(val[mid]>=K)break;
		if(pos>N)break;
	}
	for(int i=1;i<=mid;i++)
		if(val[i]<K)return true;
	return false;
}
int solve(int num)
{
	int l=1,r=num;
	while(l<=r){
		int mid = (l+r)/2;
		//printf("here %d %d %d\n",l,r,mid);
		if(check(mid))r=mid-1;
		else l = mid+1;
	}
	return r;
}
int main()
{
	int T,cas=1;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d%d",&N,&K);
		rep(i,1,N)
			scanf("%lld",&a[i]);
		sort(a+1,a+1+N);
		printf("%d\n",solve(N/K));
	}
}
