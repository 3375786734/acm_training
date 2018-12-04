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
const int maxn = 2e2;
int G[maxn][maxn],dis[maxn][maxn];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	MEM(dis,0x3f3f3f);MEM(G,0x3f3f3f);
	int a,b,c;
	for(int i=1;i<=N;i++)G[i][i] = 0;
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(G[a][b]>c){
		G[a][b] = G[b][a]  =c;
		}
	}
	for(int i=1;i<=N;i++)
		for(int j =1;j<=N;j++)
			for(int k=1;k<=N;k++)
				G[i][j] = min(G[i][k]+G[k][j],G[i][j]);
	for(int j =1;j<=N;j++)
	for(int i=1;i<=N;i++)
		printf("%d%c",G[j][i],i==N?'\n':' ');
}

