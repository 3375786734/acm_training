#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=b;i++) 
#define MEM(a,num) memset(a,num,sizeof(a))
#define mp make_pair
using namespace std;
const int maxn=1e6+100;
const int mod=1e9+7;
pair<int ,int > a;
int N,stk[maxn],vis[maxn],l[maxn],r[maxn],ans,inv[maxn];
void qpow(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=ans*a;
		a=a*a;n>>=1;
	}
	return ans;
}
void dfs(int now)
{
	int sz=0;
	if(l[now])sz+=dfs(l[now]);
	if(r[now])sz+=dfs(r[now]);
	ans*=inv[sz]%mod;
	return sz;
}
int build()
{
	int top=0;
	MEM(l,0);MEM(r,0);MEM(vis,0);
	rep(i,1,N){
		int cur=top;
		while(cur>0&&a[stk[cur-1]]>a[i])cur--;
		//如果前面还有元素,那么将当前点放在前面一个节点的rson上
		if(k!=0)r[stk[cur-1]]=i;
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
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		int b;
		rep(i,1,N){
			scanf("%d",&b);
			a[i]=mp(-b,i);
		}
		int rt=build();
		dfs(rt);
		printf("%d\n",ans);
	}
}
