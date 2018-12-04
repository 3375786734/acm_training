/*  -*- coding: utf-8 -*- */
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
const int maxn = 1005; 
const int maxc = 105;
int N,M,S,E,p[maxn],cap;
struct Eg{
	int id,dis;
	Eg(int id = 0,int dis = 0):id(id),dis(dis){}
};
struct Node
{
	int id,res,dis;
	bool operator<(const Node &a)const{
		return dis>a.dis;
	}
	Node(int id,int res,int dis):id(id),res(res),dis(dis){}
};
vector<Eg> eg[maxn];
int dp[maxn][maxc],vis[maxn][maxc];
//一共1e7种状态.
int bfs()
{
	MEM(dp,0x3f3f3f);MEM(vis,0);
	priority_queue<Node> q;
	dp[S][0] = 0;
	q.push(Node(S,0,0));
	while(!q.empty())
	{
		Node fa =q.top();q.pop();
		int id =fa.id ,res =fa.res;
		if(vis[id][res])continue;
		//printf("%d %d %d\n",id,res,fa.dis);
		vis[id][res] = 1;
		if(id == E)return fa.dis;
		if(res+1<=cap&&dp[id][res+1]>dp[id][res]+p[id]&&!vis[id][res+1]){
			dp[id][res+1] = dp[id][res]+p[id];
			q.push(Node(id,res+1,dp[id][res+1]));
		}
		for(vector<Eg>::iterator it = eg[id].begin();it!=eg[id].end();it++){
			Eg vi = *it;
			if(res>=vi.dis&&dp[vi.id][res-vi.dis]>dp[id][res]&&!vis[vi.id][res-vi.dis]){
				dp[vi.id][res-vi.dis] = dp[id][res];
				q.push(Node(vi.id,res-vi.dis,dp[id][res]));
			}
		}
	}
	return -1;
}
int main()
{
	freopen("t.in","r",stdin);
	while(~scanf("%d%d",&N,&M)){
		rep(i,1,N)scanf("%d",&p[i]);
		rep(i,1,N)eg[i].clear();
		int a,b,c;
		rep(i,1,M){
			scanf("%d%d%d",&a,&b,&c);a++,b++;
			eg[a].pb(Eg(b,c));eg[b].pb(Eg(a,c));
		}
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d%d%d",&cap,&S,&E);S++,E++;
			int ans = bfs();
			if(ans == -1)printf("impossible\n");
			else printf("%d\n",ans);
		}
	}
}

