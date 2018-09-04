/*
 *注意:这里即使判断了层次满足要求,也不一定序列就对,因为考虑到上一层的顺序对应这下一层节点出现顺序
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=4e5+100;
int N;
struct Eg{
	int next,to;
};
Eg eg[maxn];
int s[maxn],tag[maxn],head[maxn],cur,vis[maxn];
void ag(int a,int b){
	eg[cur]=(Eg){head[a],b};
	head[a]=cur++;
}
void bfs(int now)
{
	MEM(tag,0);
	queue<int> q;
	q.push(now);
	tag[now]=1;vis[now]=1;
	while(!q.empty()){
		int fa=q.front();q.pop();
		for(int i=head[fa];i!=-1;i=eg[i].next){
			int id=eg[i].to;
			if(vis[id]==0){
				q.push(id);tag[id]=tag[fa]+1;
				vis[id]=1;
			}
		}
	}
}
int main()
{
	scanf("%d",&N);
	int a,b;
	MEM(head,-1);cur=0;
	rep(i,1,N-1){
		scanf("%d%d",&a,&b);
		ag(a,b);ag(b,a);
	}
	bfs(1);
	int pre=0,ans=1;
	rep(i,1,N){
		scanf("%d",&a);
		if(tag[a]<pre)ans=0;
		pre=tag[a];
	}
 	printf("%s\n",ans==0?"No":"Yes");
}
