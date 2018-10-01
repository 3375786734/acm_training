#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5;
char str[maxn];
int ps[maxn];
int main()
{
	int N;
	scanf("%s",str);
	N=strlen(str);
	int flag=1;
	for(int i=1;i<=N;i++)
		if(i==1&&str[i-1]!='1')
				flag=0;
		else if(i==N&&str[i-1]!='0')
				flag=0;
		else if(i!=1&&i!=N&&str[i-1]!=str[N-i-1])flag=0;
	if(flag==0)printf("-1\n");
	else{
		int cnt=0;
		for(int i=1;i<N;i++)
			if(str[i]=='1')ps[++cnt]=i+1;
		for(int i=1;i<cnt;i++)
			printf("%d %d\n",i,i+1);
		//构造一个头 cnt+1
		printf("%d %d\n",cnt,cnt+1);
		int sz=cnt+2;
		for(int i=1;i<=cnt;i++){
			for(int j=0;j<ps[i]-ps[i-1]-1;j++)
				printf("%d %d\n",i,sz++);
		}
	}
}
