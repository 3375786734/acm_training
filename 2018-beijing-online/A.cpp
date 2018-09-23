/*
 *1.算法写错了,我能怎么办
 *2.加入pair时加错了先x,后y
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define f first
#define s second
using namespace std;
const int maxn=200;
typedef pair<int,int > PP;
//int G[maxn][manx][7];
char str[maxn][maxn];
int N,M;
int vis[2][maxn][maxn][7],f[maxn][maxn][7];
PP S,T;
struct Node{
	int x,y,state,g,h,pre;
	bool operator<(const Node &a)const{
		return h+g>a.h+a.g;
	}
};

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
bool check(int x,int y,int s){
	if(x>=0&&x<M&&y>=0&&y<N){
		if(str[y][x]=='#'&&s<=0)return false;
		else return true;
	}
	else return false;
}
int Abs(int a){
	if(a>0)return a;
	else return -a;
}
int slove()
{
	priority_queue<Node> qq;
	Node ss=(Node){S.f,S.s,0,0,Abs(S.f-T.f)+Abs(S.s-T.s),0};
	qq.push(ss);
	MEM(vis,0);
	vis[0][ss.y][ss.x][ss.state]=1;
	f[ss.y][ss.x][0]=ss.g+ss.h;
	int ans=1e9;
	MEM(f,0x3f3f3f);
	while(!qq.empty()){
		Node fa=qq.top();qq.pop();
		vis[0][fa.y][fa.x][fa.state]=0;
		vis[1][fa.y][fa.x][fa.state]=1;
		printf("now at x %d y %d state %d depth %d\n",fa.x,fa.y,fa.state,fa.g);
		if(fa.x==T.f&&fa.y==T.s){
			ans=min(ans,fa.g);
			//break;
		}
		for(int i=0;i<4;i++){
			int nx=fa.x+dx[i],ny=fa.y+dy[i];
			if(check(nx,ny,fa.state)){
				Node cn=(Node){nx,ny,fa.state,fa.g+1-fa.pre,Abs(T.f-nx)+Abs(T.s-ny),0};
				if(str[ny][nx]=='B'){
					if(cn.state<5)cn.state++;
				}
				if(str[ny][nx]=='#'){
					cn.g++;
					cn.state--;
				}
				if(str[ny][nx]=='P')cn.pre=1;
				if(vis[0][cn.y][cn.x][cn.state]==1){   //in open
					if(f[cn.y][cn.x][cn.state]>cn.h+cn.g){
						qq.push(cn);
						f[cn.y][cn.x][cn.state]=cn.h+cn.g;
						vis[1][cn.y][cn.x][cn.state]=0;
					}
				}
				 if(vis[1][cn.y][cn.x][cn.state]==1){//in close
					if(f[cn.y][cn.x][cn.state]>cn.h+cn.h){
						vis[1][cn.y][cn.x][cn.state]=0;
						vis[0][cn.y][cn.x][cn.state]=1;
						qq.push(cn);
					}
				}
				else {
					qq.push(cn);
					vis[0][cn.y][cn.x][cn.state]=1;
					vis[1][cn.y][cn.x][cn.state]=0;
				}
			}
		}
	}
	return ans==1e9?-1:ans;
	
}
int main()
{
	while(~scanf("%d%d",&N,&M)&&N!=0){
		S=PP(-1,-1);T=PP(-1,-1);
		for(int i=0;i<N;i++)
			scanf("%s",str[i]);
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(str[i][j]=='S')S=PP(j,i);
				else if(str[i][j]=='T')T=PP(j,i);
		if(S.f>=0&&T.f>=0)printf("%d\n",slove());
		else printf("-1\n");
	}
}
