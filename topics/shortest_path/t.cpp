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

int nearvex[maxn];//label the node which has been added into the MST,and nearvex[u] is u's father.
int lowcost[maxn];//in order to find the current augment node.
int eg[maxn][maxn];//eg[i][j] is dis from i to j
int prim(int src)
{
	MEM(lowcost,0x3f3f3f);MEM(lowcost,0);
	ll sum = 0;
	for(int i =1;i<=N;i++){
		lowcost[i] = eg[src][i];
		nearvex[i] = src;
	}
	//add N-1 eg is enough
	for(int i=1;i<=N-1;i++){
		int now = -1;
		ll minc = inf;
		//find the node that should be augment currently.
		for(int j =1;j<=N;j++)
			if(nearvex[i]!=-1&&lowcost[i]<minc){
				minc = lowcost[i];
				now = j;
			}
		if(now!=-1){
			nearvex[i]  = -1;
			sum += lowcost[now];
			for(int j=1;j<=N;j++)
			{
				int tmp = eg[now][j];
				if(nearvex[j]!=-1&&tmp<lowcost[j]){
					lowcost[j] = tmp;
					nearvex[j] = now;
				}
			}
		}
	}
	return sum;
}
int main()
{
	printf("%d\n",prim(1));
}

