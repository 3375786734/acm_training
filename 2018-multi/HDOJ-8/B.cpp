/*考虑到一定有一个角落在底上,为了使宽度充分利用,那么这个角应该贴着矩形的角
 */
#include <bits/stdc++.h>
using namespace std;
//const  int maxn=;
const double pi=acos(-1.0);
double Abs(double a){
	if(a>=0)return a;
	else return -a;
}
double dist(double x1,double y1,double x2,double y2){
	double x=(x1-x2),y=(y1-y2);
	return sqrt(x*x+y*y);
}
int main()
{
	int T;
	freopen("b.in","r",stdin);
	freopen("B.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int x1,y1,x2,y2,x3,y3,w;
		scanf("%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&w);
		double S=Abs((x1-x3)*(y1-y2)-(x1-x2)*(y1-y3));
		double a[3];
		a[0]=dist(x1,y1,x2,y2),a[1]=dist(x1,y1,x3,y3),a[2]=dist(x2,y2,x3,y3);
		/*
		double t1=(a[0]*a[0]+a[1]*a[1]-a[2]*a[2])/(2.0*a[0]*a[1]),t2=(a[1]*a[1]+a[2]*a[2]-a[0]*a[0])/(2.0*a[1]*a[2]),t3=(a[0]*a[0]+a[2]*a[2]-a[1]*a[1])/(2.0*a[0]*a[2]);
		*/
		double ans=1e9;
		for(int i= 0; i < 6; i++)
		{
			if(a[0]<=w){
				double th1=(a[0]*a[0]+a[1]*a[1]-a[2]*a[2])/(2.0*a[0]*a[1]);
				double th2=(a[0]*a[0]+a[2]*a[2]-a[1]*a[1])/(2.0*a[0]*a[2]);
				if((th1>=0&&th2>=0)
					||(th1<0&&(a[0]-th1*a[1]<=w)))ans=min(ans,S/a[0]);
				else if(th1<0&&(a[0]-th1*a[1]>w)){
					double t3=acos(w/a[2]);
					if(t3>=th2)ans=min(ans,sqrt(a[2]*a[2]-w*w));
				}
			}
			else{
				double t1=acos((a[1]*a[1]+a[0]*a[0]-a[2]*a[2])/(2.0*a[1]*a[0]));
				double t2=acos(sqrt(a[0]*a[0]-w*w)/a[0]);
				double t3=acos((a[0]*a[0]+a[2]*a[2]-a[1]*a[1])/(2.0*a[0]*a[2]));
				if(t1+t2<=pi){
					if(t3<=t2){
						double l1=a[1]*cos(pi-t1-t2),l2=sqrt(a[0]*a[0]-w*w);
						if(t1+t2>=0.5*pi)
							ans=min(ans,l1+l2);
						else ans=min(ans,l2);
					}
				}
				else ans=min(sqrt(a[2]*a[2]-w*w),ans);
			}
			next_permutation(a,a+3);
		}
		if(ans==1e9)printf("impossible\n");
		else printf("%lf\n",ans);
	}
}
