#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int N,a[maxn],dp[maxn];
vector<int> vv[maxn];
bool dfs(int now)
{
	//printf("now %d\n",now);
	if(dp[now] != -1)return dp[now];
	int ok=0;
	for(int u:vv[now])
		if(!dfs(u))ok=1;
	return dp[now]=ok;
}
int main()
{
	scanf("%d",&N);
	MEM(dp,-1);
	rep(i,1,N)scanf("%d",&a[i]);
	for(int i=N;i>=1;i--){
		int pos = i+a[i];
		while(pos<=N){
			if(a[pos]>a[i])vv[i].push_back(pos);
			pos+=a[i];
		}
		pos=i-a[i];
		while(pos>=1){
			if(a[pos]>a[i])vv[i].push_back(pos);
			pos-=a[i];
		}
	}
	/*
	rep(i,1,N-1)
		for(int u:vv[i])
				printf("cc %d %d\n",i,u);
	*/
	for(int i=N;i>=1;i--)
		dfs(i);
	rep(i,1,N)printf("%c",dp[i]==1?'A':'B');
	puts("");
}
