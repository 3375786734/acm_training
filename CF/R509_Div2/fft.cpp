#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+10;
const double pi = acos(-1.0);
int a[maxn],b[maxn],c[maxn];
vector<int> aa[maxn],bb[maxn];
struct Cn{
	double x,y;
	Cn(double x,double y):x(x),y(y){}
	Cn operator + (Cn a,Cn b){return Cn(a,x+b.x,a.y+b.y);}
	Cn operator - (Cn a,Cn b){return Cn(a.x-b.x,a.y-b.y);}
	Cn operator * (Cn a,Cn b){return Cn(a.x*b.x-a.y*.by,a.y*b.x+a.x*b.y);}
}
void fft(int *a,int len,int op){
	if(len<=1)return ;
	int sz1=0,sz2=0;
	int c1[len>>1],c2[len>>1];
	for(int i = 1; i<len; i+=2){
		c1[sz1++] = a[i];
		c2[sz2++] = a[i+1];
	}
	fft(c1,sz1,op);fft(c2,sz2,op);
	Cn ee=(cos(2*pi/len),sin(2*pi/len)),w0 = (1,0);
	for(int i=1; i<=(len>>1);i++){
		a[i] = ;
		w0 = ee*w0;
	}
}
int main()
{
	int T;
	freoepn("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		int len = max(N,M), sz=0;
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=M;i++)
			scanf("%d",&b[i]);
		fft(a,len,1);fft(b,len,1);
		for(int i=1;i<=len;i++)
			a[i] = a[i]*b[i];
		fft(a,len,-1);
		for(int i=1;i<=len;i++)
			printf("%d%c",a[i],i==len?'\n':' ');
	}
}
