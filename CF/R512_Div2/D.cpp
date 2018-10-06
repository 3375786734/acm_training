#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

struct node
{
	int x,y;
} a[maxn],p[maxn];
int top,n;
double cross(node p0,node p1,node p2)//计算叉乘，注意p0,p1,p2的位置，这个决定了方向
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(node a,node b)//计算距离，这个用在了当两个点在一条直线上
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp2(node a,node b){
	return a.x<b.x;
}
bool cmp(node p1,node p2)//极角排序
{
	double z=cross(a[0],p1,p2);
	if(z>0||(z==0&&dis(a[0],p1)<dis(a[0],p2)))
		return 1;
	return 0;
}
//核心思想先找到左下角的那一个点,以他为起点,沿着计较排序的方向进行计算,最终就可以得到凸包
void Graham()
{
	int k=0;
	for(int i=0; i<N; i++)
		if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x))
			k=i;
	swap(a[0],a[k]);//找p[0]
	sort(a+1,a+N,cmp);
	top=1;
	p[0]=a[0];
	p[1]=a[1];
	for(int i=2; i<N; i++)//控制进栈出栈
	{
		while(cross(p[top-1],p[top],a[i])<0&&top)
		top--;
		top++;
		p[top]=a[i];
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	int x,y,ok=1,pre=0;
	rep(i,0,N-1){
		scanf("%d%d",&x,&y);
		a[i].x=x;a[i].y=y;
		if(i==0)pre=a[i].y;
		else if(pre*a[i].y<0)
	}
	if(N>=3){
		Graham();
		sort(p,p+top+1,cmp2);
		node l=p[0],r=p[top];
		printf("")
	}
	else if(N==2){
		if(a[0].y*a[1].y>=0){
			printf("");
		}}
	}
	else printf("%lf\n",a[i].y/2);
}
