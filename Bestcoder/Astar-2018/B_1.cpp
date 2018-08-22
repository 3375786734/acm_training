#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn=1e5+100;
const int LOGN=20;
int sum[28][maxn];
int st[maxn][LOGN],n;
char str[maxn];
char RMQ(int l,int r)
{
	if(l>r)swap(l,r);
	int k=0;//=(int)log(r-l+1.0)/log(2.0);
	while(r-l+1>=(1<<(k+1)))k++;
	return min(str[st[l][k]],str[st[r+1-(1<<k)][k]]);
}
void init()
{
	for(int i=0;i<n;i++)st[i][0]=i;
	for(int j=1;(1<<j)<n;j++)
		for(int i=0;i+(1<<j)-1<n;i++)
				if(str[st[i][j-1]]<str[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
				else st[i][j]=st[i+(1<<(j-1))][j-1];
}
int main()
{
	int T,cas=0;
//	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d:\n",++cas);
		int q;
		MEM(sum,0);MEM(st,0);
		scanf("%d%d",&n,&q);
		scanf("%s",str);
		int len=strlen(str);
		for(int i=1;i<=len;i++){
			int id=str[i-1]-'A';
			sum[id][i]=sum[id][i-1]+1;
			for(int j=0;j<26;j++)
				if(j!=id)sum[j][i]=sum[j][i-1];
		}
		init();
		int l,r;
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&l,&r);
			int id=RMQ(l-1,r-1)-'A';
//			printf("id is %d\n",id);
			printf("%d\n",sum[id][r]-sum[id][l-1]);
		}
	}
}
