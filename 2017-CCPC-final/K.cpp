#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;
const int maxn=1e3;
/*
int dx[8]={};
int dy[8]={};
int G[maxn][maxn],N,M;
void dfs(int nx,int ny,int dep,int lim){
	if(dep>lim)return ;
	if(nx<0||nx>=N||ny<0||ny>=N)return ;
	if(G[ny][nx]!=0)return;
	G[ny][nx]=1;
	dfs(nx+2,ny+1,dep+1,lim);
	dfs(nx+2,ny-1,dep+1,lim);

	dfs(nx+1,ny-2,dep+1,lim);
	dfs(nx+1,ny+1,dep+1,lim);

	dfs(nx-1,ny+2,dep+1,lim);
	dfs(nx-1,ny-2,dep+1,lim);
	
	dfs(nx-2,ny+1,dep+1,lim);
	dfs(nx-2,ny-1,dep+1,lim);
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int ans=1,K;
		N=40;
		memset(G,0,sizeof(G));
		dfs(N/2,N/2,0,T);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				if(i==N/2&&j==N/2)printf("S");
				else if(G[i][j]>0)printf("%d",G[i][j]),ans++;
				else printf("O");
				printf("\n");
		}
		printf("Case #%d: %d  %d\n",cas++,T,ans);
	}
}
*/
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int ans=1,N;
		printf("Case #%d: ",cas++);
		scanf("%d",&N);
		if(N==0)printf("1\n");
		else if(N==1)printf("9\n");
		else	if(N==2)printf("41\n");
		else if(N==3)printf("109\n");
		else if(N==4)printf("205\n");
		else printf("%llu\n",1ll*14*N*N-1ll*6*N+5);
	}
}
