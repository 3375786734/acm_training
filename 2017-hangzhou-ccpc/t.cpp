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

void func(vector<int> &a)
{
	a[0] =2;
}
int main()
{
	vector<int> a;
	a.resize(5);
	a[0]=1;
	func(a);
	printf("%d\n",a[0]);
	a.resize(4);
	printf("%d\n",a[0]);
	printf("%d\n",a.size());
}

