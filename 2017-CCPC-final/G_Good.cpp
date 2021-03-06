/*
 *常规思路,前i个票中,取j个集合可以覆盖的最大长度dp[i][j]
 *排序询问区间是为了一次遍历完所有的区间,常规技巧:排序之后再遍历
 *基本常识:每个区间只有三种关系 包含,交叠,相离
  我们先将包含去掉,问题就变得十分简洁了

 *类似题目:NWERC-2015-A
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=2181;
//typedef pair<int,int> PP;
struct PP{
	int x,y;
	PP(int x=0,int y=0):x(x),y(y){}
	//这里方便去掉包含关系
	bool operator<(const PP &a)const{
		return x==a.x?y>a.y:x<a.x;
	}
	bool operator==(const PP &a)const{
		return x<=a.x&&y>=a.y;
	}
};
int N,M,K;
int dp[maxn][maxn],pre[maxn];
PP ss[maxn];
int main()
{
	int  T,cas=1;
	//freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&M,&K);
		memset(dp,0,sizeof(dp));
		int xx,yy,sz=0,ans=0;

		rep(i,1,M){
			scanf("%d%d",&xx,&yy);
			ss[++sz] = PP(xx,yy);
		}
		sort(ss+1,ss+sz+1);
		sz=unique(ss+1,ss+1+sz)-ss-1;

		for(int k=1;k<=K;k++){
			int pos=0,maxx=0;
			for(int j=1;j<=sz;j++){
				while(pos<j&&ss[pos].y<ss[j].x){
					maxx=max(maxx,dp[pos][k-1]);
					pos++;
				}
				//我们需要证明,如果有多个交叠的,一定是第一个交叠的最优
				//因为不存在包含关系,因此如果有多个交叠,那么这些交叠的一定交叠(因为是按l排序的).
				//因为除第一个交叠的生成了后面交叠的最优值,那么后面的值不会比第一个优
				if(pos<j)dp[j][k]=dp[pos][k-1]+ss[j].y-ss[pos].y;
				dp[j][k]=max(dp[j][k],maxx+ss[j].y-ss[j].x+1);
			}
		}
		/*
		for(int i=1;i<=sz;i++)
			for(int j=1;j<=K;j++)
				printf("dp[%d][%d]:%d %d\n",i,j,dp[i][j]);
		for(PP si:ss)
			printf("%d %d\n",si.x,si.y);
		*/
		for(int i=1;i<=M;i++)
			ans=max(dp[i][K],ans);
		printf("Case #%d: %d\n",cas++,ans);
	}
}
