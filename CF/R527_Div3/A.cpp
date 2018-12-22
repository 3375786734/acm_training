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


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int res = n/k;
		for(int i=0;i<k;i++)
			for(int j =0;j<n/k;j++)
				printf("%c",'a'+i);
		for(int i=0;i<n%k;i++)
			printf("%c",'a'+k-1);
		printf("\n");
	}
}
