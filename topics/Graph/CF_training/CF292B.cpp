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
const int maxn  = 1e5+100;
int sz[maxn],N,M;
int main()
{
	scanf("%d%d",&N,&M);
	MEM(sz,0);
	vector<int> cnt;cnt.resize(N);
	int a,b;
	for(int i=1;i<=M;i++){
		scanf("%d%d",&a,&b);a--,b--;
		cnt[a]++,cnt[b]++;
	}
	sort(cnt.begin(),cnt.end());
	for(int i=0;i<N;i++)sz[cnt[i]]++;
	if(sz[2]==N)printf("ring topology\n");
	else if(sz[1]==2&&sz[2]==N-2)printf("bus topology\n");
	else if(sz[1]==N-1&&sz[N-1]==1)printf("star topology\n");
	else printf("unknown topology\n");
}

