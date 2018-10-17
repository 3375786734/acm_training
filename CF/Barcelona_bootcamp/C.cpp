#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=2005;
ll mm[maxn][maxn],ans;
ll pre[maxn][maxn],x;
int a[maxn],b[maxn];
ll get_sum(int x1,int y1,int x2,int y2){
	return pre[y2][x2]-(pre[y1-1][x2]+pre[y2][x1-1]-pre[y1-1][x1-1]);
}
bool check(int x1,int x2,int y1,int y2){
	if(get_sum(x1,y1,x2,y2) > x)return true;
	else return false;
}
ll bsrch(int l,int r,int u,int d){
	int uu=u;

	while(u<=d){
		int mid = (u+d)/2;
		//printf("mid %d %d %d %d %d %d\n",u,mid,d,l,r,check(l,r,u,mid));
		if(check(l,r,uu,mid))d=mid-1;
		else u=mid+1;
	}
	printf("here %d %d %d %d\n",l,r,uu,d);
	printf("return %d\n",get_sum(l,uu,r,d));
	return	get_sum(l,uu,r,d); 
}
int main()
{
	freopen("t.in","r",stdin);
	int N,M;
	scanf("%d%d",&N,&M);
	rep(i,1,N)scanf("%d",&a[i])	;
	rep(i,1,M)scanf("%d",&b[i]) ;
	rep(i,1,N)
		rep(j,1,M){
			mm[i][j] = a[i]*b[j];
		}
	rep(i,1,N)
		rep(j,1,M)
			pre[i][j] = pre[i-1][j]-pre[i-1][j-1]+mm[i][j]+pre[i][j-1];
	/*
	rep(i,1,N){
		rep(j,1,M)
				printf("%lld",get_sum(i,j,i,j));
		printf("\n");
	}
	*/
	printf("sum %d ",get_sum(1,1,2,2));
	scanf("%lld",&x);
	ll ans=0;
	for(int i=1;i<=N;i++){
		int head=1;
		for(int tail=1;tail<=M;tail++){
			if(head<tail&&check(head,tail,i,i))head++;
			//printf("here\n");
			if(check(head,tail,i,i))continue;
			//printf("here\n");
			ans=max(ans,bsrch(head,tail,i,N));
		}
	}
	printf("%d\n",ans);
}
