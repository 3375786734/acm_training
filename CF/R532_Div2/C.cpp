#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const double pi =acos(-1.0);
const double eps =1e-7;
int N,r;
bool check(double mid)
{
	double ang = pi/N,dis = sin(ang)*(mid+r);
	if(dis<=mid)return true;
	else return false;
}
double solve(int N,int r)
{
	double lb =0,rb = 1e18;
	while(fabs(lb-rb)>eps){
		double mid =(lb+rb)/2;
		if(check(mid))lb= mid;
		else rb =mid;
	}
	return (lb+rb)/2;
}
int main()
{
	scanf("%d%d",&N,&r);
	printf("%lf\n",solve(N,r));
}

