/*  -*- coding: utf-8 -*- */
/*
 *trick:由于线段不包括端点,因此我们将同一坐标点:例如  x=1 分成两部分,前一部分留给线段的r,后一部分留给线段的l.这样就不会出现交叠的情况了.
 */
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
const int maxn = 400*4+10;
int a[maxn],b[maxn],c[maxn];
int head[maxn],vis[maxn],cntv[maxn],dis[maxn],nn[maxn],h[maxn],N;
int sz;
struct Eg{
	int id,val;
};
vector<Eg> eg[maxn<<1];
bool spfa(int S)
{
	MEM(vis,0);MEM(dis,0x3f3f3f);MEM(cntv,0);
	vis[S]  =1;dis[S] = 0;
	queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int fa = q.front();q.pop();
		vis[fa] = 0;
		for(Eg e:eg[fa])
		{
			if(dis[e.id] >dis[fa]+e.val){
				dis[e.id]  =dis[fa] +e.val;
				if(!vis[e.id]){
					q.push(e.id);
					vis[e.id]=1;
					if(++cntv[e.id]>N)return false;
				}
			}
		}
	}
	return true;
}
bool check(int mid)
{
	MEM(head,-1);
	for(int i=0;i<N;i++)
		eg[a[i]].clear(),eg[b[i]].clear();
	for(int i=0;i<N;i++){
		eg[a[i]].pb((Eg){b[i],mid});
		eg[b[i]].pb((Eg){a[i],-1});
	}
	for(int i=1;i<sz*2;i++)
		eg[i].pb((Eg){i-1,0});
	return spfa(1);
}
int main()
{
	freopen("t.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&a[i],&b[i],&h[i]);	
		nn[sz++] = a[i];nn[sz++] = b[i];
	}
	sort(nn,nn+sz);
	sz = unique(nn,nn+sz)-nn;
	for(int i=0;i<N;i++){
		a[i] = (lower_bound(nn,nn+sz,a[i])-nn)*2+1;
		b[i] = (lower_bound(nn,nn+sz,b[i])-nn)*2;
	}
	int l=0,r= 2*sz-1; 
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid)) r= mid-1;
		else l = mid+1;
	}
	printf("%d\n",l);
}
