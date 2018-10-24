/*
 *WA:贪心的取离2倍最近的,样例1无法通过
 *
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=3e5+100;

int N,K;
ll b[maxn];
map<ll,int> mm;
int solve()
{
	int cnt=0;
	ll cur;
	if(mm.size()==0)return cnt;
	auto mi = mm.begin();
	cur=mi->fi;mm[mi->fi]--;cnt++;
	if(mm[mi->fi]==0)mm.erase(mi);
	for(auto mi:mm){
		auto bb = mm.lower_bound(cur*2);
		if(bb==mm.end())return cnt;
		cur = bb->fi;cnt++;
		mm[bb->fi]--;
		if(mm[bb->fi]==0)mm.erase(bb->fi);
	}
	return cnt;
}
int main()
{
	int T,cas=1;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		mm.clear();
		printf("Case #%d: ",cas++);
		scanf("%d%d",&N,&K);
		rep(i,1,N){
			scanf("%lld",&b[i]);
			mm[b[i]]++;
		}
		int cnt=0;
		while(1){
			int nn=solve();
			if(nn<K)break;
			cnt++;
		}
		printf("%d\n",cnt);
	}
}
