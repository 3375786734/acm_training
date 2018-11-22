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
const int maxn= 300;
int N,K,X;
int a[maxn],dp[maxn][maxn];
int main()
{
	scanf("%d%d%d",&N,&K,&X);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	MEM(dp,-1);
	dp[0][0] = 0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=X;j++)
			for(int k=i-1;k>=0&&k>=i-K+1;k--)
				dp[i][j] = max(dp[k][j-1]+a[i],dp[i][j]);
	int ans = -1;
	for(int i =1;i<=N;i++)
		for(int j =1;j<=X;j++)
			printf("dp%d %d : %d\n",i,j,dp[i][j]);
	for(int i =N;i>=N-K+1;i--)
		ans = max(ans,dp[i][X]);
	printf("%d\n",ans);
}

