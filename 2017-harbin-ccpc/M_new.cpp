/*
 *注意到,随机抽出3个点,如果都在圆上概率为0.125,因此不能构成圆的概率为0.875,但是这样随机的选择100次,那么概率就会大大降低,是很巧妙.
 *
 */
#include <bits/stdc++.h>
//#define f first
//#define s second
using namespace std;
const int maxn=2e5+100;
const double eps=1e-5;
const double inf=1e9;
//typedef pair<double,double > PP;
struct PP{
	double f,s;
	PP(double f=0,double s=0):f(f),s(s){}
};
PP pp[maxn];
int N;
double dis(PP a,PP b){
    return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}
PP geto(PP a,PP b,PP c)
{
	double a1=b.f-a.f, b1 = b.s-a.s , c1 = (a1*a1+b1*b1)/2;
	double a2=c.f-a.f, b2 = c.s-a.s , c2 = (a2*a2+b2*b2)/2;
	double d= a1*b2 - a2*b1;
	if(d<eps)return PP(1e18,1e18);
	return  PP(a.f+(c1*b2-c2*b1)/d, a.s+(a1*c2-a2*c1)/d);
}
bool ison(PP x,PP o,double rid){
	return fabs(dis(x,o)-rid)<eps;
}
PP solve(int bnd,double &r)
{
	while(1){
		int a=rand()%N;
		int b=rand()%N;
		int c=rand()%N;
		PP aa=pp[a];
		PP bb=pp[b];
		PP cc=pp[c];
		if(a==b||b==c||a==c)continue;
		PP oo=geto(aa,bb,cc);
		r=dis(oo,aa);
		if(abs(oo.f)>inf||abs(oo.s)>inf||r>inf)continue;

		int cnt=0;
		for(int i=1;i<=N;i++)
			if(ison(pp[i],oo,r)){
				cnt++;
				if(cnt>=bnd)return oo;
			}
	}
}
int main()
{
	int T;
	srand(time(0));
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		double xx,yy;
		for(int i=1;i<=N;i++){
			scanf("%lf%lf",&xx,&yy);
			pp[i] = PP(xx,yy);
		}
		if(N==1)printf("%f %f 1\n",pp[1].f+1,pp[1].s);
		else if(N<=4){
			//PP ans = geto(pp[1],pp[2],r);
			PP ans=PP((pp[1].f+pp[2].f)/2,(pp[1].s+pp[2].s)/2);
			double r=dis(pp[1],ans);//sqrt((pp[1].f-ans.f)*(pp[1].f-ans.f)+(pp[1].s-ans.s)*(pp[1].s-ans.s));
			printf("%f %f %f\n",ans.f,ans.s,r);
		}
		else if(N>=5){
			double r=0;
			PP ans=solve((N+1)/2,r);
			printf("%f %f %f\n",ans.f,ans.s,r);
		}
	}
}
