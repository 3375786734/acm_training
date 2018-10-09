/*
 *正常人的第一反应是列dp[i][k] 表示前i层中,第i层为性别k的最优值.
 *但是很明显是存在后效性的如下所示
 *   0 1 1 1 ...  1 | 0 在加了零之后,最优解会发生改变.
 *注意到,如果每次考虑的都是(0,1),(1,0)对的位置,那么就没有后效性了.因为后效性被这个(0,1)对给阻隔了
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=5000;
const ll inf=1e18;
ll a[2][maxn];
ll pred[2][maxn],pren[2][maxn],dp[2][maxn];
int N;
ll godown(int l,int r,int op){
	if(l>r)return 0;
	return pred[op][r]-pred[op][l-1]-(pren[op][r]-pren[op][l-1])*(l-2);
}
ll goup(int l,int r,int op){
	if(l>r)return 0;
	return (pren[op][r]-pren[op][l-1])*r-(pred[op][r]-pred[op][l-1]);
}
ll get_ans(int op,int l,int r){
	int mid = (r+l)/2;
	return godown(l,mid,op)+goup(mid+1,r,op);
}
int main()
{
	int T,cas=1;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		MEM(dp,0);
		scanf("%d",&N);
		rep(i,1,N)scanf("%lld%lld",&a[0][i],&a[1][i]);
		printf("Case #%d: ",cas++);
		for(int i = 1; i <= N; i++)
			for(int j = 0; j < 2; j++){
				pren[j][i] = pren[j][i-1]+a[j][i];
				pred[j][i] = pred[j][i-1]+a[j][i]*(i-1);
			}
		//{d_{k-1}}+{d_{k-i}}=i-1
		for(int i=1;i<=N;i++)
			for(int k=0;k<2;k++)
				dp[k][i]=inf;
		ll ans=inf;
		for(int i=1;i<N;i++){
			dp[0][i] = goup(1,i,0); //pren[0][i-1]*(i-1)-pred[0][i-1];
			dp[1][i] = goup(1,i,1); //pren[1][i-1]*(i-1)-pred[1][i-1];
			//printf("%lld %lld %lld %lld\n",dp[0][i],dp[1][i],a[i][1],a[i][0]);
			for(int j=1;j<i;j++)
					for(int k=0;k<2;k++){
						dp[k][i] = min(dp[k^1][j]+get_ans(k,j+1,i),dp[k][i]);
					}
				ans = min(dp[1][i]+godown(i+1,N,0),ans);
				ans = min(dp[0][i]+godown(i+1,N,1),ans);
		}
		printf("%lld\n",ans);
	}
}
