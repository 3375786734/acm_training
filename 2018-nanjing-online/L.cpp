#include <bits/stdc++.h>
using namespace std;
const int maxn=1<<20;
int S[25],s[25],a[25],b[25];
int dp[2][maxn],N;
bool check(int t,int state){
	int cnt=0;
	for(int i=0;i<N;i++)
		if((1<<i)&state)cnt++;
	if(cnt<=t)return true;
	else return false;
}

int main()
{
	int T;
	scanf("%d",&N);
	memset(S,0,sizeof(S));//memset(dp,0,sizeof(dp));
	for(int i=0;i<2;i++)
		for(int j=0;j<(1<<N);j++)
			dp[i][j]=-1e9-1;
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&a[i],&b[i],&s[i]);
		int aa;
		for(int j=0;j<s[i];j++){
			scanf("%d",&aa);
			S[i]+=(1<<(aa-1));
		}
//		printf("s %d\n",S[i]);
	}
	for(int i=0;i<N;i++){
		if(s[i]==0)dp[1][1<<i]=a[i]+b[i];//,printf("dp %d \n",dp[1][1<<i]);
	}
	dp[1][0]=0;
	for(int i=2;i<=N;i++){
		for(int j=0;j<(1<<N);j++){
			for(int k=0;k<N;k++){
				if((S[k]&j)==S[k]&&((1<<k)&j)!=0){

					dp[i%2][j]=max(dp[(i-1)%2][j-(1<<k)],
								max(dp[i%2][j],dp[(i-1)%2][j-(1<<k)]+(a[k]*i+b[k])));
//					else dp[i%2][j]=max(dp[i%2][j],dp[(i-1)%2][(1<<k)^j]);
				}
			}
		}
	}
	int ans=-1e9-1;
	for(int i=0;i<(1<<N);i++)
		if(dp[N%2][i]>ans){
			ans=dp[N%2][i];
			if(ans>55)printf("state %d\n",i);
		}
	printf("%d %d\n",ans,dp[N%2][(1<<N)-1]);
}
