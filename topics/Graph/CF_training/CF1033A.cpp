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
//const int maxn=;
//const double esp=1e-6
int x[2],y[2],z[2],N;
int nnx = {-1,1,-1,1};
int nny = {1,-1,-1,1};
bool in_bound(int x,int y){
	return x>=0&&x<N&&y>=0&&y<N;
}
bool dfs(int x,int y)
{
	if(!vis[x][y])return false;
	vis[x][y] =1 ;
	if(x== z[0]&&y ==z[1])return true;
	for(int i=0;i<4;i++){
		int nx = x+nx[i] ,ny = y+ny[i];
		if(!in_bound(nx,ny))continue;
		if(dfs(nx,ny))return true;
	}
	return false;
}
bool check()
{
	for(int i =0;i<=N;i++)
		vis[x[0]][i]=vis[i][x[1]]=1;
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++){
				int nx = x[0]+i,ny =x[1]+j;
				if(!in_bound(nx,ny))continue;
				vis[x[0]+i][x[1]+j]=1;
		}
	for(int i=0;i<4;i++){
		int nx =x[0],ny = x[1];
		while(in_bound(nx,ny)){
			vis[nx][ny] =1;
			nx += nnx[i];
			ny += nny[i];
		}
	}
	return dfs(y[0],y[1]);
}
int main()
{
	scanf("%d",&N);
	scanf("%d%d%d%d%d%d",&x[0],&x[1],&y[0],&y[1],&z[0],&z[1]);
	printf("%s",check()?"YES":"NO");
}

