#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5;
typedef pair<int,int> PP;
set<PP> ss;
map<PP,int> mm;
int pre[maxn],cnt[maxn],k,N,sz;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int ans=0;sz=0;
		ss.clear();mm.clear();
		memset(pre,0,sizeof(pre));memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=N;i++){
			scanf("%d",&k);
			int a,b;
			for(int j=0;j<k;j++){
				scanf("%d%d",&a,&b);
				if(!ss.count(PP(a,b))){
					mm[PP(a,b)]=sz++;
					ss.insert(PP(a,b));
//					printf("%d %d at %d\n",a,b,sz-1);
					pre[sz-1]=i;cnt[sz-1]=1;
				}
				else {
					int ps=mm[PP(a,b)];
					if(pre[ps]==i-1)ans=max(++cnt[ps],ans);
					else if(pre[ps]!=i)cnt[ps]=1;
					pre[ps]=i;
//					printf("at %d %d ,pre %d ,cnt %d\n",a,b,pre[ps],cnt[ps]);
				}
			}
		}
		printf("%d\n",ans>=2?ans:0);
	}
}
