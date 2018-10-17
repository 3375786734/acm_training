#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const double inf=1e60;
int dx[10]={0,0,1,-1,1,-1,-1,1};
int dy[10]={1,-1,0,0,1,-1,1,-1};
double a,b,c,d,e,f;
double T;
struct Node{
	double x,y,z;
};
float GetRandomReal(float low, float up) { 
	float fResult; 
	if (low > up){ 
		int temp = low; 
		low = up; 
		up = temp; 
	} 
	fResult = low + (up - low) * rand() / (RAND_MAX + (long long)1); return fResult;
}
double dis(Node a){
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
Node get_node(Node tmp,double step,int op){
	double x=tmp.x,y=tmp.y,z=tmp.z,aa,bb,cc,nz;
	double nx=x+dx[op]*step;
	double ny=y+dy[op]*step;
	aa=c;
	bb=d*ny+e*nx;
	cc=b*ny*ny+a*nx*nx+f*nx*ny-1;
	double delta=bb*bb-4.0*aa*cc;
	//if(delta>=0)printf("%lf %lf %lf\n",nx,ny,delta);
	if(delta<0)return (Node){nx,ny,inf};
	double p=-bb/aa/2,q=sqrt(delta)/aa/2;
	if((p+q)*(p+q)>(p-q)*(p-q))nz=p-q;
	else nz=p+q;
	return (Node){nx,ny,nz};
}
int main()
{
	srand(time(NULL));
	while(~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)){
	Node S=(Node){0,0,sqrt(1.0/c)};
	T=10000;
	while(T>=eps){
		Node tmp;
		for(int i=0;i<8;i++){
			tmp=get_node(S,T,i);
			double delta=dis(tmp)-dis(S);
		//printf("here %lf %lf %lf %lf %lf %lf%lf\n",S.x,S.y,S.z,tmp.x,tmp.y,tmp.z,delta);
			if(tmp.z>=1e30)
				continue;
			if(delta<0)S=tmp;
			//这里需要防止跳变出现的太多,因此概率要设小一点
			else if(exp(-delta/T)>GetRandomReal(0,100))S=tmp;
		}
		//else if(exp(-delta/T)>GetRandomReal(0,1))S=tmp;
		T*=0.99;
	}
	printf("%lf\n",dis(S));
	}
}
