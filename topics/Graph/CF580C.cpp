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
const int maxn  = 5e5;
int vis[maxn],N,M,cnt,p[maxn];
vector<int> v[maxn];
void dfs(int now,int lay)
{
	if(vis[now])return ;
	vis[now] = 1;
	int ok = 0;
	for(int vi:v[now])
		if(!vis[vi])dfs(vi,(lay<=M&&p[vi]==0)?0:lay+p[vi]),ok = 1;
	if(ok==0&&lay<=M)cnt++;
}
int main()
{
	scanf("%d%d",&N,&M);
	int a,b;
	for(int i=1;i<=N;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&a,&b);
		v[a].pb(b),v[b].pb(a);
	}
	cnt = 0;
	dfs(1,p[1]);
	printf("%d\n",cnt);
}

