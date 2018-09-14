#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef vector<int >::iterator VI;
typedef set<int>::iterator SI;
const int maxn=2e6;
int N,M;
int inn[maxn],out[maxn],vis[maxn],src[maxn];
set<int> con[maxn],ss;
vector<int> v[maxn];
void dfs(int now,int rt)
{
	if(vis[now])return;
	vis[now]=1;
	if(out[now]==0)con[rt].insert(now);
	for(VI it=v[now].begin();it!=v[now].end();it++)
		if(vis[*it]==0)dfs(*it,rt);
}
void add(int now){
	for(SI si=con[now].begin();si!=con[now].end();si++)ss.insert(*si);
}
int main()
{
	scanf("%d%d",&N,&M);
	int a,b,sz=0,cnt=0;
	rep(i,1,M){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);out[a]++;inn[b]++;
	}
	/*
	rep(i,1,N){
		if(inn[i]==0)printf("in %d\n",i);
		if(out[i]==0)printf("out %d\n",i);
	}
	*/
	rep(i,1,N)
		if(inn[i]==0){
			MEM(vis,0);
			dfs(i,i);
			src[sz++]=i;
		}
	/*
	rep(i,1,N){
		if(inn[i]==0)
			for(SI si=con[i].begin();si!=con[i].end();si++)
				printf("%d connt %d\n",i,*si);
	}
	for(SI si=con[1].begin();si!=con[1].end();si++)
		printf("end %d\n",*si);
	*/

	int ok=1;
	for(int i=0;i<(1<<sz);i++){
		ss.clear();cnt=0;
		for(int j=0;j<sz;j++)
			if(i&(1<<j)){
				add(src[j]);
				cnt++;
			}
		if(ss.size()<cnt||(ss.size()==cnt&&cnt!=sz&&cnt!=0))ok=0;
	}
	printf("%s\n",ok?"YES":"NO");
}
