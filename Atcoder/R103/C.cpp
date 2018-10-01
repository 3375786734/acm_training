#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int vis[2][maxn];
int main()
{
	int N,M,a[100010];
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	a[0]=2e5;
	for(int i=1;i<=N;i++)
			vis[i%2][a[i]]++;
//	sort(vis[0]+1,vis[0]+1+N,[&](int a,int b){return a>b;});
//	sort(vis[1]+1,vis[1]+1+N,[&](int a,int b){return a>b;});
	int p1=0,p2=0,pp1=0,pp2=0,m1=0,m2=0,mm1=0,mm2=0;
	for(int i=1;i<=1e5;i++)
		if(vis[0][i]>m1)
				m1=vis[0][i],p1=i;
	for(int i=1;i<=1e5;i++)
		if(vis[1][i]>m2)m2=vis[1][i],p2=i;
	for(int i=1;i<=1e5;i++)
		if(i!=p1&&vis[0][i]>mm1)mm1=vis[0][i],pp1=i;
	for(int i=1;i<=1e5;i++)
		if(i!=p2&&vis[1][i]>mm2)mm2=vis[1][i],pp2=i;
	if(p1!=p2)printf("%d\n",N-m1-m2);
	else printf("%d\n",N-max(m1+mm2,m2+mm1));

}
