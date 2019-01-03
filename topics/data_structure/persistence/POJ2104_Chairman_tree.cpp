/*  -*- coding: utf-8 -*- */
/*
 *Solution-1:划分树(Done)
 *Solution-2:整体二分
 *Solution-3:主席树
 *Solution-4:Fenwich tree.
 */
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
const int maxn = 2e5+10;
int N,M;
int a[maxn];
struct Node{
	int ls,rs,sum,r,l;	
	Node operator=(const Node &n)const{
		return (Node){n.ls,n.rs,n.sum,n.l,n.r};
	}
};
Node tr[maxn<<2];
void build(int &id,int l,int r)
{
	id  = cnt++;
	tr[id].l= l;tr[id].r =r;
	int mid = (l+r)/2;
	build(tr[id].ls,l,mid);
	build(tr[id].rs,mid+1,r);
}
void pushup(int rt){
	tr[rt].sum = tr[tr[rt].ls].sum+tr[tr[rt].rs].sum;
}
void upd(int &ver,int pver,int l,int r,int pos)
{
	if(l>r||r<pos||l>pos)return ;
	ver = cnt++;
	if(l==r){
		tr[ver] ++;
		return ;
	}
	tr[ver] = tr[pver];
	int mid = (l+r)/2;
	if(pos<=mid)upd(ver,tr[pver].ls,l,mid,pos);
	else upd(tr[ver].rs,tr[pver].rs,mid+1,r,pos);
	pushup(ver);
}
int query(int vl,int vr,int k,int l,int r)
{
	if(l==r) return l;
	int mid =(l+r)/2;
	if(tr[vr].sum- tr[vl].sum >sum)return query(tr[vr].ls,tr[vl].ls,k,l,mid);
	else return query(tr[vl],rs,tr[vr].rs,k,mid+1,r);
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+N+1);
	N = unique(a+1,a+1+N)-(a+1);
	build(tr[0],1,N);
	for(int i=1;i<=N;i++){
		int pos = lowerbound(a+1,a+N+1,a[i])-a;
		upd(tr[i],tr[i-1],1,N,pos);
	}
	int l,r,k;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(tr[l-1],tr[r],k,1,N));
	}
}
