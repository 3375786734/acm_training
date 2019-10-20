/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn=1e6+100;
const int maxm = 1<<20+10;
//const double esp=1e-6
char str[maxn];
int vis[25],dp[maxm];
int main()
{
	scanf("%s",str);
	int len = strlen(str);
	int ans = 0;
	for(int i=0;i<len;i++)
	{
		MEM(vis,0)
		for(int j = i;j<len;j++){
			if(vis[str[j+i]-'a'])break;
			vis[str[j+1]] =1;
			mask |= (1<<(str[j+i]-'a'));
			dp[mask] = __buildin_popcount(mask);
		}
	}
	for(int i=0;i<(1<<20);i++){
		for(int j=0;j<20;j++){
			if((i&(1<<j)))
			  dp[i] = max(dp[i],dp[i^(1<<j)]);
		}
	}
		for(int mask=0;mask<(1<<20);mask++){
			if(dp[mask] == __buildin_popcount(mask)){
				complement = (1<<20)^(mask);
				ans = max(ans,dp[mask]+dp[complement]);
			}
		}
		printf("%d\n",ans);
}

