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
//const double esp=1e-6
const int maxn =2e5+100; 
const int inf = 1e9+100;
set<int> ss[maxn];
int tim ,vis[maxn],N,M,c[maxn];
vector<int> v[maxn];
void dfs(int now)
{
	if(vis[now])return ;
	vis[now] = tim;
	for(int vi:v[now])dfs(vi);
}
void find_cc()
{
	MEM(vis,0);
	for(int i=0;i<N;i++){
		tim++;
		if(!vis[i])dfs(i);
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	rep(i,0,N-1)scanf("%d",&c[i]);
	int a,b;
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);a--,b--;
		v[a].pb(b),v[b].pb(a);
	}
	find_cc();
	for(int i=0;i<N;i++)
		ss[vis[i]].insert(c[i]);
	ll ans = 0;
	for(int i=1;i<=tim;i++)
			ans+=*(ss[i].begin());
	printf("%lld\n",ans);
}
