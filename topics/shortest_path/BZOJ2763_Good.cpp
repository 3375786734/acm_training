/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
const int maxn = 1e4+10; 
const int maxk = 20;
const int inf = 1e9;
int N,M,K;
struct Eg{
	int id,dis;
	Eg(int id,int dis):id(id),dis(dis){}
};
vector<Eg> vv[maxn];
int dp[maxn][maxk],S,T,vis[maxn][maxk];
struct Node{
	int id,res,dis;
	bool operator<(const Node &a)const{
		return dis>a.dis;
	}
	Node(int id,int res,int dis):id(id),res(res),dis(dis){}
};
int solve()
{
	MEM(dp,0x3f3f3f);MEM(vis,0);
	priority_queue<Node> q;
	q.push(Node(S,K,0));
	dp[S][K] = 0;
	while(!q.empty())
	{
		Node fa =q.top();q.pop();
		int id =fa.id,res = fa.res;
		if(vis[id][res])continue;
		vis[id][res] = 1;
		for(vector<Eg>::iterator it = vv[id].begin();it!=vv[id].end();it++){
			Eg vi = *it;
			//典型的dp方式,两种方法中进行选择.
			if(res>0&&dp[id][res]<dp[vi.id][res-1]&&!vis[vi.id][res-1]){
				dp[vi.id][res-1] = dp[id][res];
				q.push(Node(vi.id,res-1,dp[vi.id][res-1]));
			}
			if(dp[id][res]+vi.dis<dp[vi.id][res]&&!vis[vi.id][res]){
			   	dp[vi.id][res] = min(dp[vi.id][res],dp[id][res]+vi.dis);
				q.push(Node(vi.id,res,dp[vi.id][res]));
			}
		}
	}
	return dp[T][0];
}
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	scanf("%d%d",&S,&T);S++,T++;
	int a,b,c;
	rep(i,1,M){
		scanf("%d%d%d",&a,&b,&c);a++,b++;
		vv[a].pb(Eg(b,c));vv[b].pb(Eg(a,c));
	}
	printf("%d\n",solve());
}

