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
const int maxn = 2e5;
int dd[maxn],cnt,N;
int ans[maxn];
vector<int> v[maxn];
void dfs(int now,int pre,int nowc,int prec)
{
	set<int> col;
	printf("now %d",now);
	col.insert(nowc);col.insert(prec);
	int cc = 0;
	for(int vi:v[now]){
		if(vi==pre)continue;
		while(col.count(cc))cc = (cc+1)%cnt;
		ans[vi] = cc;
		dfs(vi,now,cc,nowc);
	}
}
int main()
{
	scanf("%d",&N);
	int a,b;
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&a,&b);
		v[a].pb(b),v[b].pb(a);
		dd[a]++ ,dd[b]++;
	}
	for(int i=1;i<=N;i++)
	  cnt = max(cnt,dd[i]);
	printf("%d\n",cnt);
	ans[1] = 0;
	dfs(1,0,0,0);
	for(int i=1;i<=N;i++)
	  printf("%d%c",ans[i],i==N?'\n':' ');
}

