#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef vector<int> VV;
typedef pair<int,int> PP;
const int maxn=1e5+100;
ll sum[maxn];
int main()
{
	ll N,M;
	scanf("%lld%lld",&N,&M);
	for(int i=0;i<=1e5;i++)
		sum[i]=(ll)(i+1)*(i)/2;
	ll lb=lower_bound(sum,sum+100002,M)-sum+1;
	ll ub=2*M>N?0:N-2*M;
	if(M>1)printf("%lld %lld\n",ub,N-lb);
	else printf("%lld %lld\n",ub,N);
}

