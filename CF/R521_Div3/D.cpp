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
const int maxn=2e5+100;
//const double esp=1e-6
int a[maxn],aa[maxn];
struct Node{
	int vv,id;
	bool operator<(const Node &a)const{
		return vv>a.vv;
	}
};
Node nn[maxn];
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int a,MM = 0,sz=0;
	map<int,int > mm;
	for(int i=1;i<=N;i++){
		scanf("%d",&a);
		aa[a] ++;
		if(MM<a)MM =a; 
	}
	for(int i=1;i<=MM;i++){
		if(aa[i]>0)nn[sz++] = (Node){aa[i],i};
	}
	sort(nn,nn+sz);
	for()
}
