/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
const int maxn=1e3;
const double inf = 1e30;
//const double esp=1e-6
int N,M,K;
inline double sq(double a){return a*a;}
struct Point{
	vector<double> x;
};
double dist(Point a,Point b){
	double sum =0 ;
	for(int i=0;i<K;i++)
		sum += sq(a.x[i]-b.x[i]);
	return sum;
}
Point pp[maxn];
struct Tnode{
	int id,l,r;
};
struct Kdtree{
public:
	Tnode nn[maxn];
	int tsz=0;
	void init(){
		tsz=0;MEM(nn,-1);
	}
	Tnode newNode(int iid){
		Tnode tmp ;
		tmp.id = iid; tmp.r=tmp.l = -1;
		return tmp;
	}
	//这里我们先使用直接顺序遍历的方式,循环选择所需要的k
	void build()
	{
		init();
		nn[tsz++] = newNode(1);
		for(int i=2;i<=N;i++)
			insert(0,i,0);
	}
	void insert(int now,int iid,int dep)
	{
		int ch = dep%K,nid = nn[now].id;
		if(pp[nid].x[ch] >= pp[iid].x[ch]){
			if(nn[now].l!=-1)insert(nn[now].l,iid,dep+1);
			else{
				nn[tsz++] = newNode(iid);
				nn[now].l = tsz-1;
				return ;	
			}
		}
		else{
			if(nn[now].r!=-1)insert(nn[now].r,iid,dep+1);
			else{
				nn[tsz++] = newNode(iid);
				nn[now].r = tsz-1;
				return ;
			}
		}
	}
	void query(int now,Point q,int dep,double &cdis,int &cid)
	{
		int nid = nn[now].id, ch = dep%K,dir=-1;
		double dtmp = inf;
		if(q.x[ch] <= pp[nid].x[ch]){
			if(nn[now].l!=-1)query(nn[now].l,q,dep+1,cdis,cid);
			else{
				dtmp  = dist(q,pp[nid]);
				if(dtmp<cdis)cdis =dtmp,cid = nid;
				return ;
			}
			dir = 0;
		}
		else{
			if(nn[now].r!=-1)query(nn[now].r,q,dep+1,cdis,cid);
			else{
				dtmp = dist(q,pp[nid]);
				if(dtmp<cdis)cdis = dtmp,cid = nid;
				return ;
			}
			dir = 1;
		}
		if(sq(pp[nid].x[ch]-q.x[ch])<=sq(cdis))
			query(dir==1?nn[now].l:nn[now].r,q,dep+1,cdis,cid);
		return ;
	}
	void print_t(int now,int dep)
	{
		if(now==-1)return ;
		int nid = nn[now].id;
		printf("%lf %lf %d\n",pp[nid].x[0],pp[nid].x[1],dep);
		print_t(nn[now].l,dep+1);
		print_t(nn[now].r,dep+1);
	}
};

int main()
{
	freopen("test.in","r",stdin);
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&M,&K);
		double a;
		for(int i=1;i<=N;i++)
			for(int j=0;j<K;j++){
				scanf("%lf",&a);
				pp[i].x.pb(a);
			}
		printf("case %d\n",cas++);
		Kdtree rt;
		rt.build();
		Point q;
		for(int i=1;i<=M;i++){
			for(int j=0;j<K;j++){
				scanf("%lf",&a);
				q.x.pb(a);
			}
			double cdis = inf;
			int cid = -1;
			rt.query(0,q,0,cdis,cid);
			for(int j=0;j<K;j++)
				printf("%lf%c",pp[cid].x[j],j==K-1?'\n':' ');
			printf("dis %lf\n",cdis);
		}
	}
}

