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
const double inf = 1e23;
const double eps = 1e-6;
const int maxn=2000;
class Point{
public:
	double px,py;
	Point(double px = 0,double py = 0):px(px),py(py){}
};
class Line{
public:
	Point a;
	Point b;
	int is_seg,is_verti;
	bool IsVerti()
	{
		if(fabs(a.px-b.px)<eps)return is_verti =1;
		else return is_verti =0;
	}
	//1-in  0- no  2- para
	int parallel(const Line &line)const {
		if(fabs((b.py-a.py)*(line.b.px-line.a.px) - (b.px-a.px)*(line.b.py-line.a.py))<eps){
			if(fabs(b.px-a.px)<eps){
				if(fabs(line.a.px-a.px)<eps)return 1;
				else return 2;
			}
			else{
				double k = (b.py-a.py)/(b.px-a.px);
				if(fabs((a.py-k*a.px)-(line.a.py-k*line.a.px)<eps)return 1;
				else return 2;
			}
		}
		else return 0;
	}
	Point interset(const Line &line)const{
		if(parallel(line)==0){
			if(!isverti()){
				double k = (b.py-a.py)/(b.px-a.px);
				double b = a.py-k*a.px;
				if(line.isverti()){
					double  yy = a.y+k*(line.a.px-a.px);
					return Point(line.a.px,yy);
				}
				else{
					double k2 = (line.a.py-line.b.py)/(line.a.px-line.b.px);
					double b2 = line.a.py  - k2*line.a.px;
					return Point(xx,yy);
				}
			}
			else{
				
			}
		}
		else return Point(inf,inf);
	}
};
int main()
{
	Point a(0,0),b(1,1),c(0,1),d(1,0);
	Line l1 ,l2 ;
	l1.a = a;l1.b = b;
	l2.a = a;l2.b = b;
	Point p = l1.intersect(l2);
	printf("%lf %lf",p.px,p.py);
}

