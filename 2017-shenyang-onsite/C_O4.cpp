#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=200;
int N;
struct Node{
	int x,y;
	Node operator - (const Node &a)const{
		return (Node){x-a.x,y-a.y};
	}
};
Node nn[maxn];
double dp[maxn][maxn];
struct CH{
	int sz;
	Node node[maxn];
}tmp;
double cross(Node o,Node a,Node b){
	int xa = a.x-o.x , ya = a.y-o.y;
	int xb = b.x-o.x , yb = b.y-o.y;
	return a.x*b.y-a.y*b.x;
}
bool cmpy(Node a,Node b){
	if(a.y == b.y)return a.x < b.x;
	else return a.y < b.y;
}
int dist(Node a){
	return a.x*a.x + a.y*a.y;
}
bool cmpa(Node a,Node b){
	Node ori = tmp.node[0];
	int op = cross(ori,a,b);
	if(op == 0)return dist(a-ori) < dist(b-ori);
	else return op>0;
}
double S(Node a,Node b,Node O){
	//printf("here %d %d  %d  %d %lf\n",a.x,a.y,b.x,b.y,cross(O,a,b));
	return 0.5*fabs(cross(O,a,b));
}
bool isin(Node a,Node b)
{
	if(b.x*a.y - b.y*a.x>0)return true;
	else return false;
}
bool check(Node a,Node b,int il,int ir)
{
	Node ori = nn[il-1];
	rep(i,il,ir){
		Node tt = tmp.node[i]-ori;
		if(isin(a-tt,b-tt))return false;
	}
	return true;
}
double solve()
{
	double ans=0;
	sort(nn+1,nn+1+N,cmpy);
	rep(O,1,N){
		Node ori = (Node){nn[O].x,nn[O].y};
		tmp.sz = 0;
		MEM(dp,0);
		printf("ori at %d %d\n",ori.x,ori.y);
		rep(i,O,N) tmp.node[tmp.sz++] = (Node){nn[i].x,nn[i].y};
		sort(tmp.node,tmp.node+tmp.sz,cmpa);
		rep(i,0,tmp.sz-1)printf("tmp at %d %d\n",tmp.node[i].x,tmp.node[i].y);
		dp[2][1] = S(tmp.node[1],tmp.node[2],nn[O]);
		ans = max(ans,dp[2][1]);
		//printf("here ans %lf\n",ans);
		for(int i=1;i<tmp.sz;i++)
			for(int j=1;j<i;j++){
				if(check(tmp.node[i]-ori,tmp.node[j]-ori,O+1,i)){
					for(int k=1;k<j;k++)
						dp[i][j] = max(dp[i][j],S(tmp.node[i],tmp.node[j],nn[O])+dp[j][k]);
					ans = max(dp[i][j],ans);
					printf("dp[%d][%d]:%lf\n",i,j,dp[i][j]);
				}
			}
	}
	return ans;
}
int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		printf("Case\n");
		scanf("%d",&N);
		int x,y;
		rep(i,1,N){
			scanf("%d%d",&x,&y);
			nn[i] = (Node){x,y};
		}
		printf("%.1lf\n" , solve());
	}
}
