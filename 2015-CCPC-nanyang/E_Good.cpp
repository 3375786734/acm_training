#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=;
struct Eg{
	int next,to,val;
};
Eg eg[maxn];
int egcnt,N,M;
void ag(int a,int b,int v)
{
	eg[cur]=(Eg){head[a],b,v};
	head[a]=cur++;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		MEM(head,-1);egcnt=0;
		for(int i=1;i<=M;i++){
			scanf("%d%d%d",&u,&v,&w);
			ag(u,v,w);ag(v,u,w);
		}
		
		printf("%d\n",ans);
	}
}
