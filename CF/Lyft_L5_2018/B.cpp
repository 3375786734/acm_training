#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
//const int maxn=;

bool check(ll a){
	for(ll i=2;i*i<=a;i++)
		if(a%i==0)return false;
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		ll a,b;
		scanf("%lld%lld",&a,&b)	;
		ll m=max(a,b),M=min(a,b);
		if(m-M!=1)printf("NO\n");
		else{
			if(check(M+m))printf("YES\n");
			else printf("NO\n");
		}
	}
}
