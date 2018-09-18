/*
 *idea:由于是区间和,自然考虑前缀和的形式,注意到最终的问题变为
 *    \sum_{L}\sum_{R} #(pre[R]-pre[L]<t
 *    固定L 得到计数问题   \sum_{R} #(pre[R]<pre[L]+t)
 *    可是使用BIT在O(nlogn)时间内实现
 *    warning:注意L的范围是0-N-1,R的范围是1-N
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long LL;
typedef pair<LL,int> PP;
typedef vector<int >::iterator VI;
typedef set<PP> SS;
typedef set<PP>::iterator SI;
const int maxn=3e5+100;
LL N,T,a[maxn],sum[maxn];
int bit[maxn<<1];
SS ll,rr;
int lowbit(int x){
	return x&(-x);
}
int add(int a,int x){
	for(int i=a;i<=N;i+=lowbit(i))
		bit[i]+=x;
}
int get(int x){
	LL ans=0;
	for(int i=x;i>0;i-=lowbit(i))
		ans+=bit[i];
	return ans;
}
int main()
{
//	freopen("t.in","r",stdin);
	scanf("%lld%lld",&N,&T);
	rep(i,1,N)scanf("%lld",&a[i]);
	rep(i,1,N){
		sum[i]=sum[i-1]+a[i];
		rr.insert(PP(sum[i],i));
	}
	rep(i,0,N-1)ll.insert(PP(sum[i]+T,i));
	SI sr=rr.begin();
	LL ans=0;
	for(SI sl=ll.begin();sl!=ll.end();sl++)
	{
		while(sr!=rr.end()&&sr->first<sl->first){
			add(sr->second,1);
//			printf("at %d\n",si->second);
			sr++;
		}
		ans+=get(N)-get(sl->second);
//		printf("now %d %lld\n",qi->second,ans);
	}
	printf("%lld\n",ans);
}
