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
int cnt ,S,vis[25];
int nn[25][4],ans[25];
void dfs(int now,int dep)
{
	if(dep>21||(now == S && dep!=1))return ;
	for(int i=0;i<3;i++){
		int id =nn[now][i];
		if(dep==20&&id == S){
			printf("%d:  ",++cnt);
			printf("%d",S);
			for(int i=1;i<20;i++)
			  printf(" %d",ans[i]);
			printf(" %d\n",S);
			return ;
		}
		if(vis[id])continue;
		vis[id]= 1;ans[dep] = id;
		dfs(nn[now][i],dep+1);
		vis[id] = 0;
	}
}
int main()
{
	int a[3];
	for(int i =1;i<=20;i++){
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		for(int j=0;j<3;j++)nn[i][j] = a[j];
	}
	scanf("%d",&S);
	vis[S] = 1; //note that vis[S] should be fixed
	dfs(S,1);
}
