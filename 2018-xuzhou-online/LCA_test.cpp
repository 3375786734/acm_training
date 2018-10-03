//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e4+100;
vector<int> v[maxn];
int N,vis[maxn];
class LCA{
public:
	int maxdep,LOGN,dep[maxn],anc[maxn][19];
	void swap(int &a,int &b)
	{
		int t=a;
		a=b;b=t;
	}
	void init(){
		maxdep=0;
		MEM(dep,0);
		MEM(anc,-1);
	}
	void dfs(int now)
	{
		if(anc[now][0]!=-1){
			maxdep=max(maxdep,dep[now]=dep[anc[now][0]]+1);
		}
		for(vector<int>::iterator it=v[now].begin();it!=v[now].end();it++)
		{
			if(anc[now][0]==*it)continue;
			anc[*it][0]=now;
			dfs(*it);
		}
	}
	void doubling()
	{
		//LOGN=(int)(log(maxdep)/log(2.0));
			for(int j=1;(1<<j)<=N;j++)
				for(int i=1;i<=N;i++)
					anc[i][j]=anc[anc[i][j-1]][j-1];
	}
	int lca(int a,int b)
	{
		LOGN=0;
		while((1<<LOGN)<=N)LOGN++;
		LOGN--;
		if(dep[a]>dep[b])swap(a,b);
		for(int i=LOGN;i>=0;i--)
			if(dep[b]-(1<<i)>=dep[a])
				b=anc[b][i];
		if(a==b)return a;
		for(int i = LOGN;i>=0;i--)
			if(anc[a][i]!=-1&&anc[b][i]!=anc[a][i])
					
			{
				a=anc[a][i];
				b=anc[b][i];
			}
		return anc[a][0];
	}
}tt;

int main()
{
	int T;
	//freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		rep(i,1,N)v[i].clear();
		MEM(vis,0);
		int a,b;
		rep(i,1,N-1){
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			vis[b]=1;
		}
		LCA tt;
		tt.init();
		rep(i,1,N)
			if(vis[i]==0){
				tt.dfs(i);
				tt.doubling();
				break;
			}
		scanf("%d%d",&a,&b);
		printf("%d\n",tt.lca(a,b));
	}
}
