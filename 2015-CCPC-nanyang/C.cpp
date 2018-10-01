#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
const int mod=1e9+7;
typedef pair<int,int> PP;
typedef long long ll;
ll bit[maxn<<1][maxn],dp[maxn][maxn];
struct Node{
	int val,id;
	bool operator<(const Node &a)const{
		if(val==a.val)return id>a.id;
		else return val<a.val;
	}
};
int N,M,a[maxn];
int lowbit(int a){
	return a&(-a);
}
void add(int a,int x,int id){
	for(int i=a;i<=N;i+=lowbit(i))
		bit[id][i]=(bit[id][i]+x)%mod;
}
int fd(int x,int id){
	ll ans=0;
	for(int i=x;i>0;i-=lowbit(i))
		ans=(ans+bit[id][i])%mod;
	return ans;
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		set<Node> ss;
		scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			ss.insert((Node){a[i],i});
		}
		memset(dp,0,sizeof(dp));
		memset(bit,0,sizeof(bit));
		for(int i=1;i<=N;i++)
			dp[i][1]=1;
		for(set<Node>::iterator it=ss.begin();it!=ss.end();it++){
        	int cur=it->id;
//			printf("id %d\n",cur);
        	for(int j=2;j<=M;j++){
            	dp[cur][j]+=fd(cur-1,j-1);
				dp[cur][j]%=mod;
//				printf("dp %d\n",dp[cur][j]);
				add(cur,dp[cur][j-1],j-1);
       		}
    	}	
    	ll ans=0;
    	for(int i=1;i<=N;i++)
        	ans=(ans+dp[i][M])%mod;
    	printf("Case #%d: %lld\n",cas++,ans);
	}
	/*
	for(set<PP>::iterator it=ss.begin();it!=ss.end();it++){
		int cur=it->second;
		for(int j=1;j<=M;j++){
			dp[][]+=fd(cur,j-1);
			add();
		}
	}
	ll ans=0;
	for(int i=1;i<=N;i++)
		ans=(ans+dp[i][M])%mod;
	printf("%lld\n",ans);
	*/
}
