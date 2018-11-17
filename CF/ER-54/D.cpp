/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) mem(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
const int maxn=6e5+100;
const ll inf = 1e18;
int N,M,K;
int head[maxn],cur;
set<PP> ss;
int ww[maxn],v[maxn];
struct  Eg{
	int next,to,w,id;
};
Eg eg[maxn];
int vis[maxn];
ll dis[maxn];
int ans[maxn],sz;
void ag(int a,int b,int v,int id)
{
	eg[cur]= (Eg){head[a],b,v,id};
	head[a] = cur++;
}
struct Node{
	int id;
	ll dis;
	bool operator<(const Node &a)const{
		return dis>a.dis;   //大顶堆
	}
};
struct EE{
	int id,ff;
};
EE pre[maxn];
void dj(int S)
{
	for(int i=1;i<=N;i++)
		dis[i] = inf;
	dis[S] = 0;
	priority_queue<Node> q;
	q.push((Node){S,0});
	while(!q.empty()){
		Node fa = q.top();q.pop();
		int id=fa.id;
		if(vis[id])continue;
		vis[id]=1;
		for(int i=head[id];i!=-1;i=eg[i].next){
			int to = eg[i].to;
			if(dis[id]+eg[i].w < dis[to]){
				dis[to] = dis[id]+eg[i].w;
				q.push((Node){to,dis[to]});
				pre[to] = (EE){eg[i].id,id};
			}
		}
	}
}
void dfs(int now,int pre)
{
	for(int i=head[now];i!=-1;i=eg[i].next){
		int to = eg[i].to;
		if(to == pre)continue;
		if(sz>=K||sz>=N-1)return ;
		ans[sz++]  = eg[i].id;
		dfs(to,now);
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	int x,y,w;
	memset(head,-1,sizeof(head));cur=0;
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&x,&y,&w);
		ag(x,y,w,i);ag(y,x,w,i);
	}
	dj(1);
	memset(head,-1,sizeof(head));cur=0;
	rep(i,2,N){

		ag(pre[i].ff,i,0,pre[i].id);
	}
	dfs(1,1);
	printf("%d\n",sz);
	for(int i=0;i<sz;i++)
		printf("%d%c",ans[i],i==sz-1?'\n':' ');
}
