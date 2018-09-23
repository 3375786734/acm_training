#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;


int main()
{
	ll l,r;
	scanf("%I64d%I64d",&l,&r);
	ll len =r-l+1;
	printf("YES\n");
	for(ll i=l;i<=r;i++){
		printf("%I64d %I64d\n",i,i+1);
		i++;
	}
}
