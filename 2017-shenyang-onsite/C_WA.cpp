#include <bits/stdc++.h>
using namespace std;
const int maxn=200;
int N;
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
bool cmp(node p1,node p2)//极角排序
{
    double z=cross(a[0],p1,p2);
    if(z>0||(z==0&&dis(a[0],p1)<dis(a[0],p2)))
        return 1;
    return 0;
}
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
double SS(int a,int b,int c)
{
	double x=p[a].x-p[b].x,y=p[a].y-p[b].y;
	double xx=p[a].x-p[c].x,yy=p[a].y-p[c].y;
	return fabs(x*yy-y*xx);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d%d",&a[i].x,&a[i].y);
		Graham();
		double ans=0;
		for(int i=1;i<top;i++){
			ans+=SS(0,i,i+1);
			//printf("%d %d\n",p[i].x,p[i].y);
		}
		ans/=2;
		printf("%.1f\n",ans);
	}
}
