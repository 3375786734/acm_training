/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;
//const double esp=1e-6
struct Point{
	double x[maxk];
};
Point pp[maxn];
class Kdtree{
public:
	int son[maxn<<2];
	void init()
	{
		MEM(son,-1);
	}
	void build(int l,int r,int dep)
	{
		if(l>r)return ;
		int dim = dep%K;
		int mid =(l+r)/2;
		nth_elment(pp,pp+mid,pp+N,[&](Point a,Point b){return a.x[dim]<b.x[dim];});	
		build(l,mid,dep+1);
		build(mir+1,r,dep+1);
	}
	void query(int l,int r,int dep)
	{
		int mid = (l+r)/2,dim = dep%K;
		int l = rt<<1,r = rt<<1|1;
		if(pp[rt].x[dim]>=)swap(l,r);//目的是为了防止重复的代码;
		if(son[l]!=-1)query(l,mid,dep+1);
		if(q.size()<M){
			q.push();flag=1;
			
		}
		else{
			
		}
		if(flag==1)query(mid+1,r,dep+1);
	}
};

int main()
{
	scanf("%d%d",&N,&K);
	int a;
	rep(i,1,N)
		for(int j=0;j<K;j++)
			scanf("%d",&pp[i].x[j]);
	Kdtree rt;
	rt.init();rt.build();
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		for(int j=0;j<K;j++)
			scanf("%d",&a);
	}
}

