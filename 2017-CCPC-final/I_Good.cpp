/*
 *trick map中映射边的标号,保证a<b使得一条边只被记录一次
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define MEM(a,num) memset(a,num,sizeof(a))
#define pb push_back
const int maxn=4e5+100;
struct Eg{
	int u,v;
	Eg(int u,int v) : u(u),v(v){}
};
int circle[maxn],cir_cnt,cir_col,f[maxn],N,M;
map<Eg,int> eg;
map<int,int> color[maxn];
map<int,int> col_oncircle;
vector<Eg> eg_oncircle;
void dfs(int now,int pre)
{
	for(int to : vv[now]){
		if(to == pre)continue;
		fa[to] = now;
		if(vis[to] != -1)
			dfs(to,now);
		else {
			int tmp = to;
			while(tmp != to){
				circle[cir_cnt++] = tmp;
				tmp = fa[tmp];
			}
			return;
		}
	}
}
void get_circle()
{
	cir_col=0;MEM(circle,0);
	tarjan(1,1);
	circle[cir_cnt++] = circle[0];
	for(int i=0 ;i<cir_cnt-1;i++){
		int a = circle[i] , b = circle[i+1];
		if(a>b)swap(a,b);
		int col = eg[Eg(a,b)] ;
		if(!col_oncircle.count(col){
			col_oncircl[col]++;
			cir_col++;
		}
		eg_oncircle.insert((Eg){a,b});
	}
}
void init()
{
	MEM(circle,0);eg_oncircle.clear();
	rep(i,1,N)vv[i].clear();
	MEM(f,0);
}
int main()
{
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int ans=0;
		init();
		scanf("%d%d",&N,&M);
		int a,b,z;
		rep(i,1,N){
			scanf("%d%d%d",&a,&b,&z);
			if(a>b)swap(a,b);
			vv[a].pb(b);vv[b].pb(a);
			eg[Eg(a,b)]=z;
			if(!color[a].count(z))
				f[a]++;
			if(color[b].count(z))
				f[b]++;
			color[b][z]++;color[a][z]++;
		}
		get_circle();
		rep(i,1,N)ans+=f[i];
		rep(i,1,M){
			scanf("%d%d%d",&a,&b,&z);
			if(a>b) swap(a,b);
			int ori_color = eg(Eg(a,b));
			if(eg_oncircle.count(Eg(a,b))){
				if(col_oncircle[ori_color]==1)
					cir_col--;
				clo_oncircle[ori_color]--;
			}
				if(color[a][ori_color]==1)
					f[a]--,ans--;
				if(color[b][ori_color]==1)
					f[b]--,ans--;
				color[a][ori_color]--;color[b][ori_color]--;
				if(!color[a].count(z))
					f[a]++,ans++;
				if(!color[b].count(z))
					f[b]++,ans++;
				color[a][z]++;color[b][z]++;
			if(cir_col==1)printf("%d\n",N-ans);
			else printf("%d\n",N-1-ans);
		}

	}
}
