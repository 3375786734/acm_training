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
	int N;
	scanf("%d",&N);
	set<PP> ss;
	int a;
	rep(i,1,N){
		scanf("%d",&a);
		ss.insert(PP(a,i));
	}
	int sz= 0;
	PP sss ,last;
	for(auto si:ss){
		if(si.first<2)sz++,last = si;
		else {
			sss = si;
			break;
		}
	}
	if(sz==N&&N>2)printf("NO\n");
	else {
		printf("YES %d\n",N-sz+1);
		printf("%d\n",N-1);
		for(auto si:ss){
			if(si.first<=1&&si!=last)printf("%d %d\n",sss.second,si.second);
			if(si.first>1&&si!=sss){
				printf("%d %d\n",sss.second,si.second);
				sss = si;
			}
		}
		if(sz>=2)printf("%d %d\n",sss.second,last.second);
	}
}
