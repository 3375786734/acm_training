#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int > PP;
const int maxn=;
int N,M,K;
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=M;i++){
		scanf("%d%d",&a,&b);
		v[a].insert(b);v[b].insert(a);
		ss.erase(PP(d[b],b));
		ss.erase(PP(d[a],a));
		ss.insert(PP(++d[b],b));
		ss.insert(PP(++d[a],a));
		for(set<PP>::iterator it=ss.begin();it!=ss.end();it++){
			if(it->first<K){

			}
			else break;
		}
	}
	
}
