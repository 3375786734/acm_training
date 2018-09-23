#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int a[maxn],p[maxn];
int main()
{
	int N,D,ans=0;
	scanf("%d%d",&N,&D);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=N;i++)
		scanf("%d",&p[i]);
	int cur=a[D]+p[1],ps=2;
	for(int i=D-1;i>=1;i--){
		while(ps<=N&&a[i]+p[ps]>cur)ps++;
		if(ps>N)break;
		ps++;
		ans++;
	}
	printf("%d\n",D-ans);
}
