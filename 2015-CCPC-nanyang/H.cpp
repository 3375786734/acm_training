#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
typedef pair<int,int> PP;
char str[10][10];
PP ps[maxn];
int vis[10][10],bit[5][5][5],ans;
bool check(int cx,int cy,int (*num)[5])
{
	int vv[3][5];
	for(int i=0;i<3;i++)
		for(int j=0;j<5;j++)vv[i][j]=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<4;j++)
			if(i==0)vv[i][num[cy][j]]++;
			else vv[i][num[j][cx]]++;
	/*
	for(int i=0;i<4;i++)
		printf("at %d\n",num[cy][i]);
	*/
	for(int i=cx/2*2;i<cx/2*2+2;i++)
		for(int j=cy/2*2;j<cy/2*2+2;j++)
			vv[2][num[j][i]]++;
	for(int i=0;i<3;i++)
		for(int j=1;j<=4;j++)
			if(vv[i][j]>1||(vv[i][j]==0&&vv[i][0]==0)){
				//printf("now %d",i);
				return false;
			}
	return true;
}
void dfs(int dep,int (*num)[5])
{
	int cy=ps[dep].first,cx=ps[dep].second;
	//printf("here %d %d %d\n",cx,cy,dep);
	if(dep==-1){
		ans=0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				str[i][j]=num[i][j]+'0';
		return;
	}
	//if(vis[cy][cx]==1)return ;
	//vis[cy][cx]=1;
	for(int i=1;i<=4;i++){
//		printf("here %d %d %d\n",cx,cy,dep);
		if(bit[i][cy][cx])continue;
		num[cy][cx]=i;
		if(check(cx,cy,num))dfs(dep-1,num);
		if(ans==1)return;
		num[cy][cx]=0;
	}
}
int main()
{
	int T,cas=1;
	//freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int cnt=0;	
		int num[5][5];
		memset(num,0,sizeof(num));
		memset(bit,0,sizeof(bit));
		for(int i=0;i<4;i++)
			scanf("%s",str[i]);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(str[i][j]=='*')ps[cnt++]=PP(i,j);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(str[i][j]!='*'){
					int nn= str[i][j]-'0';
					for(int k=0;k<4;k++)bit[nn][i][k]=bit[nn][k][j]=1;
					num[i][j]=nn;
				}
		printf("Case #%d:\n",cas++);
		memset(vis,0,sizeof(vis));
		dfs(cnt-1,num);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				printf("%c",str[i][j]);
			printf("\n");
		}
	}
}
