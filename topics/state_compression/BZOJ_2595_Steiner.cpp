/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
const int maxn = 12;
int N,M;
int dp[maxn][maxn][(1<<12)];
vector<PP> vv;
struct Eg{
	int to,dis;
};
vector<Eg> eg[maxn*maxn];
struct Node{
	int id,dis;
	bool operator<(const Node &a)const{
		return dis>a.dis
	}
};

void dj()
{
	MEM(dis,0x3f33f);MEM(vis,0);
	priority_queue<Node> q;
	q.push((Node){});
	while(!q.empty())
	{
		Node fa = q.top();q.pop();
		int id = fa.to;
		if(vis[id])continue;
		vis[id] = 1;
		for(Eg ei :eg){
			if(dis[ei.to]<dis[id]+ei.dis){
				dis[ei.to] = dis[id]+ei.dis;
				
			}
		}
	}
}
int Abs(int a){return a>0?a:-a;}
int main()
{
	scanf("%d%d",&N,&M);
	int sz= 0;
	for(int i=0;i<=N;i++)
		for(int  j =0;j<M;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j] == 0)vv.pb(PP(i,j)),sz++;
		}
	for(PP vi :vv)
		for(PP vj:vv){
			if(vi!=vj)eg.pb((Eg){Abs(vi.fi-vj.fi)+Abs(vi.se-vj.se)});
		}
	for(PP vi :vv){
		int i = vi.fi,j = vi.se;
		for(int s = 0;s<(1<<sz);s++)
			for(int k =0;k<(1<<sz);k++){
				if(k)dp[i][j][s]  = min(dp[i][j][s],dp[i][j][s^k]+dp[i][j][k]);
			}
	}
	dj();
	printf("%d\n",dp[i][j][(1<<sz)-1]);
}

