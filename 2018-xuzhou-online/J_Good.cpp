/*
 *idea:首先假设所有的墙都建好了,现在由于每两个点之间只有一条路径,因此可以想到,所有的点到点之间的路径形成了一颗树,现在建立一颗最大生成树即可,并用LCA询问深度,只需要dep[u]+dep[v]-2*dep[lca(u,v)]即可
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=505;
const int maxm=5e5+100;
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
	int dep[maxn*maxn],anc[maxn*maxn][21],LOGN,maxdep;
	void init(){
//		anc[j][i]=anc[anc[j][i-1]][i-1];
		MEM(anc,-1);
		MEM(dep,0);
		maxdep=0;
	}
	int lca(int a,int b){
		int LOGN=(int)(log(maxdep*1.0)/log(2.0));
		//make sure dep[a]<dep[b];
		if(dep[a]>dep[b])swap(a,b);
		//then up b until a and b have almost the same dep;
		for(int i=LOGN;i>=0;i--)
			if(anc[b][i]!=-1&&dep[anc[b][i]]>=dep[a])
				b=anc[b][i];
		if(a==b) return a;
		for(int i=LOGN;i>=0;i--){
			//up it until we get the same anc;
			if(anc[a][i]!=anc[b][i]){
				a=anc[a][i];
				b=anc[b][i];
			}
		}
		return anc[a][0];
	}

	//get anc[v][1....LOGN]
	void Doubling()
	{
		int LOGN=(int)(log(maxdep*1.0)/log(2.0));
		for(int j=1;j<=LOGN;j++)
			for(int i=1;i<=N*M;i++)
				if(anc[i][j-1]!=-1)
					anc[i][j]=anc[anc[i][j-1]][j-1];
	}

	//get maxdep,dep,and anc[v][0]
	void dfs(int now){
		if(anc[now][0]!=-1)
			maxdep=max(maxdep,dep[now]=dep[anc[now][0]]+1);
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
//	rep(i,0,egnum)printf("eg %d %d %lld\n",eg[i].u,eg[i].v,eg[i].w);
	for(int i=0;i<egnum&&sz<N*M;i++){
		int a=eg[i].u,b=eg[i].v,ra=fd(a),rb=fd(b);
		if(ra==rb)continue;
		else{
//			printf("add %d %d\n",a,b);
			un(ra,rb);
			v[a].push_back(b);
			v[b].push_back(a);
			sz++;
		}
	}
//	printf("now %d %d\n",egnum,sz);
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
	cin>>N>>M;
	char dd,rr;
	ll cd,rd,Q;
	ll ans=0;
	egnum=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			int id=i*M+j+1,idr=i*M+(j+1)+1,idd=(i+1)*M+j+1;
			cin>>dd>>cd>>rr>>rd;
			if(rr!='X')eg[egnum++]=(Eg){id,idr,rd};
			if(dd!='X')eg[egnum++]=(Eg){id,idd,cd};
		}
	build();
	tt.init();
	tt.dfs(1);
	tt.Doubling();
	scanf("%d",&Q);
	int x,y,z,w;
	while(Q--){
		cin>>x>>y>>z>>w;
		cout<<slove((y-1)*M+x,(w-1)*M+z)<<endl;
	}
}
