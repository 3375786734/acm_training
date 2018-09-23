#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b ) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
typedef vector<int> VI;
//const int maxn=;

int main()
{
	int N;
	scanf("%d",&N);
	int x,y,ans=0;
	rep(i,1,N){
		scanf("%d%d",&x,&y);
		ans=max(x+y,ans);
	}
	printf("%d\n",ans);
}
