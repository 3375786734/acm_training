#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn=1e5+100;
const double inf=1e9;
int N;
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
Point pp[maxn];
double sq(double x){
	return x*x;
}
double dist(Point a,Point b){
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}
bool cmpy(Point a,Point b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
bool cmpx(Point a,Point b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
double get_it(Point *pp,int l,int r,int &p,int &P){
	double dis=inf;
	for(int i=l;i<=r;i++)
		for(int j=i+1;j<=r;j++)
			if(dis>dist(pp[i],pp[j])){
				p = i;P = j;
				dis = dist(pp[i],pp[j]);
			}
	return dis;
}
double get_strip(Point *pp,int sz,int &p,int &P){
	sort(pp,pp+sz,cmpy);
	double dis=inf;
	for(int i=0;i<sz;i++)
		for(int j=1;j<=7;j++)
			if(dis>dist(pp[i],pp[i+j])){
				p = i ; P = i+j;
				dis = dist(pp[i],pp[i+j]);
			}
	return dis;
}
double fd_pair(Point *pp,int l,int r,int &p,int &P)
{
	if(r-l+1<=3)return get_it(pp,l,r,p,P);
	int mid=(l+r)/2,pl,Pl,pr,Pr;
	double dl = fd_pair(pp,l,mid,pl,Pl);
	double dr = fd_pair(pp,mid+1,r,pr,Pr);
	double d = min(dl,dr);
	if(dl>=dr)p = pr,P = Pr;
	else p=pl,P = Pl;
	double mx = pp[mid].x;int sz=0;
	Point strip[maxn];
	for(int i=l;i<=r;i++)
		if(fabs(pp[i].x-mx)<=d)strip[sz++] = i;
	int pmid,Pmid;
	double pdis=0,ans = min(d,pdis=get_strip(strip , sz,pmid,Pmid));
	if(d>pdis)p = pmid,P = Pmid;
	return ans;
}
int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int a,b;
		for(int i=1;i<=N;i++){
			scanf("%d%d",&a,&b);
			pp[i]=Point(a,b);
		}
		sort(pp+1,pp+1+N,cmpx);
		int p1,p2;
		double dis = fd_pair(pp,1,N,p1,p2);
		printf("dis = %lf: pair (%d ,%d)\n",dis,p1,p2);
	}
}

