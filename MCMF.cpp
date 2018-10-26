/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn=1050;
const int maxm=1e6+100;
//const double esp=1e-6
const int inf= 1e9;
struct Eg{
	int to,next,cap,flow;
	double cost;
};
int N;
Eg eg[maxm];
int head[maxn],egcnt;
int pre[maxn],cost[maxn],vis[maxn]; //pre这里记录的是边
void addeg(int u,int v,int cap,int cst){
	eg[egcnt].to =v;eg[egcnt].next =head[u];eg[egcnt].cost = cst;
	eg[egcnt].cap =cap;eg[egcnt].flow=0;head[u] = egcnt++;
	
	eg[egcnt].to=u;eg[egcnt].next=head[v];eg[egcnt].cost = -cst;
	eg[egcnt].cap = 0;eg[egcnt].flow =0;head[v] = egcnt++;
}
bool spfa(int S,int T,int n){
	MEM(vis,0);//MEM(cost,0x3f3f3f);
	rep(i,0,n-1)cost[i] = inf;
	cost[S] = 0;vis[S] = 1;pre[S] =-1;
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int fa =q.front();
		vis[fa] = 0;
		for(int i=head[fa];i!=-1;i=eg[i].next){
			int v =eg[i].to;
			if(eg[i].cap-eg[i].flow>0&&cost[v]>cost[fa]+eg[i].cost){
				cost[v] = cost[fa] +eg[i].cost;
				pre[v] = i;  //记录边
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return cost[T] != inf;//find augment;
}
/*
 *@return : flow
 *MC mincost
 */
int MCMF(int S,int T,double &MC ,int n){
	int ans=0;
	while(spfa(S,T,n)){
		int mint = inf;
		for(int i=pre[T];i!=-1;i=pre[eg[i^1].to])
			mint = min(mint,eg[i].cap - eg[i].flow);
		ans+=mint;
		for(int i=pre[T];i!=-1;i=pre[eg[i^1].to]){
			eg[i].flow+=mint;eg[i^1].flow-=mint;
			MC += mint *eg[i].cost;
		}
	}
	return ans;
}
int main()
{
	//init();
	egcnt=0;MEM(head,-1);
	double cc=0;
	int ans= MCMF(1,2,cc,1);	
}

