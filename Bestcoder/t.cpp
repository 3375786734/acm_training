#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<double,double> PP;
typedef long long ll;
const int maxn=1e5+100;
const ll inf= 2e10;
map<PP,int>  ss;
int N;
struct Point{
	ll x,y;
	int id;
	Point(ll x=0,ll y=0,int id=0):x(x),y(y),id(id){}
};
Point pp[maxn],strip[maxn];
ll sq(ll x){
	return x*x;
}
ll dist(Point a,Point b){
	return sq(a.x-b.x)+sq(a.y-b.y);
}
bool cmpy(Point a,Point b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
bool cmpx(Point a,Point b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
lle get_it(Point *pp,int l,int r,int &p,int &P){
	lldis=inf;
	for(int i=l;i<=r;i++)
		for(int j=i+1;j<=r;j++)
			if(dis>dist(pp[i],pp[j])){
				p = pp[i].id;P = pp[j].id;
				dis = dist(pp[i],pp[j]);
			}
	//printf("res %lf\n",dis);
	return dis;
}
double get_strip(Point *pp,int sz,int &p,int &P){
	sort(pp,pp+sz,cmpy);
	double dis=inf;
	for(int i=0;i<sz;i++)
		for(int j=1;j<=7;j++)
			if(i+j<sz&&dis>dist(pp[i],pp[i+j])){
				p = pp[i].id ; P = pp[i+j].id;
				dis = dist(pp[i],pp[i+j]);
			}
	//printf("strip here %lf\n",dis);
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
	for(int i=l;i<=r;i++)
		if(fabs(pp[i].x-mx)<=d)strip[sz++] = pp[i];
	int pmid,Pmid;
	/*
	rep(i,0,sz-1)
		printf("ss %lf %lf\n",strip[i].x,strip[i].y);
	*/
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
	//while(~scanf("%d",&N)&&N!=0){
		double a,b,dis=0;
		int ok=0,p1,p2;
		ss.clear();

		for(int i=1;i<=N;i++){
			scanf("%lf%lf",&a,&b);
			pp[i]=Point(a,b,i);
			if(ss.count(PP(a,b))){
				p1 = ss[PP(a,b)];
				p2 = i;ok=1;
			}
			else ss[PP(a,b)]=i;
		}
		if(ok==0){
			sort(pp+1,pp+1+N,cmpx);
			dis = fd_pair(pp,1,N,p1,p2);
		}
		else dis=0;
		printf("dis = %lf: pair (%d ,%d)\n",dis/2.0,p1,p2);
	}
}
