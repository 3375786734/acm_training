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
const int maxn = ;
char str[maxn],ans[maxn];
struct Node{
	int state[3][3];
};
bool inbound(int x,int y){
	return x>=0&&x<3&&y>=0&&y<3;
}
int encode(char *str)
{
	
}
char * decode(int code)
{

}
void a_star()
{
	priority_queue<int> q;
	while(!q.empty())
	{
		int fa = q.top();q.pop();
		for(int i=0;i<4;i++){
			
		}
	}
}
int main()
{
	while(~scanf("%s",str)){
		a_star();
		for(int i=0;i<anssz;i++)
		  print("%c",ans[i]);
		printf("\n");
	}
}

