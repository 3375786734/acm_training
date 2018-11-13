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
const int maxn=5000;
//const double esp=1e-6

int N,M,X;
int vis[maxn],a[maxn];
int main()
{
	while(~scanf("%d%d%d",&M,&N,&X))
	{
		MEM(vis,0);
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+N);
		for(int i=0;i<X;i++){
			for(int j=1;j<=N;j++)
				if(i%a[j]==0&&M>0){
					vis[j] = 1;
					M--;
				}
				else if(i%a[j]==0&&M<=0){
					vis[j] =0;
				}
		}
		for(int i=1;i<=N;i++)
			if(X%a[i]==0)vis[i] = 0;
		int ans =0;
		for(int i=1;i<=N;i++)
			if(vis[i] == 1)ans++;
		printf("%d %d\n",M,ans);
	}
}

