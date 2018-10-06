/*
 *solution:BFS,假设所有点的值均一样,那么每一层就有O(N)个点,因此最终需要搜索O(N^2)个点会超时
 *剪枝的方法:1.同一层考虑值最大的2.出现过的节点不再考虑(这是因为环的存在使得同一节点被考虑多次)
 *还有一个剪枝:考虑环上如果一圈之后仍然最优,那么循环这个圈就可以了.
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn=4e5+100;
struct Node{
	int id,val,layer;
	bool operator < (const Node &a) const{
		return layer==a.layer?val > a.val:layer>a.layer;
	}
};
char str[maxn];
int N,a[maxn],laymax[maxn],vis[maxn];
void bfs()
{
	int maxv=0,pre=0,top=0;
	priority_queue<Node> q;
	for(int i = 0 ; i < N ; i++)
		maxv = max(maxv,a[i]);
	MEM(laymax,0);
	laymax[1] = maxv;
	for(int i = 0;i < N;i++)
		if(a[i] == maxv)q.push((Node){i,a[i],1});
	stack<int> ss;
	while(!q.empty())
	{
		Node fa = q.top();q.pop();
		if(fa.layer > pre){
			//memset(vis,0,sizeof(vis));
			while(!ss.empty()){
				vis[ss.top()]=0;ss.pop();
			}
			pre = fa.layer;top=0;
		}
		int iid = ((long long)fa.id*fa.id+1)%N;
		if(fa.layer >= N || vis[fa.id] || fa.val < laymax[fa.layer])continue;
		Node nxt = (Node){iid,a[iid],fa.layer+1};
		ss.push(fa.id);
		vis[fa.id]=1;
		if(nxt.val >= laymax[nxt.layer]){
			laymax[nxt.layer] = nxt.val;
			q.push(nxt);
		}
	}
}
int main()
{
	int T,cas = 1;	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&N,str);
		for(int i = 0;i < N;i++)a[i]=str[i]-'0';
		bfs();
		printf("Case #%d: ",cas++);
		for(int i = 1;i <= N;i++)
			printf("%d",laymax[i]);
		printf("\n");
	}
}
