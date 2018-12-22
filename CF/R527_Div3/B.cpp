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
const int maxn = 1000;
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int ans = 0;
	for(int i=0;i<n;i+=2)
		ans += a[i+1]-a[i];
	printf("%d\n",ans);
}

