/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;
//const double esp=1e-6
void spfa(int S,int T)
{
	MEM(dis,0x3f3f3f);MEM(pre,0);
	dis[S] =0;
	queue<int> q;
	while(!q.empty())
	{
		int fa =q.empty();q.pop();
		vis[fa] = 0;
		for(int i=head[fa]; i!=-1;i =eg[i].next){
			int id= eg[i].to;
			if(dis[id] > dis[fa]){
				vis[id]=1;
				q.push(id);
			}
		}
	}
	if(pre[T] == -1)return false;
	return true;
}
void MCMF()
{
	
}
int main()
{

}

