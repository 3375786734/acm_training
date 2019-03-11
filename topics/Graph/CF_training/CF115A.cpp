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
const int maxn = 3000;
int p[maxn],N,depn[maxn],vis[maxn];
vector<int> v[maxn],rv[maxn];
void dfs1(int now,int dep,int &far)
{
	if(vis[now])return;vis[now];
	if(dep>depn[far]){
		depn[far] = dep;far = now;
	}
	depn[now] = max(depn[now],dep);
	vis[now]++;
	for(int vi:v[now])dfs1(vi,dep+1,far);
}
void dfs2(int now,int dep,int &maxd)
{
	if(vis[now])return ;
	vis[now]=1;
	maxd = max(maxd,dep);
	for(int vi:rv[now])dfs2(vi,dep+1,maxd);
}
int solve(int now)
{
	int far = now,dis = -1;MEM(depn,0);
	MEM(vis,0);dfs1(now,1,far);
	MEM(vis,0);dfs2(far,1,dis);
	return dis;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&p[i]);
		if(p[i]>=1)v[p[i]-1].pb(i),rv[i].pb(p[i]-1);
	}
	int ans=-1;
	MEM(vis,0);
	for(int i=0;i<N;i++)
		if(vis[i]==0)ans= max(ans,solve(i));
	printf("%d\n",ans);
}
