#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxm=1e5+10;
const int maxn=1010;
const int INF=1e7;
typedef struct tagedge
{
	int next,to,val;
}Edge;
Edge  edge[maxm],reedge[maxm];
int N,cur,rcur,M,S,T,K,dist[maxn],vis[maxn],head[maxn],cnt[maxn],rhead[maxn];
class Node
{
public:
	int g,id;
	Node(int g=0,int id=0):g(g),id(id){}
	bool operator<(const Node &a) const
	{return dist[this->id]+this->g>dist[a.id]+a.g;}
};
void addedge(int a,int b,int v,int op)
{
	if(op==0)
	{
		edge[cur].next=head[a];
		edge[cur].to=b;
		edge[cur].val=v;
		head[a]=cur++;
	}
	else
	{
		reedge[rcur].next=rhead[a];
		reedge[rcur].val=v;
		reedge[rcur].to=b;
		rhead[a]=rcur++;
	}
}
struct cmpdj
{
	bool operator ()(int a,int b){return dist[a]>dist[b];}
};
void dj()
{
	memset(dist,0x3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<int,vector<int>,cmpdj>q;
	dist[T]=0;
	q.push(T);
	while(!q.empty())
	{
		int fa=q.top();
		q.pop();
		if(vis[fa]==1)continue;
		vis[fa]=1;
		for(int i=rhead[fa];i!=-1;i=reedge[i].next)
		{
			if(dist[reedge[i].to]>dist[fa]+reedge[i].val)
			{
				dist[reedge[i].to]=dist[fa]+reedge[i].val;
				q.push(reedge[i].to);
			}
		}
	}
}
int Astar()
{
	int cnt=0;
	priority_queue<Node>open;
	Node s(0,S);
	if(dist[S]>=INF)return -1;
	if(S==T)K++;
	open.push(s);
	while(!open.empty())
	{
		Node fa=open.top();
		open.pop();
		if(fa.id==T)cnt++;
//		if(cnt[fa.id]>K)continue;
		if(fa.id==T&&cnt==K)return fa.g;
		for(int i=head[fa.id];i!=-1;i=edge[i].next)
		{
			Node tmp(fa.g+edge[i].val,edge[i].to);
			open.push(tmp);
		}
	}
	return -1;
}
int main()
{

	scanf("%d%d",&N,&M);
	memset(head,-1,sizeof(head));
	memset(rhead,-1,sizeof(rhead));
	cur=rcur=0;
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c,0);
		addedge(b,a,c,1);		
	}
	scanf("%d%d%d",&S,&T,&K);
	dj();
	printf("%d\n",Astar());
}
