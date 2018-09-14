#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e6+100;
char str[maxn];
int N,tmp[maxn];
int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&N,str);
		int len=strlen(str),ss=0,ff=1e8,laa=-1;
		for(int i=0;i<len;i++)
			if(str[i]=='1'){
				ff=i;break;
			}
		for(int i=0;i<len;i++)
			if(str[i]=='1')laa=i;
		rep(i,0,len-1){
			int ans=0,laaa=laa;
			printf("laa %d\n",laa);
			rep(j,0,len-1)tmp[j]=str[j]-'0';
			if(i<=ff)
			rep(j,i,laaa){
				if(tmp[j]==1){
					tmp[j+1]^=1;
					ans+=2;
					if(j==laaa&&tmp[j+1]==1)laaa++;
				}
				ans++;
			}
			else {
				for(int j=i-1;j>=ff;j--)tmp[j]^=1;
				rep(j,ff,laaa){
					if(tmp[j]==1){
						tmp[j+1]^=1;
						ans+=2;
						if(j=laaa&&tmp[j+1]==1)laaa++;
					}
					ans++;
				}
			}
			ss+=ans*(i+1);
			printf("%d\n",ans*(i+1));
		}
		printf("%d\n",ss);
	}
}
