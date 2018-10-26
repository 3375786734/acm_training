/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn=1e5+10;
//const double esp=1e-6
int N;
int b[maxn];
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	int a[10];
	while(T--)
	{
		rep(i,0,4)scanf("%d",&a[i]);
		scanf("%d",&N);
		rep(i,1,N)scanf("%d",&b[i]);
		sort(b+1,b+1+N);
		ll ans=0;
		for(int i=1;i<=N;i++)
			if(b[i]<=48)ans+=a[0];
			else if(b[i]<=48+8)ans+=a[1];
			else if(b[i]<=48+8+4)ans+=a[2];
			else if(b[i]<=48+8+4+2)ans+=a[3];
			else ans += a[4];
		printf("Case #%d: %lld\n",cas++,(ll)(ans*1e4));
	}	
}
