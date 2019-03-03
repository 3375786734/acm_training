/*  -*- coding: utf-8 -*- */
/*参见tex_note tree dp
 *
 *
 */
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
int dep[maxn],N;
vector<int> v[maxn];
double vv[maxn];
void dfs(int now,int dd)
{
	for(auto vi:v[now]){
		if(dep[vi]!=-1)continue;
		if(now!=1)vv[vi]  = vv[now]*(v[now].size()-1);
		else vv[vi] = vv[now]*(v[now].size());
		dfs(vi,dep[vi] = dep[now]+1);
	}
}
int main()
{
	scanf("%d",&N);
	int a,b;
	for(int i=1;i<=N;i++)vv[i]= 1,dep[i]= -1;
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&a,&b);
		v[a].pb(b),v[b].pb(a);
	}
	dfs(1,dep[1] = 0);
	double ans =  0;
	rep(i,2,N)
		if(v[i].size()==1)ans += (double)dep[i]/vv[i];
	printf("%lf\n",ans);
}

