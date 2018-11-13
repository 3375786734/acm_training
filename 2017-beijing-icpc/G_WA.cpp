/*  -*- scoding: utf-8 -*- */
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
int dx[10] = {1,1,1,0,0,-1,-1,-1};
int dy[10] = {-1,1,0,-1,1,1,-1,0};
char G[maxn][maxn];
int vis[maxn][maxn][9];
double x1,y1,x2,y2,x3,y3;
bool inbound(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}
bool intersect(PP a,PP b,PP c ,PP d)
{
	double ax = a.fi ,ay = a.se, bx = b.fi, by = b.se;
	double cx = c.fi ,cy = c.se, dx = d.fi, dy = d.se;
	double delta = (by-ay)*(dx-cx)-(dy-cy)*(bx-ax);
	//这里会出现重合不能继续往里走的情形.
	if(fabs((by-ay)*(dx-cx)-(dy-cy)*(bx-ax))<eps)
		return false;
	else{
		double  aa = (cy-ay)*(dx-cx)*(bx-ax);
		double  bb = (by-ay)*(dx-cs)*ax-(dy-cy)*(bx-ax)*ax;
		double  x  = (aa+bb)/delta;
		if(x>=min(ax,bx)&&x<=max(ax,by))return true;
		else return false;
	}
}
void preprocess()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			tmp[i][j]  = G[i][j];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			G[i][j] = tmp[N-1-i][j];	
	for(int i=0;i<N;i++)
		for(int j = 0;j<N;j++)
			for(int k=0;k<8;k++)
				for(int n = 0;n<3;n++)
					for(int m=n+1;m<3;m++)
						if(intersect(PP(x[n],y[n]),PP(x[m],y[m]),PP(j,i),PP(j+dx[k],i+dy[k])))
							vis[i][j][k] =1;
	
}
int solve()
{
	priority_queue<>
}
int main()
{
	while(~scanf("%d",&N))
	{
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
		rep(i,1,N)
			scanf("%s",G[i]);
		printf("%d\n",solve());
	}
}
