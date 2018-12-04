/*  -*- coding: utf-8 -*- */
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int inf = 1e9;
int N,S,E,T,sz;
int ans[maxn][maxn],tmp[maxn][maxn],temp[maxn][maxn];
map<int,int> mm;
//注意一个细节,这里不是floyd 
//只是dp,因为所有长度为k的等于长度为k_1的和(k-k_1)的和组成.
int min(int a,int b){return a<b?a:b;}
void floyd(int outv[][maxn],int inv[][maxn])
{
	rep(i,1,sz)
		rep(j,1,sz)temp[i][j] = inf;
	rep(i,1,sz)
		rep(j,1,sz)
			rep(k,1,sz)
				temp[i][j] = min(temp[i][j],outv[i][k]+inv[k][j]);
	rep(i,1,sz)
		rep(j,1,sz)
			outv[i][j] = temp[i][j];
}
int solve(int k)
{
	while(k)
	{
		if(k&1)floyd(ans,tmp);
		floyd(tmp,tmp);
		k>>=1;
	}
	return ans[mm[S]][mm[E]];
}
int main()
{
//	freopen("t.in","r",stdin);
	scanf("%d%d%d%d",&N,&T,&S,&E);
	int a,b,c;
	MEM(tmp,0x3f3f3f);MEM(ans,0x3f3f3f);
	rep(i,1,1001)ans[i][i] = 0;
	for(int i=1;i<=T+1;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(!mm.count(b))mm[b] = ++sz;
		if(!mm.count(c))mm[c] = ++sz;
		if(tmp[mm[c]][mm[b]]>a)tmp[mm[c]][mm[b]] = tmp[mm[b]][mm[c]] = a;
	}
	printf("%d\n",solve(N));
}
