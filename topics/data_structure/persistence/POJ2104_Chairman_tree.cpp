/*  -*- coding: utf-8 -*- */
/*
 *Solution-1:划分树(Done)
 *Solution-2:整体二分
 *Solution-3:主席树
 *Solution-4:Fenwich tree.
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn = 1e5+10;
const int maxm = 2e6+100;
int N,M,cnt;
int a[maxn],b[maxn],rt[maxn];
struct Node{
	int ls,rs,sum,r,l;	
	void operator=(Node &n){
		ls = n.ls;rs = n.rs;sum = n.sum;r = n.r;l = n.l;
	}
	/*
	 //错误写法:因为你没有实质性定义=返回的Node 还是需要通过=赋值,而这个等号没有定义
	 Node operato=(const Node&a)const{
	 	retrun (Node){ls,rs,sum,r,l};
	 }
	 */
};
Node tr[maxm];
void build(int &id,int l,int r)
{
	id  = ++cnt;
	tr[id].l= l;tr[id].r =r;
	if(l==r)return ;
	int mid = (l+r)/2;
	build(tr[id].ls,l,mid);
	build(tr[id].rs,mid+1,r);
}
void pushup(int rt){tr[rt].sum = tr[tr[rt].ls].sum+tr[tr[rt].rs].sum;}

void upd(int &ver,int pver,int pos)
{
	ver = ++cnt;
	tr[ver] = tr[pver];
	tr[ver].sum = tr[pver].sum+1;
	//if(tr[ver].l>tr[ver].r||tr[ver].l>pos||tr[ver].r<pos)return ;
	if(tr[ver].l==tr[ver].r){
		return;
	}
	int mid = (tr[ver].l+tr[ver].r)/2;
	if(pos<=mid)upd(tr[ver].ls,tr[pver].ls,pos);
	else upd(tr[ver].rs,tr[pver].rs,pos);
	//pushup(ver);
}
int query(int vl,int vr,int k)
{
	if(tr[vl].l==tr[vl].r) return a[tr[vl].l];
	//see lson only.
	int cmp = (tr[tr[vr].ls].sum-tr[tr[vl].ls].sum);
	if(cmp>=k)return query(tr[vl].ls,tr[vr].ls,k);
	else return query(tr[vl].rs,tr[vr].rs,k-cmp);
}
/*
void pttree(int now,int l,int r)
{
	if(l ==r){
		printf("leave %d %d\n",l,tr[now].sum);
		return ;
	}
	printf("%d %d %d",l,r,tr[now].sum);
	int mid = (l+r)/2;
	printf("lson\n");
	pttree(tr[now].ls,l,mid);
	printf("rson\n");
	pttree(tr[now].rs,mid+1,r);
}
*/
int main()
{
	//freopen("t.in","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(a+1,a+N+1);
	build(rt[0],1,N);
	for(int i=1;i<=N;i++){
		int pos = lower_bound(a+1,a+N+1,b[i])-a;
		upd(rt[i],rt[i-1],pos);
	}
	int l,r,k;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(rt[l-1],rt[r],k));
	}
}
