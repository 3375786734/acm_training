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
const int maxn = 2000;
int a[maxn],vis[maxn];
int dfs(int now)
{
	if(vis[now]==2)return now;
	vis[now]++;
	return dfs(a[now]);
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=N;i++){
		MEM(vis,0);
		printf("%d%c",dfs(i),i==N?'\n':' ');
	}
}

