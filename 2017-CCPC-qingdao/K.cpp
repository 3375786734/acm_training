/*
 *idea:考虑去掉一个数,方差减少的最多的是哪一个
 *计算发现,删除最大或者最小的那个数是最优的,因此每次都是删最小的那个数中,字典序最小的那个
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
struct Node{
	int val,id;
};
Node nn[maxn];
int N,M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int cnt=0,a;
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++){
			scanf("%d",&a);
			nn[cnt++]=(Node){a,i};
		}
		sort(nn,nn+cnt,[&](Node a,Node b){return a.val!=b.val?a.val<b.val:a.id<b.id;});
		sort(nn,nn+cnt-M,[&](Node a,Node b){return a.id<b.id;});
		for(int i=0;i<cnt-M;i++)
			printf("%d%c",nn[i].id,i==cnt-M-1?'\n':' ');
	}

}
