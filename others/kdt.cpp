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
const int maxn=1e5+100;
const int maxk=4;
const ll inf = 1e18+100;
//const double esp=1e-6
int N,ps[maxn][maxk],K;
struct Node
{
	int id,l,r;
};
inline ll sq(ll a){return a*a;}
inline ll dist(int a,int b){
	ll sum = 0;
	for(int i=0;i<K;i++)
		sum+=sq(ps[a][i]-ps[b][i]);
	return sum;
}
class Kdtree
{
public:
	Node nn[maxn];
	int tsz;
	inline Node newNode(int iid)
	{
    	Node tmp;
    	tmp.id = iid;tmp.l = tmp.r = -1;
    	return tmp;
	}
	void init(){
		MEM(nn,-1);tsz=0;
	}
	void build()
	{
		//rt node is
		init();
		nn[tsz++] = newNode(1);
		for(int i=2;i<=N;i++)
			insert_node(0,i,0);
	}
	void insert_node(int now,int iid,int dep)
	{
		int ch = dep%K;
		int nid = nn[now].id;
		if(ps[nid][ch]>=ps[iid][ch]){
			if(nn[now].l!=-1)insert_node(nn[now].l,iid,dep+1);
			else{
				nn[tsz++] = newNode(iid);
				nn[now].l = tsz-1;
				return ;
			}
		}
		else{
			if(nn[now].r!=-1)insert_node(nn[now].r,iid,dep+1);
			else{
				nn[tsz++] = newNode(iid);
				nn[now].r = tsz-1;
				return ;
			}
		}
	}
	/*
	void query(int now,int iid,int dep,int &cid,ll &cdis)
	{
		int ch = dep%K;
		int nid = nn[now].id,dir=-1;
		ll dis  = inf,dtmp = inf;
		if(ps[nid][ch]>=ps[iid][ch]){
			if(nn[now].l!=-1)query(nn[now].l,iid,dep+1,cid,cdis);
			else{
				if(nid==iid)return ;
				dtmp = dist(nid,iid);
				if(dtmp<cdis){
					cdis = dtmp;
					cid = nid;
				}
				return ;
			}
			dir = 0;
		}
		else{
			if(nn[now].r!=-1)query(nn[now].r,iid,dep+1,cid,cdis);
			else{
				if(nid == iid) return ;
				dtmp = dist(nid,iid);
				if(dtmp<cdis){
					cdis = dtmp;
					cid = nid;
				}
				return ;
			}
			dir = 1;
		}
		if(sq(ps[nid][ch]-ps[iid][ch])>=cdis)return ;
		if(dir==1)query(nn[now].r,iid,dep+1,cid,cdis);
		else query(nn[now].l,iid,dep+1,cid,cdis);
	}
	*/
	void print_t(int now,int dep,int dir)
	{
		if(now==-1)return;
		int iid = nn[now].id;
		printf("now at %d %d dep %d dir %d\n",ps[iid][0],ps[iid][1],dep,dir);
		print_t(nn[now].l,dep+1,0);
		print_t(nn[now].r,dep+1,1);
	}
};
int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		int a,b;
		K=2;
		for(int i=1;i<=N;i++)
			scanf("%d%d",&ps[i][0],&ps[i][1]);
		Kdtree rt;
		rt.build();
		for(int i=1;i<=N;i++){
			ll cdis = inf;
			int cid = -1;
			rt.query(0,i,0,cid,cdis);
			if(cdis!=inf)printf("%lld\n",cdis);
			else printf("-1\n");
		}
	}
}

