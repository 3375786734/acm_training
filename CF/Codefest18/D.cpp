#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
typedef vector<int> VV;
typedef VV::iterator VI;
const int maxn=4e5+100;
int N,vis[maxn],a[maxn],rk[maxn];
VV v[maxn];
bool bfs()
{
	MEM(vis,0);
	queue<int>q;
	q.push(1);vis[1]=1;
	int cnt=1;
	while(!q.empty())
	{
		int fa=q.front();q.pop();
//		printf("now at %d %d\n",fa,a[]);
		if(fa!=a[cnt++])return false;
		for(VI it=v[fa].begin();it!=v[fa].end();it++){
			if(!vis[*it]){
				vis[*it]=1;
				q.push(*it);
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d",&N);
	int c,d;
	for(int i=1;i<=N-1;i++){
		scanf("%d%d",&c,&d);
		v[c].push_back(d);
		v[d].push_back(c);
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
//		if(a[i]!=1)v[fa[a[i]]].push_back(a[i]);
		rk[a[i]]=i;
	}
	for(int i=1;i<=N;i++)
		sort(v[i].begin(),v[i].end(),[&](int a,int b){return rk[a]<rk[b];});
	if(bfs())printf("Yes\n");
	else printf("No\n");
}
