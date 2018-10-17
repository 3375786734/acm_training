#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=50;
ll b[maxn],bits[maxn];
ll ans(ll a,ll b){
    ll ans=0;
    while(a){
        ans+=a%10;
        a/=10;
    }
    while(b){
        ans+=b%10;
        b/=10;
    }
    return ans;
}
int main()
{
    ll N,a;
	b[0]=1;bits[0]=0;
	for(int i=1;i<13;i++)b[i]=b[i-1]*10;
    for(int i=1;i<13;i++)bits[i]=b[i]-1;
	scanf("%lld",&N);
	for(int i=0;i<=12;i++)
		if(bits[i]<=N)a=bits[i];
		else break;
	printf("%lld\n",ans(a,N-a));
}

