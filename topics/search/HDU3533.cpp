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
//const double esp=1e-6
const int maxn = ;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,,1,-1};
bool out_bound(int x,int y){
	return (x<0||x>=m||y<0||y>=n);
}
bool is_attack(int x,int y,int lay)
{
	for(int i=0;i<k;i++)
		if()return false;
	return true;
}
int solve()
{
	queue<PP> q;
	q.push(PP(0,0));
	while(!q.empty())
	{
		PP fa = q.front();q.pop();
		for(int i=0;i<4;i++){
			int nx,ny = fa.fi+dx[i] , fa.se+ dy[i];
			if(out_bound(nx,ny)&&is_attack())continue;
		}
	}
}
int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&k,&d)){
		for(int i=0;i<k;i++){
			scanf("%s",str);
			scanf("%d%d%d%d",&t,&v,&x,&y);
		}
		int ans = solve();
		if(ans == -1)printf("Bad luck!\n");
		else printf("%d\n",ans);
	}
}

