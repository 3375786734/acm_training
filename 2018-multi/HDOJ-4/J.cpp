/*1.how to rotate the matrix
 *2.DFS  idea: we check the state row by row,search by a seq ,so that we can reduce the num we need to search
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=20;
struct Node{
	int str[4][4];
	void rot(){
		int tmp[4][4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
					tmp[i][j]=str[i][j];
		for(int i=0;i<4;i++)
				for(int j=0;j<4;j++){
					str[i][j]=tmp[j][3-i];
				}
	}
	void rev(){
		int tmp[4][4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
					tmp[i][j]=str[i][j];
		for(int i=0;i<4;i++)
				for(int j=0;j<4;j++){
					str[i][j]=tmp[3-j][i];
				}
	}
	void pn(){
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
					printf("%d",str[i][j]);
			printf("\n");
		}
	}
	int x,y;
};
Node  nn[4][4];
int rv[18][18],cv[18][18],ans;
int check(int fx,int fy)
{
	int px=fx*4,py=fy*4,flag=1;
	for(int i=py;i<py+4;i++)
		for(int j=px;j<px+4;j++){
			int id=nn[fy][fx].str[i-py][j-px];
			//printf("now at % %d"  )
			rv[i][id]--;cv[j][id]--;
		}
	nn[fy][fx].rev();
	for(int i=py;i<py+4;i++)
		for(int j=px;j<px+4;j++){
			int id=nn[fy][fx].str[i-py][j-px];
			if(++rv[i][id]>1||++cv[j][id]>1){
					flag=0;
//					printf("id  %d %d\n",rv[i][id],cv[j][id]);
			}
		}
	return flag;
}
void add(int fx,int fy,int v)
{
	int px=fx*4,py=fy*4;
	for(int i=py;i<py+4;i++)
		for(int j=px;j<px+4;j++){
			int id=nn[fy][fx].str[i-py][j-px];
			rv[i][id]+=v;
			cv[j][id]+=v;
		}
}
//we judge the num row by row!!
void slove(int dep,int fx,int fy)
{
	if(fx == 0 && fy == 4){
		ans=min(ans,dep);
		return;
	}
//	printf("now at %d %d\n",fx,fy);
	//opt cut
	if(ans<dep)return;
	add(fx,fy,1);
	for(int r = 1 ; r <= 4 ; r++){
		if(check(fx,fy))//next block
		{
			slove(r%4+dep,fx==3?0:fx+1,fx==3?fy+1:fy);
		}
	}
	//if not allow
	add(fx,fy,-1);
}
int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		MEM(rv,0);MEM(cv,0);
		ans=16*4;
		char tmp[18][18];
		for(int i=0;i<16;i++)scanf("%s",tmp[i]);
		/*
		for(int i=0;i<16;i++){
             for(int j=0;j<16;j++)
                 printf("%c",tmp[i][j]);
             printf("\n");
         }*/
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					for(int w=0;w<4;w++)
						if(tmp[i*4+k][j*4+w]>='A')nn[i][j].str[k][w]=tmp[i*4+k][j*4+w]-'A'+10;
						else nn[i][j].str[k][w]=tmp[i*4+k][j*4+w]-'0';
		/*
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				nn[i][j].pn();
		*/
		slove(0,0,0);
		printf("%d\n",ans);
	}
}
