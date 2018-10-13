/*
 *differential constraint
 *trick 构造一个S为了使得所有的相对约束成立
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=3000;
const int maxm=1e7;
int a[maxn],b[maxn],c[maxn],d[maxn];
int S,N,M,X;
struct Eg{
	int next,to;
	ll val;
};
vector<Eg> vv;
int egcnt,head[maxn],cntv[maxn],v[maxn],vis[maxn];
ll dis[maxn];
void ag(int a,int b,int c){
	eg[egcnt]=(Eg){head[a],b,c};
	head[a]=egcnt++;
}
bool solve(int S)
{
	//MEM(vis,0);MEM(dis,0x3f3f3f);MEM(cntv,0);
	rep(i,0,N){
		cntv[i]=vis[i]=0;
		dis[i]=1e9+2000;
	}
	vis[S]=1;dis[S]=0;c[S]=1;
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int fa=q.front();q.pop();
		vis[fa]=0;
		for(int i = head[fa]; i != -1;i = eg[i].next){
			int id = eg[i].to;
			//printf("here fa %d eg %d\n",fa,id);
			if(dis[id]>dis[fa]+eg[i].val){
				dis[id]=dis[fa]+eg[i].val;
				if(!vis[id]){
					q.push(id);
					vis[id]=1;
					if(++cntv[id]>N)return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	int T,cas=1;
	//freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		egcnt=0;
		int ok=1;
		scanf("%d%d%d",&N,&M,&X);
		MEM(head,-1);
		rep(i,1,N){
			ag(0,i,0);
			if(i>1)ag(i,i-1,-1);
		}
		rep(i,1,M){
			scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
			//分类最简单的方法是分成尽可能细
			if(a[i]==b[i] && c[i]==d[i]){
				if(c[i]!=b[i])ag(a[i],b[i],X),ag(b[i],a[i],-X);
				else ok=0;
			}
			else if(a[i]==b[i]){
				if(b[i]==c[i])ag(d[i],a[i],-X-1);
				else{
					ag(a[i],c[i],X-1);
					ag(d[i],a[i],-X-1);
				}
			}
			else if(c[i]==d[i]){
				if(b[i]==c[i])ag(b[i],a[i],-X-1);
				else ag(b[i],c[i],X-1),ag(c[i],a[i],-X-1);
			}
			else {
				if(c[i]==b[i])ag(d[i],a[i],-X-1);
				else ag(b[i],c[i],X-1),ag(d[i],a[i],-X-1);
			}
		}
		printf("Case #%d: ",cas++);
		/*
		for(int i=head[1];i!=-1;i=eg[i].next)
			printf("%d\n",eg[i].to);
		*/
		if(ok){
			ok=solve(0);
			rep(i,2,N)if(dis[i]>2ll*1e9)ok=0;
			//rep(i,1,N)printf("dis %lld\n",dis[i]-dis[i-1]);
			if(!ok)printf("IMPOSSIBLE\n");
			else{
				rep(i,2,N)
					printf("%lld%c",dis[i]-dis[i-1],i==N?'\n':' ');
			}
		}
		else printf("IMPOSSIBLE\n");
	}
}
