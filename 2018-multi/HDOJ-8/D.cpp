/*1.打表找规律:合法= 前缀和>=0 and sum all=0
 *2.小语法: printf("%d",a,"\n"[i==n]);  ..当i==n时输出\n
 *3.小技巧: putchar()
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=1e5;
int n,m,a[300][300],ans;
int w,h;
/*
void dfs(int u,int v) {
    if (u==n) {
        int cnt=0;
        rep(i,0,n){
            int c=0; bool val=1;
            rep(j,0,m) {
                c+=a[i][j];
                val&=c>=0;
            }
            val&=c==0;
            cnt+=val;
        }
        rep(i,0,m) {
            int c=0; bool val=1;
            rep(j,0,n) {
                c+=a[j][i];
                val&=c>=0;
            }
            val&=c==0;
            cnt+=val;
        }
        if (cnt>ans) {
            ans=cnt;
            printf("%d\n",ans);
            rep(i,0,n) rep(j,0,m) printf("%d%c",a[i][j]," \n"[j==m-1]);
        }
    } else {
        a[u][v]=1;
        dfs(u+(v+1)/m,(v+1)%m);
        a[u][v]=-1;
        dfs(u+(v+1)/m,(v+1)%m);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    dfs(0,0);
}
*/
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&w,&h);
		if(w%2==1&&h%2==1)
				for(int i=0;i<w;i++){
					for(int j=0;j<h;j++)
							printf("(");
					printf("\n");
				}
		else if(w%2==1){
			for(int i=0;i<w;i++){
				for(int j=0;j<h;j++)
					if(j%2==0)printf("(");
					else printf(")");
				printf("\n");
			}
		}
		else if(h%2==1){
			for(int i=0;i<w;i++){
				for(int j=0;j<h;j++)
					if(i%2==0)printf("(");
					else printf(")");
				printf("\n");
			}
		}
		else {
			int  p=min(w,h),q=max(w,h);
			if(p>=6){
				for(int i=0;i<w;i++){
					for(int j=0;j<h;j++){
						if(i==0)printf("(");
						else if(i==w-1)printf(")");
						else if(j==0)printf("(");
						else if(j==h-1)printf(")");
						else if((i+j)%2==1)printf("(");
						else if((i+j)%2==0)printf(")");
					}
					printf("\n");
				}
			}	
			else {
				if(p==2){
					for(int i=0;i<q;i++)
						for(int j=0;j<p;j++)
							if(j&1)a[i][j]=-1;
							else a[i][j]=1;
				}
				if(p==4){
					for(int i=0;i<q;i++)
						for(int j=0;j<p;j++)
							if(i<q/2)a[i][j]=j<p/2?1:-1;
							else if(i>=q/2)a[i][j]=j&1?-1:1;
				}
				if(w<h){
					for(int i=0;i<w;i++){
						for(int j=0;j<h;j++)
							if(a[j][i]==-1)putchar(')');
							else putchar('(');
						puts("");
					}
				}
				else{
					for(int i=0;i<w;i++){
						for(int j=0;j<h;j++)
							if(a[i][j]==-1)putchar(')');
							else putchar('(');
						puts("");
					}
				}
			}
		}
	}
}
