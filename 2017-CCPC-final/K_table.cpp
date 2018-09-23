#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int maxn=1e3+100;
typedef pair<int,int> PP;
set<PP> ss;
int vis[maxn][maxn],N,K;
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};
int bfs(int dep)
{
	PP s=PP(N/2,N/2);
	vis[N/2][N/2]=0;
	queue<PP> q;
	q.push(s);
	memset(vis,0,sizeof(vis));
	while(!q.empty())
	{
		PP fa=q.front();q.pop();
		int x=fa.f,y=fa.s;
		if(vis[y][x]>=dep)break;
		ss.insert(fa);
		for(int i=0;i<8;i++){
			int nx=x+dx[i],ny=y+dy[i];
			PP np=PP(nx,ny);
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&vis[ny][nx]==0){
				q.push(np);
				vis[ny][nx]=vis[y][x]+1;
			}
		}
	}
	int ans=ss.size();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			if(i==N/2&&j==N/2)printf("S");
			else if(vis[i][j]==0)printf("x");
			else printf("%d",vis[i][j]);
		printf("\n");
	}
	printf("%d\n",ans);
}

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<K;i++){
		printf("%d\n",bfs(i));
	}
}
