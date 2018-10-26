/*
 *注意一个细节问题,这里最好脚标从0开始,方便开空间
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
//const int maxn=1e5+10;//注意这个长度不够,因为要考虑1<<17而不是n ,因此2e5足够
const int maxn=2e5;
const double pi = acos(-1.0);
int a[maxn],b[maxn],ans[maxn];
//vector<int> aa[maxn],bb[maxn];
char aaa[maxn] ,bbb[maxn];
struct Cn{
	double x,y;
	Cn(double x=0,double y = 0):x(x),y(y){}
	Cn operator + (Cn b){return Cn(x+b.x,y+b.y);}
	Cn operator - (Cn b){return Cn(x-b.x,y-b.y);}
	Cn operator * (Cn b){return Cn(x*b.x-y*b.y,y*b.x+x*b.y);}
};
Cn aa[maxn],bb[maxn],cc[maxn];
void fft(Cn *a,int len,int op){
	if(len==1)return ;
	Cn A0[(len>>1)+1],A1[(len>>1)+1];
	int sz=0;
	for(int i=0;i<len;i+=2)
		A0[sz] =a[i],A1[sz++] = a[i+1];
	fft(A0,sz,op);fft(A1,sz,op);
	Cn ee=Cn(cos(2*pi/len),op*sin(2*pi/len)),w = Cn(1,0);
	for(int i=0;i<len;i++,w=w*ee)
		a[i] = A0[i%sz] + w*A1[i%sz];
	//for(int i=0;i<sz;i++,w=w*ee) a[i]=A0[i]+w*A1[i] , a[i+sz]=A0[i]-w*A1[i];
}
int main()
{
	//int T;
	//freopen("tt.in","r",stdin);
	//scanf("%d",&T);
	//while(T--)
	//{
	while(~scanf("%s%s",aaa,bbb)){
		MEM(aa,0);MEM(bb,0);MEM(cc,0);
		//scanf("%d%d",&N,&M);
		int N = strlen(aaa) , M = strlen(bbb);
		int len =1 , sz=0;
		for(int i=0;i<N;i++){
			//scanf("%d",&a[i]);
			aa[i] = Cn(aaa[i]-'0',0);
		}
		for(int i=0;i<M;i++){
			//scanf("%d",&b[i]);
			bb[i] = Cn(bbb[i]-'0',0);
		}
		while(len<=M+N)len<<=1;
		fft(aa,len,1);fft(bb,len,1);
		for(int i=0;i<len;i++)cc[i] = aa[i]*bb[i];
		fft(cc,len,-1);
		//这里因为次数为N+M-2因此有N+M-1项
		int ok = 1;
		for(int i=0;i<len;i++){
			ans[i] = (int)(cc[i].x/len+0.5);
			//printf("aa %d\n",ans[i]);
		}
		for(int i=len-1;i>0;i--){
			ans[i-1]+=ans[i]/10;
			ans[i] = ans[i]%10;
		}
		for(int i=0;i<M+N-1;i++){
			//printf("ans %d\n",ans[i]);
			if(ok==1&&ans[i]==0&&i!=N+M-2)continue;
			ok=0;
			printf("%d",ans[i]);
		}
		printf("\n");
	//}
	}	
}
