/*
 *问题转化为'任意'从2出发,找到'某一个'终点的最短路的和,反过来,就可以建立一个超终点,十分精妙
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
int x[maxn],y[maxn],c[maxn],w[maxn],egcnt,head[maxn];
int N,M,vis[maxn];
ll dis[maxn];
struct Eg{
	int next,to;
	ll l;
};
Eg eg[maxn];
struct Node{
	int id;
	ll l;
	bool operator<(const Node &a)const {
		return l>a.l;
	}
};
void ag(int a,int b,ll c)
{
	eg[egcnt]=(Eg){head[a],b,c};
	head[a]=egcnt++;
}
ll solve()
{
	MEM(vis,0);MEM(dis,0x3f3f3f);
	priority_queue<Node> q;
	rep(i,1,M)
		if(w[i]==0)q.push((Node){i,dis[i]=0});
	while(!q.empty())
	{
		Node fa=q.top();q.pop();
		int id=fa.id;
		if(vis[id])continue;
		vis[id]=1;
		for(int i=head[id];i!=-1;i=eg[i].next){
			int nxt=eg[i].to;
			if(dis[fa.id]+eg[i].l<dis[nxt]){
				dis[nxt]=dis[fa.id]+eg[i].l;
				q.push((Node){nxt,dis[nxt]});
			}
		}
	}
	ll dd=0;
	rep(i,1,M)
		if(w[i]==2&&!vis[i])return -1;
	rep(i,1,M)
		if(w[i]==2)dd+=dis[i];
	//printf("dd %lld\n",dd);
	return dd;
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		MEM(head,-1);egcnt=0;
		scanf("%d%d",&N,&M);
		rep(i,1,N)scanf("%d",&x[i]);
		rep(i,1,N)scanf("%d",&y[i]);
		rep(i,1,N)scanf("%d",&c[i]);
		rep(i,1,M)scanf("%d",&w[i]);
		rep(i,1,N)ag(y[i],x[i],c[i]);	
		printf("Case #%d: %lld\n",cas++,solve());
	}
}
