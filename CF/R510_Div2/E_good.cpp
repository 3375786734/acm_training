/*
 *题意:给一个矩阵,和一个chip,chip中存放的是一个矩阵中的数,每次都等可能的从中取出一个比当前数小的放到chip中并得到上面的分数,问分数的期望值是多少
 *1.求后缀和
 *2.注意有相同值的元素
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
typedef pair<ll,PP> NN;
const int maxn=1e6+100;
const int mod= 998244353;
int N,M;
ll dp[maxn],sqs[2][maxn],ls[2][maxn],a[1005][1005];
set<NN> ss;
ll inv(ll a, ll  m=mod) {
 a %= m; if (a < 0) a += m;
 return a == 1 ? a : int(m - ll(inv(m, a)) * ll(m) / a);
}
int main()
{
	scanf("%d%d",&N,&M);
	rep(i,1,N){
		rep(j,1,M){
			scanf("%lld",&a[i][j]);
			ss.insert(NN(a[i][j],PP(i,j)));
		}
	}
	int r,c;
	ss.insert(NN(-1,PP(-1,-1)));
	scanf("%d%d",&r,&c);
	int sz=1;
	set<NN>::iterator si=--ss.lower_bound(NN(a[r][c],PP(r,c)));
	for(set<NN>::iterator it=--ss.end();it!=si;it--){
		ll yy=(it->second).first,xx=(it->second).second;
		sqs[0][sz]=sqs[0][sz-1]+yy*yy;
		sqs[1][sz]=sqs[1][sz-1]+xx*xx;
		ls[0][sz]=ls[0][sz-1]+yy;
		ls[1][sz]=ls[1][sz-1]+xx;
		sz++;
		printf("now %lld %lld %lld %lld %lld %lld\n",xx,yy,sqs[0][sz],sqs[1][sz],ls[0][sz],ls[1][sz]);
	}
	int cur=1;
	ll pre=0;
	for(set<NN>::iterator it=--ss.end();it!=si;it--){
		ll xx=(it->second).first,yy=(it->second).second;
		int pid=cur-1;
		dp[cur]=(pre+-2*xx*ls[1][pid]+mod-2*yy*ls[0][pid]+mod+sqs[0][pid]+sqs[1][pid])%mod*inv(cur-1)%mod;
		pre+=dp[cur];
		cur++;
	}
	printf("%lld\n",dp[cur-1]);
}
