#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=4e5+100;
struct Eg{
	int next,to;
	ll w;
};
Eg eg[maxn];
int egcnt,tim,N,M,cnt,dfn[maxn],head[maxn];
ll f[maxn],cir[maxn];
void ag(int a,int b,ll v)
{
	eg[egcnt]=(Eg){head[a],b,v};
	head[a]=egcnt++;
}
void dfs(int now,int pre)
{
	dfn[now]=++tim;
	for(int i=head[now];i!=-1;i=eg[i].next){
		int id=eg[i].to;
		//if(id==pre)continue;//do not miss it;
		if(!dfn[id]){
			f[id]=f[now]^eg[i].w;
			dfs(id,now);
		}
		if(dfn[id]<dfn[now])
			cir[cnt++]=f[now]^f[id]^eg[i].w;
	}
}
ll solve()
{
	ll ans=0;
	for(ll i=60;i>=0;i--){
		//注意这里1ll!
		ll now=(1ll<<i);
		ll pvt=-1;
		for(int j = 0;j < cnt;j++)
			if(cir[j]&now){
				pvt = cir[j];
				break;
			}

		if(pvt!=-1){
			ans=max(ans,ans^pvt);//cuz the current pivot maybe the best one
			//ans=ans^pvt;
			for(int j =0 ;j <cnt;j++)if(now&cir[j])cir[j]^=pvt;
		}
	}
	return ans;
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		MEM(head,-1);egcnt=0;MEM(dfn,0);MEM(f,0);MEM(cir,0);cnt=0;tim=0;
		int u,v;
		ll w;
		for(int i=1;i<=M;i++){
			scanf("%d%d%lld",&u,&v,&w);
			ag(u,v,w);ag(v,u,w);
		}
		//printf("here\n");
		dfs(1,-1);
		//printf("here\n");
		printf("Case #%d: %lld\n",cas++,solve());
	}
}
