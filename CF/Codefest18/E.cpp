/*题意,动态加边,每一步,询问有多少个subgraph,在这个subgraph中每点至少有k条边
 *idea:把所有degree<k的删掉之后,剩下的就是满足要求的点的个数,然后发现,如果正向更新,那么每一次都要更新$O(N)$
 *次,那么最终更新的次数为O(N^2)次,但是如果我们逆向处理,可以发现,当我们把度数<k的点删掉之后,他不会再次出现,因此总次数为O(n \log n);
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> PP;
typedef set<PP>::iterator SI;
const int maxn=1e5+100;
set<PP> ss;
PP G[maxn];
set<int> v[maxn];
int N,M,K,d[maxn],ans[maxn];
void delt()
{
	SI it=ss.begin();
	while(it!=ss.end()){
		if(it->first>=K)break;
//		printf("here %d %d\n",it->first,it->second);
		int id= it->second;
		for(set<int>::iterator vi=v[id].begin();vi!=v[id].end();vi++){
			int to=*vi;
			ss.erase(PP(d[to],to));ss.insert(PP(--d[to],to));
			v[to].erase(id);v[id].erase(to);
		}
		ss.erase(*it);
		it=ss.begin();
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i=1;i<=M;i++){
		scanf("%d%d",&a,&b);
		G[i]=PP(a,b);d[a]++;d[b]++;
		v[a].insert(b);v[b].insert(a);
//		printf("G %d %d\n",G[i].first,G[i].second);
	}
	for(int i=1;i<=N;i++)ss.insert(PP(d[i],i));
//	for(int i=1;i<=N;i++)printf("%d\n",d[i]);
	delt();
	ans[M]=ss.size();
	for(int i=M;i>1;i--){	
		a=G[i].first,b=G[i].second;
		if(!v[a].count(b)||!v[b].count(a)){
			ans[i-1]=ans[i];
			continue;
		}
		ss.erase(PP(d[a],a));ss.insert(PP(--d[a],a));
		ss.erase(PP(d[b],b));ss.insert(PP(--d[b],b));
		v[a].erase(b);v[b].erase(a);
//		printf("now %d\n",i);
		delt();
		ans[i-1]=ss.size();
		if(ans[i-1]==0)break;
	}
	for(int i=1;i<=M;i++)printf("%d\n",ans[i]);
}
