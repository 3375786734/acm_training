/*
 *idea:首先假设所有的墙都建好了,现在由于每两个点之间只有一条路径,因此可以想到,所有的点到点之间的路径形成了一颗树,现在建立一颗最大生成树即可,并用LCA询问两点之间的距离.
 *
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=505;
typedef long long ll;
typedef pair<int,int> PP;
int N,M;
ll cd[maxn][maxn],rd[maxn][maxn];
vector<int> v[maxm];
struct Eg{
	ll v,u,w;
};
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
	sort(eg,eg+cnt,[&](Eg a,Eg b){return a.w>b.w;});
	for(int i=0;i<cnt&&sz<N;i++){
		int a=eg[i].u,b=eg[i].v,ra=fd(a),rb=fd(b);
		if(ra==rb)continue;
		else{
			un(a,b);
			v[a].push_back(b);
			v[b].push_back(a);
			sz++;
		}
	}
}
ll slove(int a,int b){

}
int main()
{
	cin>>N>>M;
	char dd,rr;
	ll ans=0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			cin>>dd>>cd[i][j]>>rr>>rd[i][j];
			ans+=cd[i][j]+rd[i][j];
			eg[cnt++]=(Eg){}
		}
	scanf("%d",&Q);
	while(Q--){
		printf("%lld\n",ans-slove());
	}
}
