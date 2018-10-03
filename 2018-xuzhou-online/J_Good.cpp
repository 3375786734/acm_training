/*
 *idea:首先假设所有的墙都建好了,现在由于每两个点之间只有一条路径,因此可以想到,所有的点到点之间的路径形成了一颗树,现在建立一颗最大生成树即可,并用LCA询问深度,只需要dep[u]+dep[v]-2*dep[lca(u,v)]即可
 *trick:设置一个编码器,而不是一个一个的写坐标变换.
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=510;
const int maxm=6e5+100;
typedef long long ll;
typedef pair<int,int> PP;
typedef vector<int>::iterator VI;
int N,M,fa[maxm],egnum;
//ll cd[maxn][maxn],rd[maxn][maxn];
vector<int> v[maxm];
struct Eg{
	int v,u;
	ll w;
};
Eg eg[maxm];
struct LCA{
	int dep[maxn*maxn],anc[maxn*maxn][26];
	void init(){
//		anc[j][i]=anc[anc[j][i-1]][i-1];
		MEM(anc,-1);
		MEM(dep,0);
		maxdep=0;
	}
	int lca(int a,int b){
		//int LOGN=(int)(log(maxdep*1.0)/log(2.0));
		int LOGN=0;
		while((1<<LOGN)<=N*M)LOGN++;
		LOGN--;
		//make sure dep[a]<dep[b];
		if(dep[a]>dep[b])swap(a,b);
		//then up b until a and b have almost the same dep;
		for(int i=LOGN;i>=0;i--)
			if(dep[b]-(1<<i)>=dep[a])
				b=anc[b][i];
		if(a==b) return a;
		for(int i=LOGN;i>=0;i--){
			//up it until we get the same anc;
			if(anc[a][i]!=-1&&anc[a][i]!=anc[b][i]){
				a=anc[a][i];
				b=anc[b][i];
			}
		}
		return anc[a][0];
	}
	//get anc[v][1....LOGN]
	void Doubling()
	{
		//int LOGN=(int)(log(N*M*1.0)/log(2.0));
		for(int j=1;(1<<j)<=N*M;j++)
			for(int i=1;i<=N*M;i++)
				if(anc[i][j-1]!=-1)
					anc[i][j]=anc[anc[i][j-1]][j-1];
	}
	//get maxdep,dep,and anc[v][0]
	void dfs(int now){
		dep[now]=dep[anc[now][0]]+1;
		for(VI vi=v[now].begin();vi!=v[now].end();vi++){
			int id = *vi;
			if(id==anc[now][0])continue;
			anc[id][0]=now;
			dfs(id);
		}
	}
}tt;

int fd(int a){
	if(fa[a]==a)return a;
	else return fa[a]=fd(fa[a]);
}
void un(int a,int b){
	int ra=fd(a),rb=fd(b);
	if(ra==rb)return ;
	fa[ra]=rb;
}
void build()
{
	int sz=0;
	for(int i=1;i<=M*N;i++)fa[i]=i;
	sort(eg,eg+egnum,[&](Eg a,Eg b){return a.w>b.w;});
	for(int i=0;i<egnum;i++){
		int a=eg[i].u,b=eg[i].v,ra=fd(a),rb=fd(b);
		if(ra==rb)continue;
		else{
			//printf("add %d %d\n",a,b);
			un(ra,rb);
			v[a].push_back(b);
			v[b].push_back(a);
			sz++;
		}
	}
}

ll slove(int a,int b){
//	printf("now at %d %d %d\n",a,b,tt.maxdep);
//	printf("%d %d %d %d\n",tt.dep[a],tt.dep[b],tt.lca(a,b),tt.dep[tt.lca(a,b)]);
	return tt.dep[a]+tt.dep[b]-2*tt.dep[tt.lca(a,b)];
}
int index(int x,int y){
	return (x-1)*M+y;
}
int main()
{
	//freopen("t.in","r",stdin);
	cin>>N>>M;
	char dd,rr;
	ll cd,rd,Q;
	egnum=0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			for(int k=0;k<2;k++){
				cin>>dd>>cd;
				if(dd!='X'){
					int id=index(i,j),idr=index(i,j+1),idd=index(i+1,j);
					if(dd=='R')eg[egnum++]=(Eg){id,idr,cd};
					if(dd=='D')eg[egnum++]=(Eg){id,idd,cd};
				}
			}
		}
	build();
	tt.init();
	tt.dfs(1);
	tt.Doubling();
	cin>>Q;
	int x,y,z,w;
	while(Q--){
		cin>>x>>y>>z>>w;
		cout<<slove((y-1)*M+x,(w-1)*M+z)<<endl;
	}
}
