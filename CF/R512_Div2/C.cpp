#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=2e6;
int  tmp[maxn],ttt[maxn];
int main()
{
	int N;
	scanf("%d",&N);
	rep(i,1,N)tmp[i]=i;
	int sz=N;
	for(int i=0;(1<<i)<=N;i++){
		if(sz>=4){
			int tz=0,ss=(1<<i);
			for(int j=2;j<=sz;j+=2)
				ttt[++tz]=tmp[j];
			for(int j=0;j<sz-tz;j++)printf("%d ",ss);
			sz=tz;
			//printf("here %d\n",sz);
			for(int j=1;j<=sz;j++){
				tmp[j]=ttt[j];
				//printf("tmp %d\n",tmp[j]);
			}
		}
		else if(sz==3){
			printf("%d %d %d\n",tmp[1],tmp[1],tmp[3]);
			break;
		}
		else if(sz==2){
			printf("%d %d\n",tmp[1],tmp[2]);
			break;
		}
		else if(sz==1){
			printf("%d\n",tmp[1]);
			break;
		}
	}
}
