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
const double eps=1e-6;
const int maxn=500;
const int inf = 1e9;
int dx[10] = {1,1,1,0,0,-1,-1,-1};
int dy[10] = {1,0,-1,1,-1,1,0,-1};
struct Point{
	double px,py;
	Point(double px = 0,double py =0 ):px(px),py(py){}
	Point operator+(const Point &a)const{
		return Point(a.px+px,a.py+py);
	}
	Point operator/(const double &a){
		return Point(px/a,py/a);
	}
};
struct Line{
	Point a,b;
	int ori,is_ver;
	bool isver(){
		return is_ver=(fabs(a.px-b.px)<eps);
	}
	//1-up , -1 -below 0-in
	int below(Point cc)
	{
		double c = (a.px*b.py - b.px*a.py);
		//if(cc.py==0&&cc.px==1)printf("ori %lf %lf\n",c,c - cc.px*(b.py-a.py)+cc.py*(b.px-a.px));
		if(fabs(c-cc.px*(b.py-a.py)+cc.py*(b.px-a.px))<eps)return 0;
		else return (c - cc.px*(b.py-a.py)+cc.py*(b.px-a.px))<0?-1:1;	
	}
};
Line l[4];
char G[maxn][maxn];
int N,M;
void trans(char G[][maxn]){
	char tmp[maxn][maxn];
	for(int i=0;i<N;i++)
		strcpy(tmp[i],G[i]);
	for(int i=0;i<N;i++)
		strcpy(G[i],tmp[N-1-i]);
}
bool check(int i,int j)
{
	for(int k= 0;k<3;k++)
		if(i==0&&j==1)printf("orti %d\n",l[k].below(Point(j,i)));
	for(int k = 0;k<3;k++){	
		if(l[k].ori != l[k].below(Point(j,i)))return true;
	}
	return false;
}
void process(char G[][maxn])
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!check(i,j))G[i][j]  ='#';
}
struct Node{
	int id,dis;
	bool operator<(const Node &a)const{
		return dis>a.dis;   //大顶堆
	}
};
int dis[maxn],vis[maxn];
void getps(int &x,int &y,int id){
	y = id/N;
	x = id%N;
}
int solve()
{
	MEM(dis,0x3f3f3f);
	MEM(vis,0);
	dis[0] = 0;
	priority_queue<Node> q;
	q.push((Node){0,0});
	while(!q.empty()){
		Node fa = q.top();q.pop();
		int id=fa.id,xx,yy;
		printf("now %d\n",id);
		if(vis[id])continue;
		vis[id]=1;
		for(int i=0;i<8;i++){
			getps(xx,yy,fa.id);
			int nx = xx+dx[i], ny = yy+dy[i];
			int to = nx+ny*N;
			printf("now %d %d %d %d\n",nx,ny,xx,yy);
			if(!(nx>=0&&nx<N&&ny>=0&&ny<N)||(G[ny][nx]=='#'))continue;
			printf("ehre\n");
			if(dis[id]+1 < dis[to]){
				dis[to] = dis[id]+1;
				q.push((Node){to,dis[to]});
			}
		}
	}
	return dis[(N-1)*N+N-1];
}
void get_ori()
{
	Point mid[5];
	for(int i=0;i<3;i++)
		mid[i] = (l[i].a+l[i].b)/2.0;
	l[0].ori=l[0].below(mid[1]);
	l[2].ori=l[2].below(mid[1]);
	l[1].ori=l[1].below(mid[2]);
	for(int i=0;i<3;i++)
		printf("ori  %d\n",l[i].ori);
}
int main()
{
	freopen("t.in","r",stdin);
	while(~scanf("%d",&N))
	{
		double a,b;
		Point pp[5];
		for(int i=0;i<3;i++){
			scanf("%lf%lf",&a,&b);
			pp[i] = Point(a,b);
		}
		l[0].a=pp[0],l[0].b=pp[1];
		l[1].a=pp[0],l[1].b=pp[2];
		l[2].a=pp[1],l[2].b=pp[2];
		get_ori();
		for(int i=0;i<N;i++)
			scanf("%s",G[i]);
		trans(G);
		process(G);
		for(int i=0;i<N;i++)
			printf("%s\n",G[i]);
		printf("%d\n",solve());
	}
}
