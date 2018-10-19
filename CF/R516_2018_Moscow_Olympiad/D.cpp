#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace  std;
const int maxn=2018;
char str[maxn][maxn];
int vis[maxn][maxn];
int N,M;
struct Node{
	int x,y,l,r;
};
bool  isin(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N&&str[y][x]=='.';
}
void extend(Node S,queue<Node> &q){
	int x=S.x,y=S.y;
	for(int i=y;i>=0;i--)
		if(str[i][x]=='*'||vis[i][x])break;
		else {
			q.push((Node){x,i,S.l,S.r});
			vis[i][x]=1;
		}
	for(int i=y+1;i<=N;i++)
		if(str[i][x]=='*'||vis[i][x])break;
		else{
			q.push((Node){x,i,S.l,S.r});
			vis[i][x]=1;
		}
}
int bfs(Node S){
	MEM(vis,0);
	queue<Node> q;
	q.push(S);extend(S,q);vis[S.y][S.x]=1;
	while(!q.empty())
	{
		Node fa=q.front();q.pop();
		//printf("%d %d\n",fa.x,fa.y);
		int x=fa.x,y=fa.y;
		if(fa.l>0&&isin(x-1,y))extend((Node){x-1,y,fa.l-1,fa.r},q);
		if(fa.r>0&&isin(x+1,y))extend((Node){x+1,y,fa.l,fa.r-1},q);
	}
	int ans=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			ans+=vis[i][j];
			//printf("%d",vis[i][j]);
		}
		//printf("\n");
	}
	return ans;
}
int main()
{
	int x,y,l,r;
	scanf("%d%d%d%d%d%d",&N,&M,&y,&x,&l,&r);
	x--;y--;
	rep(i,0,N-1)scanf("%s",str[i]);
	printf("%d\n",bfs((Node){x,y,l,r}));
}
