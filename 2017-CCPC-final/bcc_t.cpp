#include <bits/stdc++.h>
using namespace std;
const int maxn=;
struct Eg{
	int u,v;
	Eg(int u=0;int v=0) : u(u),v(v){}
};
int dfn[maxn],low[maxn];
void tarjan_bcc(int now, vector<Eg> & st){
	dfn[now]=low[now] = ++tim;

	for(int i=head[now];i!=-1;i=eg[i].next){
		int id=eg[i].to;
		if(dfn[i]==-1){
				parent[id] = now;
				st.push_back(Eg(now,id));
				tarjan(id ,st);
				//考虑他的孩子节点能向上翻到哪里
				low[now] = min(low[now],low[id]);

		}
		else if(parent[now]!=id){
			//由于id是其祖先节点,因此考虑祖先的深度即可
			//不考虑祖先的low是因为祖先的low可能不是由这个分支产生的
			low[now] =  min(low[now],dfn[id]);
			if(dfn[id] < dfn[now])
				st->push_back(Eg(now,id));
		}
	}
}
int main()
{
	vector<Eg> st;
	MEM(dfn,-1);
	for(int i=1;i<=N;i++){
		if(dfn[i]==-1)tarjan_bcc(now,st);
	}
}
