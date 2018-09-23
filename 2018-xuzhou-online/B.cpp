/*
 *记忆搜索,水题
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1005;
const int inf=200;
int N,M,k,l,dp[maxn][205];
int a[maxn],b[maxn],c[maxn];
int dfs(int now,int dep)
{
	if(dp[dep][now+100]!=inf)return dp[dep][now+100];
	int aa,bb,cc;
	if(a[dep]!=0)aa=dfs(min(100,now+a[dep][dep+1]),dep+1);
	if(b[dep]!=0)bb=dfs(max(now-b[dep],-100),dep+1);
	if(c[dep]!=0)cc=dfs(now*-1,dep+1);
	if(dep%2==0)return dp[dep][now+100]=max(max(aa,bb),cc);
	else return dp[dep][now+100]=min(min(aa,bb),cc);
}

int main()
{
	scanf("%d%d",&N,&M,&k,&l);
	for(int i=0;i<=N;i++)
		for(int j=0;j<=200;j++)
				dp[i][j]=200;
	rep(i,1,N)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	int ans=dfs(M,1);
	if(ans==1)printf("Good Ending\n");
	if(ans==-1)printf("Bad Ending\n");
	if(ans==0)printf("Normal Ending\n");
}
