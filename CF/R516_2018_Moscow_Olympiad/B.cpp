#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get_b(int a)
{
	int b[1000],sz=0;
	ll cnt=1;
	while(a){
		b[sz++]=a&1;
		a>>=1;
	}
	for(int i=0;i<sz;i++)
		if(b[i]==1)cnt=cnt*2;
	return cnt; 
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a;
		scanf("%d",&a);
		printf("%lld\n",get_b(a));
	}
}
