/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
const int maxn=6e4+100;
const int maxk=6;

struct Point{
	ll x[maxk];
	//这里仅仅是为了满足priority_queue的要求没什么含义
	bool operator<(const Point &a)const{
		return x[0]<a.x[0];
	}
};
typedef pair<double,Point> PP;
Point pp[maxn],ans[maxn];
int  N,K;
inline double sq(double a){return a*a;}
double dist(Point a,Point b){
	double ans = 0;
	for(int i=0;i<K;i++)
		ans += sq(a.x[i]-b.x[i]);
	return ans;
}
class Kdtree{
public:
	//if NULL tag = -1,if has node tag =0
	int tag[maxn<<2];
	//tree node
	Point node[maxn<<2];
	priority_queue<PP> qq;
	void init(){
		MEM(tag,0);MEM(node,0);
		while(!qq.empty())qq.pop();
	}
	/*
	 * 这里将rt作为索引标号
	 *@para : l = 0 ,r = N-1,rt = 1,dep = 0
	 */
	void build(int l,int r,int rt,int dep)
	{
		if(l>r) return;
		tag[rt] = 1;
		tag[rt<<1] = tag[rt<<1|1]=-1;
		int dim = dep%K;
		int mid =(l+r)/2;
		//note here,这三个数的范围需要注意.
		nth_element(pp+l,pp+mid,pp+r+1,[&](Point a,Point b){return a.x[dim]<b.x[dim];});
		node[rt] = pp[mid];
		//往下递归没有mid
		build(l,mid-1,rt<<1,dep+1);
		build(mid+1,r,rt<<1|1,dep+1);
	}
	/*
	 *@para : initial rt =1,dep =0,query point q, M-nearest.
	 *@return:point and it's dist,note that this pri_queue is a decrease queue.
	 */
	void query(int rt,int dep,Point q,int M)
	{
		int dim = dep%K,flag = 0;
		int l = rt<<1,r = rt<<1|1;
		PP tmp = PP(dist(q,node[rt]),node[rt]);
		//目的是为了防止重复的代码,逻辑和原始算法是一样的,先看满足的一边
		if(node[rt].x[dim]<=q.x[dim])swap(l,r);
		//可以往下递归的话.
		if(tag[l]!=-1)query(l,dep+1,q,M);
		if(qq.size()<M){
			qq.push(tmp);flag=1;
		}
		else{
			if(dist(q,node[rt])<qq.top().first){
				qq.pop();qq.push(tmp);
			}
			//如果这里存在点可以被更新的就往下递归
			if(sq(q.x[dim]-node[rt].x[dim]) < qq.top().first)flag=1;
		}
		if(flag&&tag[r]!=-1)query(r,dep+1,q,M);
	}
};

int main()
{
	//freopen("t.in","r",stdin);
	ll a;
	for(int i=0;i<N;i++)
		for(int j=0;j<K;j++){
			scanf("%lld",&a);
			pp[i].x[j]=a;
		}
	Kdtree rt;
	rt.init();rt.build(0,N-1,1,0);
	int t,M;
	scanf("%d",&t);
	Point q;
	for(int i=1;i<=t;i++){
		for(int j=0;j<K;j++)
			scanf("%lld",&q.x[j]);
		scanf("%d",&M);
		printf("the closest %d points are:\n",M);
		rt.query(1,0,q,M);
		int sz = 0;
		while(!rt.qq.empty()){
			Point tmp = rt.qq.top().second;rt.qq.pop();
			ans [sz++] = tmp;
		}
		for(int i=M-1;i>=0;i--)
			for(int j=0;j<K;j++)
				printf("%lld%c",ans[i].x[j],j==K-1?'\n':' ');
		}
	}
}
