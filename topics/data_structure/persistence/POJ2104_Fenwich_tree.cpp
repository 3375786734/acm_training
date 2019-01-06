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
const int maxn = ;

int bit[maxn<<1];
int a[maxn];

int lowbit(int a){return a&(-a);}
void add(int a,int x)
{
	for(int i=0;i<=x;i+=lowbit(i))
		bit[i] += x;
}

int fd(int x)
{
	int ans = 0;
	for(int i=x;x>=0;i-=lowbit(i))
		ans+=bit[i];
	return ans;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&l,&r,&k);
		
	}
}
