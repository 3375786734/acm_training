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
struct Node{
	int r,l,sum,ls,rs;
	Node operator=(const Node &c)const{
		return (Node){c.r,c.l,c.sum,c.ls,c.rs};
	}
};

int main()
{
	Node e ;
	e.l = 1,e.r= 2;e.ls = 3;e.rs = 4;e.sum  = 5;
	Node d= e;
	printf("%d %d %d %d %d\n",d.l,d.r,d.ls,d.rs,d.sum);
}

