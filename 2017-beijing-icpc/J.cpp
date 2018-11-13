/*  -*- coding: utf-8 -*- */
//IDEA:dp[i][j][k] 把区间分成k堆所需要的最小代价
//本来需要枚举子区间中所有的堆数,但是发现他们中总是通过合并一堆得到的,因此只需要枚举(1,k-1)这一种情形就行了
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
const int maxn=200;
const int inf = 1e9;
int dp[maxn][maxn][maxn];
int pre[maxn],a[maxn];
int  N, L,R;
int main()
{
	//freopen("t.in","r",stdin);
	while(~scanf("%d%d%d",&N,&L,&R))
	{
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=N;i++)
			pre[i]  =pre[i-1]+a[i];
		memset(dp,0x3f3f3f,sizeof(dp));
		for(int j=1;j<=N;j++)
			dp[j][j][1] = 0;
		for(int i=2;i<=N;i++)
			for(int j=1;i+j-1<=N;j++){
				for(int x= 1;x<i;x++)
					for(int l = L-1;l<R;l++)
					dp[j][i+j-1][1] = 
						min(dp[j][j+x-1][1]+dp[j+x][i+j-1][l]+pre[j+i-1]-pre[j-1],dp[j][i+j-1][1]);
				//printf("get %d %d need %d\n",j,j+i-1,dp[j][i+j-1][1]);
				for(int k = 2;k<=i;k++)
					for(int x = 1;x<i;x++)
						dp[j][i+j-1][k] = min(dp[j][x+j-1][k-1]+dp[x+j][i+j-1][1],dp[j][i+j-1][k]);
			}
		if(dp[1][N][1]<inf)printf("%d\n",dp[1][N][1]);
		else printf("0\n")	;
	}
}

