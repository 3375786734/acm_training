#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=3000;
ll mm[maxn][maxn];
ll pre[maxn][maxn],x;
int a[maxn],b[maxn];
ll get_sum(int x1,int y1,int x2,int y2){
	return pre[y2][x2]-(pre[y1-1][x2]+pre[y2][x1-1]-pre[y1-1][x1-1]);
}
bool check(int x1,int x2,int y1,int y2){
	if(get_sum(x1,y1,x2,y2) > x)return true;
	else return false;
}
int bsrch(int l,int r,int u,int d){
	int uu=u;
	while(u<=d){
		int mid = (u+d)/2;
		//printf("mid %d %d %d %d %d %d\n",u,mid,d,l,r,check(l,r,u,mid));
		if(check(l,r,uu,mid))d=mid-1;
		else u=mid+1;
	}
	return u-1;
}
int main()
{
	freopen("t.in","r",stdin);
	int N,M;
	while(~scanf("%d%d",&M,&N)){
	rep(i,1,M)scanf("%d",&a[i]);
	rep(i,1,N)scanf("%d",&b[i]);
	rep(i,1,N)
		rep(j,1,M)
			mm[i][j] = a[j]*b[i];
	rep(i,1,N)
		rep(j,1,M)
			pre[i][j] = pre[i-1][j]-pre[i-1][j-1]+mm[i][j]+pre[i][j-1];
	/*
	rep(i,1,N)
		rep(j,1,M)
			printf("%lld\n",pre[i][j]);
	*/
	scanf("%lld",&x);
	int ans=0;
	for(int i=1;i<=N;i++){
		int head=1;
		for(int tail=1;tail<=M;tail++){
			while(head<tail&&!check(head,tail,i,i))head++;
			if(!check(head,tail,i,i))continue;
			ans=max(ans,(bsrch(head,tail,i,N)-i+1)*(tail-head+1));
		}
	}
	printf("%d\n",ans);
	}
}
