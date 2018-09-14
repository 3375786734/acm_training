#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e6;
long long ss[maxn];
bool nosq(LL a){
	LL k=sqrt(a);
	return k*k<a;
}
void init(int &cnt){
	LL inf=1e18;
	for(LL i=2;i<=1e6;i++){
//		if(1LL*i*i*i>=inf)break;
		LL tt=1LL*i*i;
		//注意这里 1e18<=1e18  但是再乘上 1e6之后超范围!处理技巧,判断除法而不是乘法
		while(tt<=inf/i){
			tt*=i;
			if(nosq(tt))ss[cnt++]=tt;
		}
	}
	sort(ss,ss+cnt);
	cnt=unique(ss,ss+cnt)-ss;
}
int main()
{
	int T,cnt=0;
	scanf("%d",&T);
	init(cnt);
	LL n;
	for(int i=1;i<=T;i++){
		LL ans=0;
		scanf("%I64d",&n);
		ans+=(LL)(sqrt(n))-1;
//		printf("ans %lld\n",ans);
		//注意这里应该用upper bound！
		ans+=upper_bound(ss,ss+cnt,n)-ss;
		printf("%I64d\n",n-1-ans);
	}
}
