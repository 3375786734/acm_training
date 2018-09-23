/*
 *常规思路,前i个票中,取j个集合可以覆盖的最大长度dp[i][j]
 *排序询问区间是为了一次遍历完所有的区间,常规技巧:排序之后再遍历
 *类似题目:NWERC-2017-A
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=;
typedef pair<int,int> PP;
int N,M,K;
SS ss;
struct Node{
	int l,r;
};
Node n[maxn];
bool operator()(Node &a,Node &b){
	return a.l<b.l;
}
int main()
{
	int  T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&M,&K);
		rep(i,1,M){
			scanf("%d%d",&n[i].l,&n[i].r);
		}
		sort(n+1,n+1+M,cmp);
		for(int i=1;i<=N;i++){
			
		}
	}
}
