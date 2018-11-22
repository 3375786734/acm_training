/*  -*- coding: utf-8 -*- */
/*
 *题意:给一个图,以1为根节点构造一颗支撑树,边权是该边以下的所有点权*该边的单位权重.求怎么样选择,可以使得总边权最小


 *IDEA:注意到这个优化问题,代表的什么含义注意到树上rt到每个点只有一条路径,因此.我们求的结果实际上是 sum dist(1,i)*w(j),为什么是这个呢.因为
 sum_e(sum_v)其中v对应的是decend的节点权值,我们交换和号得到sum_v(sum_e)其中e就是v对应的ascend 的路径,也就是说1-v的路径,因此这个问题实际上是最短路径问题.
remark:问题的关键是找到descend 的含义
 */
#include <cstdio>
#include <cstring>
#include <vector>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&V,&E);
		for(int i=1;i<=N;i++)
			scanf("%d",&v[i]);
		for(int i=1;i<=E;i++){
			scanf("%d%d%d",&a,&b,&c);
		}
		printf("%d\n",solve());
	}
}

