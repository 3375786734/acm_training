/*
 *idea:SG
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int mod=242121643;
const int maxn=2000;
ll inv[maxn],fac[maxn],f[maxn];
int a[maxn];
int N,K;
ll C(ll n,ll m){
	if(m>n)return 0;
	//if(n==m||m==0)return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll qpow(ll a,ll n){
	ll ans=1;
	while(n!=0){
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}
/*
int c[maxn][maxn];

void init()
{
    c[0][0] = 1;
    for(int i = 1; i < maxn; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}
*/

void init()
{
	fac[0]=fac[1]=1;
	inv[0]=inv[1]=1;
	f[0]=f[1]=1;
	rep(i,2,1000){
		fac[i]=(fac[i-1]*i)%mod;
		f[i]=(mod-mod/i)*f[mod%i]%mod;
		inv[i]=inv[i-1]*f[i]%mod;
	}
	/*
	rep(i,1,1000)fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	inv[1000]=qpow(fac[1000],mod-2);
	for(int i=999;i>=2;i--)inv[i]=(inv[i+1]*(i+1))%mod;
	*/
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	init();
	while(scanf("%d%d",&N,&K)&&N!=0){
		//memset(b,0,sizeof(b));
		int num=0;
		rep(i,1,N)scanf("%d",&a[i]);
		rep(i,1,N)if(a[i]==1)num++;
		ll ans=0;
		for(int i=1;i<=min(K,num);i+=2)
			ans=(ans+C(num,i)*C(N-num,K-i)%mod)%mod;
		printf("%lld\n",ans);
		/*
		if(K%2==1){  // we need the sum be an even number
			ll even=b[0],odd=b[1];
			ll  ans=0;
			for(int i=odd/2*2;i>=0;i-=2){
				ans=(ans+C(odd,i)*C(even,K-i)%mod)%mod;
				ans%=mod;
			}
			printf("%lld\n",ans);
		}
		else{
			ll even=b[0],odd=b[1];
			ll ans=0;
			for(int i=(odd%2==0)?odd-1:odd;i>=1;i-=2){
				ans=(ans+C(odd,i)*C(even,K-i)%mod)%mod;
				ans%=mod;
			}
			printf("%lld\n",ans);
		}
		*/
	}
}
