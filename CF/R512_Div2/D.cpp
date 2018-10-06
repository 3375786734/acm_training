#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=;

double bsrch(int )
int main()
{
	int N;
	scanf("%d",&N);
	int pre=0,ok=1,maxy=1e7+100,miny=-1e7-100;
	rep(i,1,N){
		scanf("%d%d",&x[i],&y[i]);
		miny=min(miny,y[i]);
		maxy=max(maxy,y[i]);
	}
	if(miny<0&&maxy>0)printf("-1\n");
	else printf("%lf\n",bsrch());
}
