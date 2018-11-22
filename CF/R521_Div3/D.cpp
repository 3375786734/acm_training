/*  -*- coding: utf-8 -*- */
/*
 *how to divide the element is the key obstacle of this problem.
 *since we can use the same character many times as well as different characters.
 *IDEA:convert this problem into a decision problem, that is judge if we can fill the matrix of certian size successfully.
 */
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
int N,K,ans[maxn];
struct Node{
	int vv,id;
	bool operator<(const Node &a)const{
		return vv>a.vv;
	}
};
Node nn[maxn];
bool check(int mid ,int sz)
{
	int cnt = 0;
	for(int i=0;i<sz;i++)
		cnt += nn[i].vv/mid;
	if(cnt>=K)return true;
	else return false;
}
int main()
{
	scanf("%d%d",&N,&K);
	int a,MM = 0,sz=0;
	map<int,int > mm;
	for(int i=1;i<=N;i++){
		scanf("%d",&a);
		aa[a] ++;
		if(MM<a)MM =a; 
	}
	for(int i=1;i<=MM;i++)
		if(aa[i])nn[sz++] = (Node){aa[i],i};
	sort(nn,nn+sz);
	int l = 1,r = 2e5,cc=1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(!check(mid,sz))r = mid-1;
		else l = mid+1;
	}
	int cnt = 0;
	for(int i = 0;i<sz;i++){
		int ccc = nn[i].vv/r;
		for(int j = 0;j<ccc;j++)
			ans[cnt++] = nn[i].id;
	}
	for(int i =0;i<K;i++)
		printf("%d%c",ans[i],i==K-1?'\n':' ');
}
