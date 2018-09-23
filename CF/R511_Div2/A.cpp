#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b ) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;

int main()
{
	int N;
	scanf("%d",&N);
	if((N-2)%3==0)printf("%d %d %d\n",1,2,N-3);
	else printf("%d %d %d\n",1,1,N-2);
}
