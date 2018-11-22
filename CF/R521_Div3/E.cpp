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
const int maxn = 2e5+100;
struct Node{
	int id,vv;
	bool operator<(const Node&a)const {
		return vv<a.vv;
	}
};
Node nn[maxn];
int main()
{
	int N,sz = 0;
	scanf("%d",&N);
	int a;
	map<int,int> mm;
	for(int i=1;i<=N;i++){
		scanf("%d",&a);
		mm[a]++;
	}
	for(auto mi:mm)
		nn[sz++] = (Node){mi.first,mi.second};
	sort(nn,nn+sz);
	int ps =-1,sum = 0,ans = 0,val = 0;
	for(int i =1;i<=2e5;i++){
		val = i, ps = -1,sum = 0;
		ps = lower_bound(nn+ps+1,nn+sz,(Node){0,val})-nn;
		if(ps>=sz)break;
		while(ps<sz){
			sum += val;
			val <<=1;
			ps = lower_bound(nn+ps+1,nn+sz,(Node){0,val})-nn;
		}
		ans = max(sum,ans);
	}
	printf("%d\n",ans);
}
