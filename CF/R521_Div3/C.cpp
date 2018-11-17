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
const int maxn=2e5+20;
//const double esp=1e-6
ll a[maxn],ans[maxn];
int main()
{
	int N,sz=0;
	map<ll,int> ss;
	ll sum =0; 
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld",&a[i]);
		ss[a[i]]++;
		sum+=a[i];
	}
	for(int i=1;i<=N;i++){
		ss[a[i]]--;
		if((sum-a[i])%2==0&&ss[(sum-a[i])/2]>0){
			ans[sz++] = i;
		}
		ss[a[i]]++;
	}
	printf("%d\n",sz);
	for(int i=0;i<sz;i++)
		printf("%lld%c",ans[i],i==sz-1?'\n':' ');

}
