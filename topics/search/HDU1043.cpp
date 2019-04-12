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
const int maxn = 3e5;
char str[maxn],ans[maxn];
int dist(PP now){
	
}
struct Node{
	PP id;
	int g ;
	bool operator<(const Node &a)const{
		return dist(id)+g >dist(a)+a.g;
	}
}
bool inbound(PP now){
	int x = now.fi, y = now.se;
	return x>=0&&x<3&&y>=0&&y<3;
}
int encode(PP state)
{
	
}
PP decode(int now)
{
	
}
void a_star(PP ss)
{
	priority_queue<PP,vector<int>,cmp> q;
	q.push(ss)
	while(!q.empty())
	{
		PP fa = q.top();q.pop();
		for(int i=0;i<4;i++){
			PP tmp = PP(fa.fi+dx[i],fa.se+dy[i]);
			if(in_bound(tmp)&&vis[encode(tmp)])continue;
			q.push(encode(tmp));
		}
	}
}
int main()
{
	while(~scanf("%s",str)){
		PP ss ;
		for(int i=0;i<strlen(str);i++)
		  if(str[i]== 'x')ss = PP();
		a_star(ss);
		for(int i=0;i<anssz;i++)
		  print("%c",ans[i]);
		printf("\n");
	}
}

