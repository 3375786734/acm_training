/*
 *remark:有选择,又有顺序的dp问题,我们通常是先确定顺序,这里可以发现,一定是现将长木棍放在外更优
 *细节问题:由于占据的空间可能不是整数,但是*2之后就能满足整数要求
 *注意开的空间别开小了
 *
 *solution2:考虑直接判断前i个,然后只需要记录前面有多少个悬在外面,当前悬不悬在外面即可
 *dp[i][j][u]=max(dp[i-1][j-a[i].half][u-1],dp[i-1][j-a[i].len][u]);
 *
 */
#include <bits/stdc++.h>
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn=4000+100;
typedef long long ll;
struct Node{
	int l,v;
	bool operator<(const Node  &a)const{
		return l<a.l; 
	}
};
Node nn[maxn];
ll f[1005][maxn],dp[2][maxn][3];
int N,L;
int main()
{
	int T,cas=1;
	//freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&L);
		L*=2;
		int a,v;
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++){
			scanf("%d%d",&a,&v);
			nn[i]=(Node){a*2,v};
		}
		sort(nn+1,nn+1+N);
		//for(int i=1;i<=N;i++)printf("%d\n",nn[i].l);
		ll ans=0;
		for(int i=1;i<=N;i++)ans=max(ans,(ll)nn[i].v);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=L;j++)
				if(j-nn[i].l>=0)f[i][j]=max(f[i-1][j-nn[i].l]+nn[i].v,f[i-1][j]);

		for(int i=N;i>=1;i--){
			for(int j=1;j<=L;j++){
					//printf("nn %d\n",nn[i].l/2);
					if(j>=nn[i].l/2){
						if(i<N)dp[i%2][j][1]=max(dp[(i+1)%2][j-nn[i].l/2][0]+nn[i].v,dp[(i+1)%2][j][1]);
						dp[i%2][j][0]=max((ll)nn[i].v,dp[(i+1)%2][j][0]);
						//printf("last %d length %d dp[2] %d dp[1] %d\n",i,j,dp[i][j][2],dp[i][j][1]);
						ans=max(ans,dp[i%2][j][0]+f[i-1][L-j]);
						ans=max(ans,dp[i%2][j][1]+f[i-1][L-j]);
					}
			}
		}
		/*
		dep(i,N,1)
			dep(j,L,1)
				dep(k,2,1)printf("dp[%d][%d][%d]:%lld\n",i,j,k,dp[i][j][k]);
		for(int i=0;i<=N;i++)
			for(int j=1;j<=L;j++)
				for(int k=0;k<3;k++){
					ans=max(ans,dp[i+1][j][k]+f[i][L-j]);
					//if(dp[i+1][j][k]+f[i][L-j]==3)printf("here: dp[%d][%d][%d]:%d+f%d = %d\n",i+1,j,k,dp[i+1][j][k],f[i][L-j],ans);
				}
		*/
		printf("Case #%d: %lld\n",cas++,ans);
	}
}
