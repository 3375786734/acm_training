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

int main()
{
	int q,N;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&N);
		int maxx,minx,maxy,miny;
		maxx = 1e5,minx = -1e5,miny = -1e5,maxy = 1e5;
		int f[4];
		for(int i =0;i<N;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int j=0;j<4;j++)scanf("%d",&f[j]);
			if(f[0] == 0)minx = max(minx,x);
			if(f[1] == 0)maxy = min(maxy,y);
			if(f[2] == 0)maxx = min(maxx,x);
			if(f[3] == 0)miny = max(miny,y);
		}
		if(minx>maxx||miny>maxy)printf("0\n");
		else printf("1 %d %d\n",(maxx+minx)/2,(maxy+miny)/2);
	}
}

