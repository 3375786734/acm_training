#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6;

double a,b,c,d,e,f;
double T;
struct Node{
	double x,y,z;
};

double dis(Node a){
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
Node get_node(Node tmp){
	double x=tmp.x,y=tmp.y,z=tmp.z,nz,aa,bb,cc;
	int tag=rand()%2;
	if(tag<=1){
		double aa=c,bb=(d*y+e*(x+eps)),cc=-(1-(b*y*y+a*(x+eps)*(x+eps)+f*(x+eps)*y));
		double p=-bb*.5/aa,q=sqrt(bb*bb-4*aa*cc)*.5/a;
		if(fabs(p+q-z)<eps)nz=p+q;
		else nz=p-q;
		return (Node){x+eps,y,nz};
	}
	else{
		 aa=c,bb=d*(y+eps)+e*x,cc=-(1-f*x*(y+eps)-b*(y+eps)*(y+eps)-a*x*x);
		 double p=-bb*0.5/aa,q=sqrt(bb*bb-4*aa*cc)*0.5/a;
		 if(fabs(p+q-z)<eps)nz=p+q;
		 else nz=p-q;
		 return (Node){x,y+eps,nz};
	}
}
int main()
{
	T=1;
	srand(time(NULL));
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	Node S=(Node){0,0,sqrt(1.0/c)};
	while(1){
		Node tmp=get_node(tmp);
		double delta=dis(tmp)-dis(S);
		printf("here %lf %lf %lf %lf %lf %lf %lf\n",S.x,S.y,S.z,tmp.x,tmp.y,tmp.z,delta);
		if(fabs(delta)<eps)break;
		if(delta<=0)S=tmp;
		else if(rand()<exp(-delta/T))S=tmp;
	}
	printf("%lf\n",dis(S));
}
