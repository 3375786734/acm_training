#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef vector<int> VV;
typedef pair<int,int> PP;
//const int maxn=;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,c,s;
		scanf("%I64d%I64d%I64d%I64d",&s,&a,&b,&c);
		ll tot=s/c,res=b*(tot/a);
		printf("%I64d\n",tot+res);
	}	
}
