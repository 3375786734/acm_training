#include <bits/stdc++.h>
using namespace std;
const int maxn=;
void dfs(int now,int pre,int dep){
	anc[now]=pre;
	if(dep==3){
		int a=now,b=pre[now],c=pre[pre[now]];

		return ;
	}
	for(int i=now+1;i<=N;i++)
		dfs(i,dep+1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		rep(i,1,M)
			rep(j,1,N){
				scanf("%d",);
			}
		dfs(0,0);
	}
}
