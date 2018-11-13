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
//const int maxn=;
//const double esp=1e-6

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int d;
		scanf("%d",&d);
		double delta = d*d -4*d;
		if(delta <0)
			printf("N\n");
		else{
			double de =d<4?sqrt(delta):sqrt((double)d)*sqrt(d-4.0);
			double  x1 = (d-de)/2.0;
			if(x1<0){
				printf("N\n");
			}
			else {
				double x2;
				printf("Y %.12lf %.12lf\n",x2=((d+de)/2.0),x1);
				//printf("%lf %lf \n",x1+x2,x1*x2);
			}
		}
	}
}

