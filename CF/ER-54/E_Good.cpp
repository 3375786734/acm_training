/*  -*- coding: utf-8 -*- */
/*
 *trick :直观想法是使用线段树维护区间和,但是这里[d,d+h]区间+z等价于只在d点加上+sum,在区间[d,d+h]上保持不变,然后在d+h+1点-sum,后面再保持不变,注意这一题和树上染色的区别,这里是树上的加法.
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
const int maxn = 6e5+100;
vector<PP> q[maxn];
vector<int> vv[maxn];
int N,M;
ll ans[maxn],num[maxn];
void dfs(int now,int pre,int dep,ll sum)
{
	for(PP qi:q[now]){
		num[dep]+= qi.second;
		num[min(dep+qi.first+1,N)] -= qi.second;
	}
	sum += num[dep];
	ans[now] = sum;
	for(int vi:vv[now]){
		if(vi == pre)continue;
		dfs(vi,now,dep+1,sum);
	}
	for(PP qi:q[now]){
		num[dep] -= qi.second;
		num[min(dep+qi.first+1,N)] += qi.second;
	}
}
int main()
{
	scanf("%d",&N);
	int a,b,c;
	for(int i=1;i<=N-1;i++){
		scanf("%d%d",&a,&b);
		vv[a].pb(b);vv[b].pb(a);
	}
	scanf("%d",&M);
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&a,&b,&c);
		q[a].pb(PP(b,c));
	}
	dfs(1,1,0,0);
	for(int i=1;i<=N;i++)
		printf("%lld%c",ans[i],i==N?'\n':' ');
}
