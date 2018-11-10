/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;
//const double esp=1e-6

bool ok(int a){return ~a;}
int main()
{
	for(int i=-2;i<2;i++)
		if(ok(i))printf("%d is 1\n",i);
		else printf("%d is 0\n",i);
	printf("%d\n",~1);
}

