/*
 *题意:将所有颜色相同的点联通所需要的最少边为E_i
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int N,K;
int vis[maxn];
vector<int> vv[maxn];
int ans;
int sz[maxn];
int dfs(int now,int pre)
{
	sz[now]=1;
	for(vector<int>::iterator it=vv[now].begin();it!=vv[now].end();it++)
	{
		if(*it==pre)continue;
		sz[now]+=dfs(*it,now);
	}
	if(sz[now]>=K&&N-sz[now]>=K)ans++;
	return sz[now];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++)vv[i].clear();
		int a,b;
		for(int i=1;i<=N-1;i++){
			scanf("%d%d",&a,&b);
			vv[a].push_back(b);
			vv[b].push_back(a);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
}
