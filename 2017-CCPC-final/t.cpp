/*
 *常规思路,前i个票中,取j个集合可以覆盖的最大长度dp[i][j]
 *排序询问区间是为了一次遍历完所有的区间,常规技巧:排序之后再遍历
 *基本常识:每个区间只有三种关系 包含,交叠,相离
  我们先将包含去掉,问题就变得十分简洁了

 *类似题目:NWERC-2017-A
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=2010;
//typedef pair<int,int> PP;
struct PP{
    int x,y;
    PP(int x=0,int y=0):x(x),y(y){}
    //这里方便去掉包含关系
    bool operator<(const PP &a)const{
        return x==a.x?y<a.y:x<a.x;
    }
    bool operator==(const PP &a)const{
        return x<=a.x&&y>=a.y;
    }
};
int N,M,K;
int dp[maxn][maxn],pre[maxn];
int main()
{
    int  T,cas=1;
    //freopen("t.in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        set<PP> ss;
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        int xx,yy;
        rep(i,1,M){
            scanf("%d%d",&xx,&yy);
            ss.insert(PP(xx,yy));
        }
        int ans=0,i=1;
        for(PP si:ss){
            for(int j=1;j<=min(K,i);j++){
                int dd=0,tmp=0;
                if(pre[j-1]<si.x){
                    tmp=si.y;
                    dd=si.y-si.x+1;
                }
                else if(pre[j-1]<si.y){
                    tmp=si.y;
                    dd=si.y-pre[j-1];
                }
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+dd);
                if(dp[i-1][j-1]+dd>dp[i-1][j])pre[j]=tmp;
            }
            i++;
        }
        for(int i=1;i<=M;i++)
            ans=max(ans,dp[i][K]);
        /*
        for(PP si:ss)
            printf("%d %d\n",si.x,si.y);
        */
        printf("Case #%d: %d\n",cas++,ans);
    }
}
