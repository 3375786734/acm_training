#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int a[20];
ll dp[20][4];
ll dfs(int pos, int pre, int state, bool limit)
{
    if(pos==-1) return 1;
    if(!limit && dp[pos][state]!=-1) return dp[pos][state];
    int up=limit?a[pos]:9;
    ll ans=0;
	for(int i=0;i<=up;i++)
    {
        if(i!=0)pre++;
      	if(pre>3){
			if(i!=0)pre--;
			continue;
		}
	  	ans+=dfs(pos-1, pre, pre,limit && i==a[pos]);
		//当统计完pre 时候要将其减去
    	if(i!=0)pre--;
	}
    if(!limit) dp[pos][state]=ans;
    return ans;
}

ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos - 1, 0, 0, true);
}
int main()
{
	int N;
	ll le,ri;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld%lld",&le,&ri);
		memset(dp, -1, sizeof(dp));
		printf("%lld\n",solve(ri)-solve(le-1));
	}
	return 0;
}
