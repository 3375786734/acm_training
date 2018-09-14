/*
 *idea:先考虑没有线相交的情形,此时,整点个数为gcd(|x1-x2|,|y1-y2|)+1;
 *这是因为 表达式 (y2-y1)/(x2-x1)*(x_k-x_1)=(m*gcd/n*gcd)*kn ,由于kn<n*gcd
 *因此  0<=k<=gcd   一共有 gcd+1个点满足要求
 *  
 *然后枚举两两相交的情形即可 
 */
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PP;
typedef pair<PP,PP> LI;
const int eps=1e-4;
const int maxn=1e4;
int N;
set<PP> ss;
int Abs(int a){
	if(a>0)return a;
	else return -a;
}
LI ll[maxn];
map<PP,int> mm;
map<int,int> num;
bool inr(PP a,PP b,PP c){
//	int d1=a.f-b.f,d2=b.f-c.f,d3=a.s-b.s,d4=b.s-c.s;
//	if(d1*d2>=0&&d3*d4>=0)return true;
	LL lh=min(b.f,c.f),rh=max(b.f,c.f),lv=min(b.s,c.s),rv=max(b.s,c.s);
	if(a.f>=lh&&a.f<=rh&&a.s>=lv&&a.s<=rv)return true;
	else return false;
}
void count(int a,int b){	
//	printf("now %d %d\n",a,b);
	int sz=0;
	PP p1=ll[a].f,p2=ll[a].s,q1=ll[b].f,q2=ll[b].s;
	LL dy1=p2.s-p1.s,dy2=q2.s-q1.s,dx1=p2.f-p1.f,dx2=q2.f-q1.f;
	LL kk=(dy1*dx2-dy2*dx1),ww=(q1.s-p1.s)*dx1*dx2;
	LL mmm=dy2*dx1*q1.f-dy1*dx2*p1.f,nnn=ww-mmm;
	if(kk!=0&&nnn%kk==0){
		LL x3=nnn/kk,y3=-1e9;
		if(dx1!=0&&(dy1*(x3-p1.f)%dx1==0))y3=dy1*(x3-p1.f)/dx1+p1.s;
		else if(dx2!=0&&(dy2*(x3-q1.f)%dx2==0))y3=dy2*(x3-q1.f)/dx2+q1.s;
//		printf("now %d %d ",x3,y3);
		if(y3>-1e9&&inr(mp(x3,y3),p1,p2)&&inr(mp(x3,y3),q1,q2))mm[PP(x3,y3)]++;
	}
	return;
}
int main()
{
	scanf("%d",&N);
	int x1,y1,x2,y2,ans=0;
	for(int i=1;i<=1200;i++)num[(i*(i+1)/2)]=i;
	for(int i=1;i<=N;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ans+=__gcd(Abs(x1-x2),Abs(y1-y2))+1;
		ll[i]=mp(PP((LL)x1,(LL)y1),PP((LL)x2,(LL)y2));
	}
//	printf("%d\n",ans);
	for(int i=1;i<=N;i++)
		for(int j=1;j<i;j++){
			count(i,j);
			/*
			PP p1=ll[i].f,p2=ll[i].s,q1=ll[j].f,q2=ll[j].s;
			double k1=1.0*(p1.s-p2.s)/(p1.f-p2.f);
			double k2=1.0*(q1.s-q2.s)/(q1.f-q2.f);
			double xx=(q1.s-p1.s+k1*p1.f-k2*q1.f)/(k1-k2);
			double yy=k1*(xx-p1.f)+p1.s;
			if(fabs(xx-floor(xx))<eps&&fabs(yy-floor(yy))<eps)
				if(xx>=x1&&x1<=x2)ss.insert(PP((xx,yy));
			*/
		}
	for(map<PP,int>::iterator it=mm.begin();it!=mm.end();it++){
		ans-=num[it->second];
//		printf("%d %d  %d\n",(it->f).f,(it->f).s,it->s);
	}
	printf("%d\n",ans);
}
