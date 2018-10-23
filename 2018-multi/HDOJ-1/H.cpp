//MEM may tle in HDU
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++) 
#define MEM(a,num) memset(a,num,sizeof(a))
#define mp make_pair
typedef long long LL;
const int maxn=1e6+100;
const int mod=1e9+7;
pair<int ,int > a[maxn];
int N,stk[maxn],vis[maxn],l[maxn],r[maxn];
LL inv[maxn],ans;
int dfs(int now)
{
	int sz=1;
	if(l[now])sz+=dfs(l[now]);
	if(r[now])sz+=dfs(r[now]);
	ans=ans*inv[sz]%mod;
//	printf("ans %lld\n",ans);
	return sz;
}
int build()
{
	int top=0;
	//MEM(l,0);MEM(r,0);MEM(vis,0);
	rep(i,1,N)l[i]=r[i]=vis[i]=0;
	rep(i,1,N){
		int cur=top;
		while(cur>0&&a[stk[cur-1]]>a[i])cur--;
		//如果前面还有元素,那么将当前点放在前面一个节点的rson上
		if(cur!=0)r[stk[cur-1]]=i;
		//如果从stk中弹出了元素,那么需要将先前的一部分放在当前的lson
		if(cur<top)l[i]=stk[cur];
		stk[cur++]=i;
		//这里保证了每个元素最多进入一次栈
		top=cur;
	}
	//找根;
	int rt=0;
	rep(i,1,N)vis[l[i]]=vis[r[i]]=1;
	rep(i,1,N)if(vis[i]==0){
		rt=i;
		break;
	}
	return rt;
	//dfs(rt);
}
void init(){
	inv[1]=1;
	rep(i,2,1000000) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
}
int main()
{
	int T;
	scanf("%d",&T);
	init();
	while(T--)
	{
		scanf("%d",&N);
		ans=N*inv[2]%mod;
		int b;
		rep(i,1,N){
			scanf("%d",&b);
			a[i]=mp(-b,i);
		}
		int rt=build();
		dfs(rt);
		printf("%lld\n",ans);
	}
}
