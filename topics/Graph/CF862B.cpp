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
const int maxn = 2e5;
int vis[maxn],N,M;
int rc[maxn],cnt[maxn];
int lay[maxn];
vector<int> v[maxn];
void bfs(int now)
{
	MEM(vis,0);lay[now] = 1;
	queue<int> q;
	q.push(now);
	while(!q.empty())
	{
		int fa = q.front();q.pop();
		if(vis[fa]) continue;
		vis[fa]  =1;
		for(int vi :v[fa]){
			if(vis[vi]) continue;
			lay[vi] = lay[fa] +1;
			q.push(vi);
		}
	}
}
int main()
{
	scanf("%d",&N);
	int a,b;
	for(int i =0;i<N-1;i++){
		scanf("%d%d",&a,&b);
		v[a].pb(b),v[b].pb(a);
	}
	bfs(1);
	int ml = 0;
	for(int i=1;i<=N;i++){
		cnt[lay[i]]++;
		ml = max(ml,lay[i]);
	}
	ll odd = 0;
	for(int i=1;i<=ml;i+=2)odd += cnt[i];
	printf("%lld\n",(odd*(N-odd)-N+1));
}
