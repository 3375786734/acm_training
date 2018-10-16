/*
 *当题目范围比较小的时候还可以考虑dp,只需要将状态精细一些
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=200;
int a[maxn],pre[maxn];
int dp[maxn][maxn][maxn];
int sum(int l,int r){
	return pre[r]-pre[l-1];
}
int main()
{
	int N,L,R;
	scanf("%d%d%d",&N,&L,&R);
	rep(i,1,N)scanf("%d",&a[i]);
	rep(i,1,N)pre[i]=pre[i-1]+a[i];
	sort(a+1,a+1+N);
	MEM(dp,0x3f3f3f);
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++)
			dp[i][j][j-i+1]=0;
	for(int len = 1;len <= N;len++){
		for(int s=1;s+len-1<=N;s++){
			for(int j=s+1;j<s+len-1;j++)
				for(int m=L-1;m<=R-1;m++)
				  dp[s][s+len-1][1]=
					min(dp[s][j][m]+dp[j+1][s+len-1][1]+sum(s,s+len-1),dp[s][s+len-1][1]);
			for(int j=s+1;j<s+len-1;j++)
				for(int k=2;k<len;k++)
					dp[s][s+len-1][k]=min(dp[s][s+len-1][k],dp[s][j][k-1]+dp[j+1][s+len-1][k]);
		}
	}
	printf("%d\n",dp[1][N][1]);
}
