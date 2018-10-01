/*
 *idea:将机械臂的长度分为全部都是一段的情形,然后判断和的奇偶性即可,但是注意到机械臂所要达到的范围在1e9量级
 *简单的使用每段长度均为1的机械臂会TLE.
  这题实际使用的是二进制表示方法,可以证明,只要长度为(1,2,2^2,...,2^k)那么就可以到任何(1,1,1,..,1)能到的地方
 *证明使用归纳法,如果坐标和为偶数,那么在原先的基础上加上一段1即可,非常巧妙.
 *题目还可以近一步引申,如果允许长度为0.5的出现,那么就可以到达任意奇偶的位置.
 *详细题解见Note
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5;
typedef long long ll;
int N,x[maxn],y[maxn];
char alph[5]={'R','L','U','D'};
int dx[5]={1,-1,0,0};
int dy[5]={0,0,1,-1};
int ans[50];
ll length[50];
ll aa(ll a){
	if(a<0)return -a;
	else return a;
}
bool check(ll cx,ll cy,ll ml){
//	printf("cx %d cy %d num %d\n",cx,cy,ml);
	if(aa(cx)+aa(cy)<=(1<<ml)-1)return true;
	else return false;
}
void dfs(int id,int xx,int yy)
{
	ll cx=xx,cy=yy;
	for(int j=id;j>=1;j--)
	{
//		printf("cx %d cy %d\n",cx,cy);
		for(int i=0;i<4;i++){
			ll nx=cx+length[j]*dx[i];
			ll ny=cy+length[j]*dy[i];
			if(check(nx,ny,j-1)){
				ans[j]=i^1;
				cx=nx;cy=ny;
				break;
			}
		}
	}
}

int main()
{
	freopen("t.in","r",stdin);
	scanf("%d",&N);
	int flag=0,ok=1;
	ll pre=0;
	for(int i=1;i<=N;i++){
		scanf("%d%d",&x[i],&y[i]);
		pre=max(pre,aa(x[i])+aa(y[i]));
		if(i==1)flag=(aa(x[i])+aa(y[i]))%2;
		else{
			if((aa(x[i])+aa(y[i]))%2!=flag)ok=0;
		}
	}

	if(ok==0)printf("-1\n");
	else{
		ll cx,cy;
		if(flag==1){
			printf("31\n");
			for(int i=1;i<=31;i++)printf("%lld%c",length[i]=(1<<(i-1)),i==31?'\n':' ');
			for(int j=1;j<=N;j++){
				cx=cy=0;
				dfs(31,x[j],y[j]);
				for(int i=1;i<=31;i++){
					printf("%c",alph[ans[i]]);
					cx+=length[i]*dx[ans[i]];
					cy+=length[i]*dy[ans[i]];
				}
				//printf("ps %lld %lld\n",cx,cy);
				printf("\n");
			}
		}
		else {
			printf("32\n");
			for(int i=1;i<=32;i++)printf("%lld%c",i==32?length[i]=1:length[i]=(1<<(i-1)),i==32?'\n':' ');
			for(int j=1;j<=N;j++){	
				cx=cy=0;
				dfs(32,x[j],y[j]);
				for(int i=1;i<=32;i++){
					printf("%c",alph[ans[i]]);
					cx+=(ll)length[i]*dx[ans[i]];
					cy+=(ll)length[i]*dy[ans[i]];
				}
				//printf("cx %lld cy %lld\n",cx,cy);
				printf("\n");
			}
		}
		/*
		printf("%d\n",pre);
		for(int i=1;i<=pre;i++)printf("%d%c",1,i==pre?'\n':' ');
		for(int i=1;i<=N;i++){
			printf("x %d y %d pre %d res %d\n",x[i],y[i],pre,(pre-aa(x[i])+aa(y[i]))/2);
			if(x[i]>0)for(int j=1;j<=x[i];j++)printf("R");
			if(x[i]<0)for(int j=1;j<=aa(x[i]);j++)printf("L");
			for(int j=1;j<=pre-aa(x[i]);j++)
				if(j<=((pre-aa(x[i])+aa(y[i]))/2))printf("%c",y[i]>0?'U':'D');
				else printf("%c",y[i]>0?'D':'U');
			printf("\n");
		}
		*/
	}
}
