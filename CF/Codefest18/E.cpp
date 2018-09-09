#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> PP;
const int maxn=1e5+100;
set<PP> ss;
vector<int> v[maxn];
int N,M,K,d[maxn];
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i=1;i<=M;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);v[b].push_back(a);
		ss.erase(PP(d[b],b));
		ss.erase(PP(d[a],a));
		ss.insert(PP(++d[b],b));
		ss.insert(PP(++d[a],a));
		set<PP>::iterator it=ss.begin();

		/*
		for(;it!=ss.end();it++)
			if(it->first>=K){
				int id=it->second;
				for(VI vi=v[id].begin();vi!=v[id].end();vi++){
					ss.erase(d[*vi],);ss.erase(d[*vi],);
					ss.insert(d[],);ss.insert(d[],);
				}
			}
			else break;
		*/

		int ans=0;
		for(;it!=ss.end();it++)ans++;
		printf("%d\n",ans);
	}	
}
