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

struct Node{
	int id,vv;
	bool operator<(const Node&a)const {
		return vv<a.vv;
	}
};
Node nn[maxn];
int main()
{
	int N;
	scanf("%d",&N);
	map<int,int> mm;
	int a;
	for(int i=1;i<=N;i++){
		scanf("%d",&a);
		mm[a]++;
	}
	
}

