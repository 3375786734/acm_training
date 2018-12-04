/*  -*- coding: utf-8 -*- */
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
const int maxn =; 
int L,P;
int f[maxn];
int vis[maxn],dis[maxn],cntv[maxn];
bool SPFA(int S)
{
	MEM(vis,0);MEM(dis,0x3f3f3f);MEM(cntv,0);
	vis[S]=1;dis[S]=0;cntv[S]=1;
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int fa=q.front();q.pop();
		vis[fa]=0;
		for(int i = head[fa]; i != -1;i = eg[i].next){
			int id = eg[i].to;
			if(dis[id]>dis[fa]+){
				dis[id]=dis[fa]+eg[i].val;
				if(!vis[id]){
					q.push(id);
					vis[id]=1;
					if(++cntv[id]>N)return true;
				}
			}
		}
	}
	return false;
}
double solve()
{
	double l = 0,r =inf;
	while(l<r){
		double mid = (l+r)/2;
		if(SPFA(mid))l = mid;
		else r = mid;
	}
	return r;
}
int main()
{
	scanf("%d%d",&L,&P);
	for(int i=1;i<=L;i++)
		scanf("%d",&f[i]);
	int a,b,l;
	for(int i=1;i<=P;i++){
		scanf("%d%d%d",&a,&b,&l);
	}
	printf("%lf\n",solve());
}

