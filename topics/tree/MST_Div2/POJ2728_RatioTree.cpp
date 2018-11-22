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
const int maxn = ;
int N,head[maxn],cur;
struct Eg
{
	int next,to;
	double dis,cc;
};
Eg eg[maxn];
void ag(int a,int b,double dis,double c)
{
	eg[cur] = (Eg){head[a],b,dis,c};
	head[a] = cur++;
}

int fd(int a){
	if(fa[a]!=a)return fa[i] = fd(fa[i]);
	else return a;
}
void un(int a,int b)
{
	int ra =fd(a),rb= fd(b);
	if(ra==rb)return;
	fa[ra]  =rb; 
}
double MST()
{
}
double solve()
{
	
}
int main()
{
	while(scanf("%d",&N)&&N!=0)
	{
		MEM(head,-1);cur = 0;
		for(int i=1;i<=N;i++)
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
		for(int i=1;i<=N;i++)
			for(int j=i+1;j<=N;j++){
			}
		printf("%lf\n",solve());
	}
}

