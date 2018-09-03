#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e6+100;
int main()
{
	char s1[maxn],s2[maxn];
	int N;
	scanf("%d",&N);scanf("%s",s1);scanf("%s",s2);
	int ans=0,pre=0;
	for(int i=0;i<N-1;i++)
		if(s1[i]!=s2[i]&&s1[i]==s2[i+1]&&s2[i]==s1[i+1]){
			ans++;i++;pre=i;
		}
		else if(s1[i]!=s2[i])ans++;
	if(pre!=N&&s1[N-1]!=s2[N-1])ans++;
	printf("%d\n",ans);
}
