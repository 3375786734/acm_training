/*  -*- coding: utf-8 -*- */
/*
 *细节问题:最后一块木块应该靠着大的一端放,考虑从小的一端可以不断向大的一端移动,半径因此减小.
 */
#include <bits/stdc++.h>
#define MEM(a,b) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<double,double> PP;
const int maxn=1e5+100;
const double eps=1e-10;
int N;
double nn[maxn];
double sq(double a){
	return a*a;
}
bool check(double rid)
{
	double l=rid ,L =rid;
	for(int i=1;i<=N;i++){
		if(l>L) swap(l,L);
		//printf("at %lf %lf\n",rid,nn[i]);
		if(rid*rid-nn[i]*nn[i]<0)return false;
		L = min(L,sqrt(rid*rid-nn[i]*nn[i]));
		if(L>=1.0)L-=1.0;
		else {
			//printf("at %lf\n",rid);
			if(l+L<1.0)return false;
			if(i<N)return false;
			if(rid*rid-nn[i]*nn[i]<)return false;
		}
	}
	return true;
}
double solve()
{
	double l=0,r =1e9;
	while(fabs(r-l)>eps){
		double mid =(l+r)/2;
		//printf("here %lf\n",mid);
		if(check(mid))r = mid;
		else l = mid;
	}
	return r;
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		double a,b;
		for(int i=1;i<=N;i++){
			scanf("%lf%lf",&a,&b);
			nn[i]  = min(sqrt(sq(a)+sq(b/2)),sqrt(sq(a/2)+sq(b)));
		}
		sort(nn+1,nn+1+N);
		printf("Case #%d: %lf\n",cas++,solve());
	}
}

