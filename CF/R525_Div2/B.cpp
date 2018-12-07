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
const int maxn = 1e5+100;
int a[maxn];
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	sort(a,a+N);
	N = unique(a,a+N)-a;
	ll ans = 0,flag =0;
	for(int i=0;i<K;i++){
			if(i<N){
				printf("%lld\n",a[i]-ans);
				ans = a[i];
			}
			else printf("0\n");
	}
}

