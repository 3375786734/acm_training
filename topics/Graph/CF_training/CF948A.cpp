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
//const double esp=1e-6
const int maxn = 600;
char str[maxn][maxn];
int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,1,-1};
int vis[maxn][maxn],m,n;
set<PP> ss;
bool dfs(int y,int x)
{
	if(vis[y][x])return false;
	vis[y][x] = 1;
	if(str[y][x]=='S')return true;
	for(int i=0;i<4;i++){
		int nx = x+dx[i] , ny = y+dy[i];
		if(nx<0||nx>=m||ny<0||ny>=n||str[ny][nx]=='.')continue;
		if(dfs(y+dy[i],x+dx[i]))return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",str[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(str[i][j]=='W')ss.insert(PP(i,j));
	MEM(vis,0);
	int ok =1;
	for(PP si:ss)
		if(dfs(si.fi,si.se)){
			ok =0;break;
		}
	printf("%s\n",ok==0?"No":"Yes");
	if(ok==1){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				if(str[i][j]=='.')printf("%c",'D');
				else printf("%c",str[i][j]);
			printf("\n");
		}
	}
}

