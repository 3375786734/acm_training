#include <bits/stdc++.h>
#define  MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=1500;
int vis[maxn],num[maxn];
int n,m,k;
int main()
{
	int T,cas=0;
//	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		char str[100];
		MEM(num,0);
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n){
			scanf("%s",str);
			for(int j=0;j<m;j++)
				if(str[j]=='A')num[i]+=(1<<j);
		}
		int ans=0;
		for(int i=0;i<(1<<m);i++)
		{
			ll s1=0,s2=0,cnt=0;
			MEM(vis,0);cnt=0;
			rep(j,1,n){
				int id=(num[j]&i);
				vis[id]++;
//				printf("now vis%d++\n",id);
			}
			for(int j=0;j<(1<<m);j++){
				s1+=vis[j];
				s2+=(ll)vis[j]*vis[j];
			}
			cnt=(s1*s1-s2)/2;
//			printf("now %d %lld \n",i,cnt);
			if(cnt>=k)ans++;
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
}
