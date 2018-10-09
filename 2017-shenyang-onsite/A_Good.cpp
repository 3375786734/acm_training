/*
 *IDEA:只要对公式进行截尾,满足精度要求即可,然后我们为了提取第n位,可以先乘上16^n,
 *然后截尾十分容易,考虑保留前n项,考虑n很大的时候1/(8n)将变得非常小,而另一部分几何级数的和最多也只有16/15,因此他们整体将对答案影响微乎其微.可以直接截去

 * trick: 由于16^(n)可能比较大,我们先留一位,取分母的模不会对小数产生影响之后再还原.
 
 * 细节问题:取模之后可能会出现负数的情形+1即可
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
//注意这里的精度可能会炸
ll qpow(ll a,ll n,ll mod){
	ll ans=1;
	while(n!=0){
		if(n&1)ans=ans*a%mod;
		n>>=1;a=a*a%mod;
	}
	return ans;
}
double BBP(int d,int k,int n){
	if(n>=k)return (double)qpow(16,n-k,8*k+d)/(8*k+d);
	else return powf(16,n-k)/(8*k+d);
}
char solve(int n)
{
	double ans=0;
	for(int i=0;i<=n;i++)
		ans+=4*BBP(1,i,n)-2*BBP(4,i,n)-BBP(5,i,n)-BBP(6,i,n);
	double res=ans-(ll)ans;
	if(res<0)res+=1.0;
	int num=(int)(res*16.0);
	//printf("%lf %lld",res,num);
	if(num<10)return num+'0';
	else return num-10+'A';
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		printf("Case #%d: %d %c\n",cas++,N,solve(N-1));
	}
}
