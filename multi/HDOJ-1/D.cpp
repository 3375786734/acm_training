/*trick:使用set处理mex询问的方法
 *   考虑两种情形：
 *   case1:    -----
 *                ----
 *   case1:   ----  ----
 *   前一个区间的起始位置是pl,后一个是pre[i],只要将pl-pre[i]的去掉即可
 */
#include <bits/stdc++.h>
#define rep(i,a,b ) for(int i=a;i<=b;i++)
#define dep(i,a,b)  for(int i=a;i>=b;i--)
using namespace std;
const int maxn=1e5+100;
int N,M,pre[maxn],vv[maxn];
set<int> ss;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int l,r;
		scanf("%d%d",&N,&M);
		rep(i,1,N+1)pre[i]=i;
		rep(i,1,M){
			scanf("%d%d",&l,&r);
			pre[r]=min(pre[r],l);
		}
		dep(i,N,1)pre[i]=min(pre[i+1],pre[i]);
		int pl=1;
		//pl++ at most N O(nlogn)
		rep(i,1,N) ss.insert(i);
		
		rep(i,1,N){
			while(pre[i]>pl){
				ss.insert(vv[pl]);pl++;
			}
			vv[i]=*ss.begin();
			ss.erase(vv[i]);
		}
		printf("%d",vv[1]);
		rep(i,2,N)printf(" %d",vv[i]);
		printf("\n");
	}
}
