#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=2000;
char str[maxn][maxn],tmp[maxn][maxn];
int vis[maxn][maxn];
int N,M;
bool isin(int y,int x)
{
	if(x+2<M&&y+2<N)return true;
	else return false;
}
int main()
{
	scanf("%d%d",&N,&M);
	rep(i,0,N-1)scanf("%s",str[i]);
	int ok=1;
	rep(i,0,N-1){
		rep(j,0,M-1){
			if(str[i][j]=='#'&&vis[i][j]!=1&&isin(i,j)){
				int cc=0;
				for(int m=0;m<3;m++)
					for(int n=0;n<3;n++){
						int xx=j+m,yy=i+n;
						//printf("%c\n",str[yy][xx]);
						if(str[yy][xx]=='#')cc++;
					}
				//printf("%d %d %d\n",i,j,cc);
				if(cc==8&&str[i+1][j+1]=='.'){
						for(int m=0;m<3;m++)
     		               for(int n=0;n<3;n++){
                      		  int xx=j+m,yy=i+n;
                    		  if(m==1&&n==1&&vis[yy][xx]==0)tmp[yy][xx]='.';
							  else tmp[yy][xx]='#';
							  vis[yy][xx]=2;
						}
				}
				else if(cc==9){
					for(int m=0;m<3;m++)
                        for(int n=0;n<3;n++){
                              int xx=j+m,yy=i+n;
                              if(m==1&&n==1&&vis[yy][xx]==0)tmp[yy][xx]='.';
                              else {
									tmp[yy][xx]='#';
							  	vis[yy][xx]=2;
							  }
                        }
				}
			}
			else if(str[i][j]=='.')tmp[i][j]='.';
		}
	}
	rep(i,0,N-1){
		rep(j,0,M-1){
			if(tmp[i][j]!=str[i][j])ok=0;
			//printf("%c",tmp[i][j]);
		}
	//	printf("\n");
	}
	if(ok)printf("YES\n");
	else printf("NO\n");
}
