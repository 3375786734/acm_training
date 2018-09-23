#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int maxn=1000;
int a[maxn],vis[maxn],tmp[maxn];
int ans[maxn];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		vis[a[i]]++;
	}
	int sz=0,cnt=0,ps=-1;
	rep(i,1,N){
		if(vis[a[i]]==1)sz++;
		if(vis[a[i]]>2)ps=i;
	}
	if(sz%2==1&&ps==-1)printf("NO\n");
	else if(sz%2==1){
		int flag=0;
		printf("YES\n");
		rep(i,1,N){
            if(vis[a[i]]==1&&cnt<=sz/2)ans[i]=0,cnt++;
			else if(vis[a[i]]==1&&cnt>sz/2)ans[i]=1,cnt++;
            else if(vis[a[i]]==2&&tmp[a[i]]==0)ans[i]=1,tmp[a[i]]=1;
			else if(vis[a[i]]==2&&tmp[a[i]]==1)ans[i]=0;
			else if(flag==0&&vis[a[i]]>2)ans[i]=1,flag=1;
		}
        rep(i,1,N)printf("%c",ans[i]==0?'A':'B');
        printf("\n");

	}
	else {
		rep(i,1,N){
			if(vis[a[i]]==1&&cnt<sz/2)ans[i]=1,cnt++;
			else if(vis[a[i]]==1&&cnt>sz/2)ans[i]=0,cnt++;
			else if(vis[a[i]]==2&&tmp[a[i]]==0)ans[i]=1,tmp[a[i]]=1;
			else if(vis[a[i]]==2&&tmp[a[i]]==1)ans[i]=0;
		}
		printf("YES\n");
		rep(i,1,N)printf("%c",ans[i]==0?'A':'B');
		printf("\n");
	}
}
