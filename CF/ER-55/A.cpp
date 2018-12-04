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
//const int maxn=;
//const double esp=1e-6

int ABS(int a){return a>0?a:-a;}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,x,y,d;
		scanf("%d%d%d%d",&n,&x,&y,&d);
		if(ABS(x-y)%d==0)printf("%d\n",ABS(x-y)/d);
		else if((y-1)%d!=0&&(n-y)%d!=0)printf("-1\n");
		else {
			int ans = 1e9;
			if((y-1)%d==0)ans = ((x-1)%d==0)?(x-1)/d:((x-1)/d+1) + (y-1)/d;
			if((n-y)%d==0)ans = min(ans,((n-x)%d==0)?(n-x)/d:((n-x)/d+1)+(n-y)/d);
			printf("%d\n",ans);
		}
	}
}

