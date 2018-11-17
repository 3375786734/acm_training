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


int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		printf("%lld\n",(ll)(a-b)*(k/2)+(ll)a*(k%2));
	}
}

