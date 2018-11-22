/*  -*- coding: utf-8 -*- */
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
const int maxn = 2e3;
const int inf = 1e7;
const double eps = 1e-6;
int a[maxn],b[maxn];
int N,K;
double d[maxn];
bool cmp(double a,double b){
	return a>b;
}
bool check(double mid)
{
	for(int i=1;i<=N;i++)
		d[i] = a[i] - mid*b[i];
	sort(d+1,d+1+N,cmp);
	double sum =0;
	for(int i=1;i<=N-K;i++)
		sum+= d[i];
	if(sum>=0)return true;
	else return false;
}
int sovle()
{
	double l=0,r= inf;
	double ans = 0;
	while(r-l>eps)
	{
		
		double mid =(l+r)/2;
		if(check(mid)) l = mid;
		else r =mid;
	}
	return 100*(0.005+l);
}
int main()
{
	while(~scanf("%d%d",&N,&K)&&N!=0){
		for(int i =1;i<=N;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=N;i++)
			scanf("%d",&b[i]);
		printf("%d\n",sovle());
	}
}

