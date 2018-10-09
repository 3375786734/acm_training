/*
 *1.这题的数据会卡你的精度,注意到这里是相对误差,当l-r很大的时候,应该算相对误差而不能是绝对误差,否则会死循环
 *2.注意一些数学运算函数,尤其是平方之后数太大了,再经过数学函数,会有较大的精度损失,
   例如sqrt(a*a-b*b)应该写成 sqrt(a-b)sqrt(a+b)
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+10;
const double eps=1e-12;
double l[maxn],r[maxn];
double x[maxn],y[maxn];
int N;
inline double safe_sqrt(const double & D){
	return D < 0 ? 0 : sqrt(D);
}
bool ok(double rid){
	double ml =-2e8,mr=2e8;
	rep(i,1,N){
		double dd = fabs(y[i]-rid);
		//printf("dd %lf rid %lf\n",dd,rid);
		if(dd>rid)return false;
		double pp=safe_sqrt(rid-dd)*safe_sqrt(rid+dd);
		double l = x[i]-pp, r = x[i]+pp;
		if(l > ml)ml = l;
		if(r < mr)mr = r;
	}
	if(ml > mr)return false;
	else return true;
}
double bsrch(double r){
	double l = 0;
	while(1){
		double mid=(l+r)/2;
		if((r-l)/mid<=eps)break;
		//printf("here %lf %lf l %lf r %lf\n",mid,r-l,l,r);
		if(ok(mid))r=mid;
		else l=mid;

	}
	return l;
}
int main()
{
	scanf("%d",&N);
	int pre=0,ok=1;
	double maxy=y[1],miny=y[1];
	rep(i,1,N){
		scanf("%lf%lf",&x[i],&y[i]);
		miny=min(miny,y[i]);
		maxy=max(maxy,y[i]);
		y[i]=fabs(y[i]);
	}
	//printf("")
	if(miny<0&&maxy>0)printf("-1\n");
	else printf("%lf\n",bsrch(1e16));
}
