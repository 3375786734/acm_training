/*  -*- coding: utf-8 -*- */

#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;
//const double esp=1e-6
struct Eg{
	int to,dis;
};
vector<Eg> eg[maxn];
struct Node{
	int dis;
	bool operator<(const Node &a)const{
		return dis>a.dis;
	}
};
int dj(int srci,int ter)
{
	for(int i =1;i<=N;i++)
		dis[i] = inf;
	dis[src ]  = 0;;
	priority_queue<Node> q;
	while(!q.empty())
	{
		Node now = q.top;q.pop();
		int nid = now.id,nfg = now.fg;
		if(vis[nid][nfg])continue;
		vis[nid][nfg] = 1;
		for(Eg vi : eg[now]){

		}
	}
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for(int i=1;i<=M;i++){
			scanf("%d%d%d",&a,&b,&l);
			eg[a].pb(Eg(b,l));
		}
		scanf("%d%d",&S,&F);
		printf("%d\n",dj(S));
	}
}

