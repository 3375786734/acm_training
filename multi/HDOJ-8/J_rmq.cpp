#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn=1e5+100;
int st[maxn][20],N,M;
int dl[maxn],dr[maxn],h[maxn];
void init()
{
	rep(i,1,N)st[i][0]=i;
	for(int j=1;(1<<j)<=N;j++)
		for(int i=1;i<=N;i++)
			if(i+(1<<j)-1<=N){
				if(h[st[i][j-1]]>=h[st[i+(1<<(j-1))][j-1]])
				st[i][j]=st[i][j-1];
				else st[i][j]=st[i+(1<<(j-1))][j-1];
			}
}
int rmq(int a,int b)
{
	if(a>b)swap(a,b);
	if(a<=0||b<=0)return 0;
	if(a>N||b>N)return N+1;
	int k=0;
	while((1<<(k+1))<=(b-a+1))k++;
	if(h[st[a][k]]>h[st[b-(1<<k)+1][k]])return st[a][k];
	else return st[b-(1<<k)+1][k];
}
int find(int l,int r,int val)
{
	if(l>r)return 0;
	if(h[rmq(l,r)]<=val)return 0;
	while(r>l)
	{
//		printf("now %d %d",l,r);
		int mid=(l+r)/2;
		if(h[rmq(l,mid)]<=val)
			l=mid+1;
		else r=mid;
//		else return 0;
	}
	return l;
}
int main()
{
	int T;
//	freopen("j.in","r",stdin);
//	freopen("j.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		MEM(dl,0);MEM(dr,0);
		scanf("%d%d",&N,&M);
		int MM=0;
		rep(i,1,N)
		{
			scanf("%d",&h[i]);
			if(h[i]>MM){
				MM=h[i];dl[i]=dl[i-1]+1;
			}
			else dl[i]=dl[i-1];
		}
		printf("rmq1.4 %d\n",rmq(1,4));
		init();
		dep(i,N,1){
			int pr=find(i+1,N,h[i]);
			dr[i]=dr[pr]+1;
//			printf("ps %d\n",pr);
		}
		rep(i,1,M){
			int ans=0,pp,hh;
			scanf("%d%d",&pp,&hh);
			int pl=rmq(1,pp-1);
			if(h[pl]<hh)ans+=dl[pl]+1;
			else ans+=dl[pl];
			int pr=find(pp+1,N,hh);
			ans+=dr[pr];
			printf("pl%d pr%d dl%d dr%d ans%d\n",pl,pr,dl[pl],dr[pr],ans);	
	//		printf("%d\n",ans);
		}
	}	
}
