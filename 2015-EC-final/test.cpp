//#include <bits/stdc++.h>
#include <cstdio>
#include <stack>
#include <map>
#include <cstring>
#include <vector>
#define MEM(a,num) memset(a,num,sizeof(a))
//#define pb push_back
using  namespace std;
const int maxn=1000;
int N,M;
int bcc_cnt,dfn[maxn],low[maxn],fa[maxn],tim;
vector<int> eg[maxn];
struct Eg{
	int u,v;
	Eg(int u=0,int v=0):u(u),v(v){}
	bool operator<(const Eg&a)const{
		return u==a.u?v<a.v:u<a.u;
	}
};
map<Eg,int> egmp;
stack<Eg> st;
void dfs_bcc(int now){
	dfn[now] = low[now] = ++tim;
	int child=0;
	for(int to :eg[now]){
		if(dfn[to]==-1){
			child++;fa[to] = now;
			st.push(Eg(now,to));
			dfs_bcc(to);
			low[now] = min(low[now], low[to]);
			//printf("here %d\n",now);
			if((dfn[now]==1&&child==1) || (dfn[now]>1&&low[to] >= dfn[now])){
				//note here there may be two bcc in the stack ,we need to pop one by one;
				int sz=0;
				printf("here\n");
				while(st.top().u!=now || st.top().v!=to){
					int u=st.top().u,v = st.top().v;
					egmp[Eg(u,v)] = bcc_cnt;
					printf("%d-- %d \n",u,v);st.pop();
				}
				egmp[Eg(now,to)] = bcc_cnt;st.pop();
				printf("%d-- %d \n",now,to);
				bcc_cnt++;
			}
		}
		else if(to!=fa[now]){
			low[now] = min(low[now],dfn[to]);
			if(dfn[to] < dfn[now])  //this is the last edge in the bcc;
				st.push(Eg(now,to));
		}
	}
}
void fd_bcc()
{
	MEM(dfn,-1);
	for(int i=1;i<=N;i++){
		if(dfn[i]==-1)
			dfs_bcc(i);
		int ok=0;
		while(!st.empty()){   //since there may left a bcc in the stack
			if(ok==0)bcc_cnt++,ok=1;
			int u=st.top().u,v=st.top().v;
			egmp[Eg(u,v)]=bcc_cnt;st.pop();
		}
	}
	printf("bcc = %d\n",bcc_cnt);
}
int main()
{
	freopen("t.in","r",stdin);
	scanf("%d%d",&N,&M);
	int a,b;
	for(int i=1;i<=M;i++){
		scanf("%d%d",&a,&b);
		eg[a].push_back(b);eg[b].push_back(a);
	}
	fd_bcc();
}
