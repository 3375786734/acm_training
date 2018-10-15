#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn=200;	
char str[maxn][maxn];
char vv[maxn*maxn],tmp[maxn*maxn],vis[maxn][maxn],str2[maxn][maxn];
int N;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void get_str(int &cx,int &cy,int op,int &sz,int cur){
	for(int i=0;i<cur;i++){
		cx+=dx[op%4];
		cy+=dy[op%4];
		str2[cy][cx]=vv[sz++];
	}
}
int main()
{
	while(~scanf("%d",&N)){
		MEM(str,0);MEM(str2,0);
		int sz=0;
		for(int i=0;i<N;i++)
			scanf("%s",str[i]);
		for(int i=1;i<=N;i++){
			if(i%2==0)
				for(int j=0;j<i;j++)vv[sz++]=str[j][i-1-j];
			else 
				for(int j=0;j<i;j++)vv[sz++]=str[i-1-j][j];
		}
		for(int i=N-1;i>=1;i--){
			//printf("sz %d\n",sz);
			if(i%2)
				for(int j=0;j<i;j++)vv[sz++]=str[N-1-j][N-i+j];
			else 
				for(int j=0;j<i;j++)vv[sz++]=str[N-i+j][N-1-j];
			//printf("sz %d\n",sz);
		}
		
		int cur=N,ccc=0,cx=0,cy=0;sz=0;
		for(int i=0;;i++){
			if(cur==N){
				for(int j=0;j<cur;j++)
					str2[cy][cx++]=vv[sz++];
				cx--;cur--;
			}
			else{
				ccc++;
				//printf("%d %d \n",cx,cy);
				get_str(cx,cy,i,sz,cur);
				if(ccc==2)cur--,ccc=0;
			}
			if(cur<=0)break;
		}
		for(int i=0;i<N;i++)
			printf("%s\n",str2[i]);
	}
}
