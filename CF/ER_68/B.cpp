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
const int maxn = 1e6;
int r[maxn],c[maxn];
char str[maxn];
int main()
{
	int q,M,N;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&N,&M);
		int ans = 0;
		MEM(r,0);MEM(c,0);
		for(int i=0;i<N;i++){
			scanf("%s",str);
			for(int j= 0;j<M;j++){
				if(str[j] == '*')r[i]++,c[j]++;	
			}
		}
		printf("%d\n",N+M-1-ans);
	}
}

