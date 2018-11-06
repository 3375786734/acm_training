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


int main()
{
	int a[6]={2,3,1,5,4};
	nth_element(a,a+3,a+5,[&](int a,int b){return a<b;});
	printf("%d\n",a[3]);
}

