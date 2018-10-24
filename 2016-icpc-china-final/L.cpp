#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
//const int maxn=;
int b(int num,int bits){
	for(int i=0;i<bits;i++)
		num/=3;
	return num%3;
}
int main()
{
	int T,cas=1;
	//freopen("t.in","r",stdin);
	scanf("%d",&T);
	int bit[100];
	int aa[2][10]={{0,0,0,1,1,2},{1,2,3,2,3,3}};
	bit[0]=1;
	for(int i=1;i<=6;i++)bit[i]=bit[i-1]*3;
	while(T--)
	{
		int a[4],tmp[4];
		printf("Case #%d: ",cas++);
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
		int cnt=0,cc=0;
		for(int i=0;i<bit[6];i++){
			memset(tmp,0,sizeof(tmp));
			for(int j=0;j<6;j++){
				int op=b(i,j);
				if(op==2)tmp[aa[0][j]]+=3;
				else if(op==1)tmp[aa[0][j]]++,tmp[aa[1][j]]++;
				else tmp[aa[1][j]]+=3;
			}
			int ok=1;
			for(int j=0;j<4;j++){
				if(tmp[j]!=a[j])ok=0;
				if(j==0&&tmp[j]==9)cc++;
			}
			if(ok==1)cnt++;
		}
		if(cnt==0)printf("Wrong Scoreboard\n");
		else if(cnt==1)printf("Yes\n");
		else printf("No\n");
	}
}
