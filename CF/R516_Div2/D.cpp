#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
int vis[maxn][maxn],l,x,y,r,N,M;
char str[maxn][maxn];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool isin(int x,int y){
	//printf("now %d %d  %d %d\n",x,y,N,M);
	if(x>=0&&x<M&&y>=0&&y<N&&str[y][x]=='.')return true;
	else return false;
}
void dfs(int x,int y,int cl,int cr,int px,int py){
	if(cl>l||cr>r)return ;
	vis[y][x]=1;
	printf("at %d %d\n",x,y);
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx==px&&ny==py)continue;
		if(isin(nx,ny)){
			if(dx[i]==1)dfs(nx,ny,cl+1,cr,x,y);
			else if(dx[i]==-1)dfs(nx,ny,cl,cr+1,x,y);
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	scanf("%d%d%d%d",&y,&x,&l,&r);
	x--;y--;
	for(int i=0;i<N;i++)
		scanf("%s",str[i]);
	dfs(x,y,0,0,-1,-1);
	int ans=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			ans+=vis[i][j];
	printf("%d\n",ans);
}
