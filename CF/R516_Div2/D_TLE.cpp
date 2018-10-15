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
	//printf("at %d %d %d %d\n",x,y,cl,cr);
	if(cl>l||cr>r||vis[y][x])return ;
	vis[y][x]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx==px&&ny==py)continue;
		if(isin(nx,ny)){
			//printf("now at %d %d\n",nx,ny);
			if(dx[i]==1)dfs(nx,ny,cl+1,cr,x,y);
			else if(dx[i]==-1)dfs(nx,ny,cl,cr+1,x,y);
			else dfs(nx,ny,cl,cr,x,y);
		}
	}
}
int main()
{
	clock_t s,t;
	scanf("%d%d",&N,&M);
	scanf("%d%d%d%d",&y,&x,&r,&l);
	x--;y--;
	l=min(l,2*M);r=min(r,2*M);
	for(int i=0;i<N;i++)
		scanf("%s",str[i]);
	s=clock();
	dfs(x,y,0,0,-1,-1);
	int ans=0;
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			printf("%d",vis[i][j]);
		printf("\n");
	}*/
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			ans+=vis[i][j];
	printf("%d\n",ans);
	t=clock();
	double dur=double(t-s);
	printf("time %lf\n",dur/CLOCKS_PER_SEC);
}
