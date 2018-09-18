/*
 *题意要求一个括号序列的平均入栈到出栈的时间
 * idea:常规想法是按每个序列进行统计求出入栈时间的总和
 * 换一种想法,由于如果固定一个括号对,其时间是非常容易求的
 * 因此如果按(i,j)的等待时间进行求和,那么计算将变得容易
 * 具体的(i,j)固定,那么合法的序列有Catalan(len-1)*Catalan(N-len)个,其中len对应这(i,j)序列长度为2*len,中间的必须要匹配,因此固定长度(i,j),时间是dtim*Catalan(len-1)*Catalan(N-len)
 *然后注意到长度为2×len的括号对的等待时间可以用前缀和表示,因此问题的求解变得十分容易了
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int N;
ll p,pre[maxn],a[maxn],fac[2*maxn],inv[maxn*2],catalan[maxn];
ll qpow(ll a,ll n){
	ll ans=1;
	while(n){
		//!!
		if(n&1)ans=ans*a%p;
		a=a*a%p;n>>=1;
	}
	return ans%p;
}

//注意这里求catalan数的方法,将其转化成阶乘形式
ll Catalan(ll n){
    if(n==0)return 1;
    ll ret=fac[2*n];
    ret=ret*inv[n+1]%p;
    ret=ret*inv[n]%p;
    return ret;
}
void init()
{
	fac[0]=1;
	rep(i,1,2*N)fac[i]=fac[i-1]*i%p;
	inv[0]=inv[1]=1;// 注意初始化
	inv[2*N]=qpow(2*N,p-2);
	dep(i,2*N-1,2)inv[i]=inv[i+1]*(i+1)%p;
	catalan[0]=1;
	rep(i,1,N)catalan[i]=Catalan(i);
}
/*
void init(){
    inv[0]=inv[1]=1;
    fac[0]=fac[1]=1;
    for(int i=2;i<=2*N;i++){
        inv[i]=inv[p%i]*(p-p/i)%p;
        fac[i]=fac[i-1]*i%p;
    }
    for(int i=1;i<=2*N;i++){
        inv[i]=inv[i-1]*inv[i]%p;
    }
}
*/
int main()
{
	int T;
//	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		ll b,A,B;
		scanf("%d%lld%lld%lld%lld",&N,&p,&b,&A,&B);
		init();
		rep(i,1,2*N){
			b=(A*b+B)%p;
			a[i]=a[i-1]+b+1;
		}
		ll ans=0;
		//可以直接使用a[i]求前缀和
		rep(i,1,2*N)pre[i]=(pre[i-1]+a[i])%p;
		for(int i=1;i<=N;i++){
			ll d=((pre[2*N]-pre[2*i-1])-pre[2*N-2*i+1]+2*p)%p;
			ans+=d*catalan[i-1]%p*catalan[N-i]%p;
			ans%=p;
		}
		ans=ans*qpow(catalan[N],p-2)%p;
		printf("%lld\n",ans%p);
	}

}
