/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;
//const double esp=1e-6
int cnt ,S,vis[25];
int nn[25][4];
stack<int> st;
void dfs(int now,int dep)
{
	if(dep==19&&now == S){
		printf("%d:  ",++cnt);
		printf("%d",st.top());st.pop();
		while(!st.empty()){
			printf(" %d",st.top());
			st.pop();
		}
		printf("\n");
		return ;
	}
	else if(dep>20)return ;
	for(int i=0;i<3;i++){
		int id =nn[now][i];
		if(vis[id])continue;
		vis[id]= 1;
		dfs(nn[now][i],dep+1);
		vis[id] = 0;
	}
}

int main()
{
	int a;
	for(int i=0;i<20;i++)
	  for(int j =0;j<3;j++){
		scanf("%d",&a);
		nn[i][j] = a;
	  }
	scanf("%d",&S);
	dfs(S,1);
}

