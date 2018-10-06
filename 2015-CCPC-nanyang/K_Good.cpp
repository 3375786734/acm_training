/*
 *dp[0][i][j]
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=;
ll a[maxn],b[maxn];
ll pred[2][maxn],pren[2][maxn],dp[2][maxn][maxn];
ll getans(int op,int )
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		MEM(dp,0);
		scanf("%d",&N);
		rep(i,1,N)scanf("%lld%lld",a[0][i],a[1][i]);
		printf("Case #%d: \n",cas++);
		for(int i = 1; i <= N; i++)
			for(int j = 0; j < 2; j++){
				pren[j][i] = pren[j][i-1]+a[j][i];
				pred[j][i] = pred[j][i-1]+a[j][i]*(i-1);
			}
		//{d_{k-1}}+{d_{k-i}}=i-1
		for(int i=2;i<=N;i++){
			dp[0][i] = a[0][i] + ;
			dp[1][i] = a[1][i] + ;
				for(int j=1;j<i;j++)
					for(int k=0;k<2;k++)
						dp[k][i] = max(dp[k][j]+getans(),dp[k][i]);
		}
		printf("%d\n",max(dp[0][N],dp[1][N]));
	}
}
