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
//const double esp=1e-6
const int maxn = 20000;
int N;
int vis[maxn];
int fa[maxn];
string str[maxn];
struct Node{
	string ss;
	int id ;
	bool operator<(const Node &a)const{
		return ss.length()<a.ss.length();
	}
};
Node nn[maxn];
bool  dfs(int now,int pre,int dep)
{
	fa[now] = pre;
	if(dep==N/2-1){
		int tmp = now;
		vis[nn[now].id] = 1;
		while(tmp!=0&&tmp!=1){
			vis[nn[tmp].id] = 1;
			tmp = fa[tmp];
		}
		return true;
	}
	if(now%2==0){
		int ok = 1;
		for(int i = 0;i<nn[now].ss.length();i++)
			if(nn[now].ss[i]!=nn[now+2].ss[i]){
				ok =0;
				break;
			}
		if(ok== 1&&dfs(now+2,now,dep+1))return true;
		ok = 1;
		for(int i =0;i<nn[now].ss.length();i++)
			if(nn[now].ss[i]!=nn[now+3].ss[i]){
				ok = 0;
				break;
			}
		else if(ok==1)return dfs(now+3,now,dep+1);
	}
	else {
		int ok = 1;
		for(int i = 0;i<nn[now].ss.length();i++)
			if(nn[now].ss[i]!=nn[now+1].ss[i]){
				ok =0;
				break;
			}
		if(ok&&dfs(now+1,now,dep+1))return true;
		ok =1;
		for(int i = 0;i<nn[now].ss.length();i++)
			if(nn[now].ss[i]!=nn[now+2].ss[i]){
				ok =0;
				break;
			}
		else if(ok) return dfs(now+2,now,dep+1);
	}
	return false;
}
int main()
{
	scanf("%d",&N);
	N= 2*(N-1);
	for(int i=0;i<N;i++){
		cin>>str[i];
		nn[i] = (Node){str[i],i};
	}
	sort(nn,nn+N);
	MEM(vis,0);
	if(!dfs(0,0,0)){
		MEM(vis,0);
		dfs(1,1,0);
	}
	for(int i=0;i<N;i++)
		if(vis[i]==0)printf("S");
		else printf("P");
	printf("\n");
}

