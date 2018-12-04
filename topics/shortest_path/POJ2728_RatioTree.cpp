/*  -*- coding: utf-8 -*- */
/*
 *Note that: prim is faster than kruskal here .
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
const int maxn = 2e6+100;
const int maxm = 1e3+100;
const int inf = 100;
const double eps = 1e-6;
int N;
/*
struct Eg{
	int u,v;
	double dis;
	bool operator<(const Eg&a)const{
		return dis<a.dis;
	}
};
*/
struct Eg{
	int next,to;
	double dis;
	bool operator<(const Eg &a)const{
		return dis>a.dis;
	}
};
Eg eg[maxn];
int head[maxn],cur;
void ag(int a,int b,double v){
	eg[cur]= (Eg){head[a],b,v};
	head[a] = cur++;
}
int a[maxn],b[maxn],c[maxn],fa[maxn];
double dd[maxm][maxm],cc[maxm][maxm];
double cost(int u,int v){
	return fabs(c[u]-c[v]);
}
double dist(int u,int v){
	return sqrt(1.0*(a[u]-a[v])*(a[u]-a[v])+1.0*(b[u]-b[v])*(b[u]-b[v]));
}
/*
int fd(int a)
{
	if(a!=fa[a])return fa[a] = fd(fa[a]);
	else return a;
}
void un(int a,int b)
{
	int ra = fd(a),rb= fd(b);
	if(ra==rb)return ;
	fa[ra] = rb;
}
bool check(double mid)
{
	int cnt = 0;
	for(int i=1;i<=N;i++)
			fa[i] = i;
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++){
			eg[cnt++] = (Eg){i,j,cc[i][j]-mid*dd[i][j]};
		}
	sort(eg,eg+cnt);
	int sz = 0 ;
	double sum = 0;
	for(int i=0;i<cnt&&sz<N-1;i++)
	{
		int u = eg[i].u,v = eg[i].v;
		int ra = fd(u),rb = fd(v);
		if(ra == rb)continue;
		un(u,v);sz++;sum += eg[i].dis;
	}
	return sum>=0;
}
*/
int nearvex[maxn];
double lowcost[maxn];
bool check(double l)
{
    double cost = 0, len = 0;
    double sum = 0;
    for(int i = 1; i <= N; i++)
    {
        nearvex[i] = 1;
        lowcost[i] = cc[1][i] - dd[1][i] * l;
    }
    nearvex[1] = -1;
    for(int i = 1; i < N; i++)
    {
        double mi = 1e30;
        int v = -1;
        for(int j = 1; j <= N; j++)
            if(nearvex[j] != -1 && lowcost[j] < mi)
            {
                v = j;
                mi = lowcost[j];
            }
        if(v != -1)
        {
            cost += cc[nearvex[v]][v];
            len += dd[nearvex[v]][v];
            nearvex[v] = -1;
            sum += lowcost[v];
            for(int j = 1; j <= N; j++)
            {
                double tmp = cc[v][j] - dd[v][j] * l;
                if(nearvex[j] != -1 && tmp < lowcost[j])
                {
                    lowcost[j] = tmp;
                    nearvex[j] = v;
                }
            }
        }
    }
    return sum>=0;
}


/*
int vis[maxn];
bool check(double mid)
{
	priority_queue<Eg> q;
	for(int i=0;i<=N;i++)vis[i] = 0;
	int cnt = 0;
	double sum = 0;
	for(int i =1;i<=N;i++)
		for(int j =head[i];j!=-1;j=eg[j].next){
			int u = eg[j].to;
			eg[j].dis = cc[i][u] - mid*dd[i][u];
		}
	for(int i=head[1];i!=-1;i=eg[i].next)
		q.push(eg[i]);
	vis[1] = 1;
	while(!q.empty()&&cnt<N-1)
	{
		Eg fa = q.top(); q.pop();
		if(vis[fa.to])continue;
		sum += fa.dis;
		vis[fa.to] = 1;
		cnt++;
		for(int i=head[fa.to];i!=-1;i=eg[i].next){
			if(vis[eg[i].to]==0)q.push(eg[i]);
		}
	}
	return sum>=0;
}
*/
double solve()
{
	double l = 0,r= inf;
	while(r-l>eps){
		double mid = (l+r)/2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	return r;
}
int main()
{
	while(~scanf("%d",&N)&&N!=0){
		MEM(head,-1);cur=0;
		for(int i=1;i<=N;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);	
		}
		for(int i=1;i<=N;i++)
			for(int j =i+1;j<=N;j++)
				ag(j,i,0),ag(i,j,0),dd[i][j] = dd[j][i] = dist(i,j),cc[j][i] = cc[i][j] = cost(i,j);
		printf("%.3f\n",solve());
	}
}
