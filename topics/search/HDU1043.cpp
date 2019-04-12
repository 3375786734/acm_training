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
PP ss;
int fac[30];
struct Node{
	int g,x,y;
	char state[9];
	Node(int g,int x,int y,char state[]):g(g),x(x),y(y),state[](state[]){
	bool operator<(const Node &a)const{
		return dist(id)+g >dist(a)+a.g;
	}
};
bool inbound(PP now){
	int x = now.fi, y = now.se;
	return x>=0&&x<3&&y>=0&&y<3;
}
int encode(int *a){
}
Node decode(int x){
	
}
void a_star(PP ss)
{
	priority_queue<Node> q;
	q.push();
	while(!q.empty())
	{
		Node fa = q.top();q.pop();
		int ifa = encode(fa.state);
		if(vis[ifa])continue;
		for(int i=0;i<4;i++){
			PP tmp = PP(fa.fi+dx[i],fa.se+dy[i]);
			if(in_bound(tmp)&&vis[encode(tmp)])continue;
			q.push(encode(tmp));
		}
	}
}
void init()
{
	for(int i =0;i<strlen(str);i++)
		if(i=='x')str[i] == '9',ss.fi = i%3,ss.se = i/3;
	fac[0]=1;
	for(int i=1;i<=9;i++) fac[i]=fac[i-1]*i;
}
int main()
{
	while(~scanf("%s",str)){
		init();
		a_star();
		for(int i=0;i<anssz;i++)
			print("%c",ans[i]);
		printf("\n");
	}
}
