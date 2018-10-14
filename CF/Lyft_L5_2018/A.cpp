#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
//const int maxn=;
int main()
{
	int N,ax,ay,bx,by,cx,cy;
	scanf("%d",&N);
	scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
	int ok=1;
	if(by>ay&&cy<=ay)ok=0;
	if(by<ay&&cy>=ay)ok=0;
	if(bx<ax&&cx>=ax)ok=0;
	if(bx>ax&&cx<=ax)ok=0;
	if(cy==cx+ay-ax)ok=0;
	//cy>=cx+ay-ax)ok=0;
	if(cy==ay+ax-cx)ok=0;
	//if(by<ay+ax-bx&&cy>=ay+ax-cx)ok=0;
	if(ok==1)printf("YES\n");
	else printf("NO\n");
}
