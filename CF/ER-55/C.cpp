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
vector<int> vv[maxn];
set<int> id;
ll ans[maxn];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	int a,b;
	rep(i,1,N){
		scanf("%d%d",&a,&b);
		vv[a].pb(b);id.insert(a);
	}
	for(int iid :id){
		//printf("iid %d\n",iid);
		sort(vv[iid].begin(),vv[iid].end(),[&](int a,int b){return a>b;});
		//for(int vi :vv[iid])
		//	printf("sac %d\n",vi);
	}
	int MAX = 0;
	for(int iid:id){
		int cnt = 1;
		ll sum = 0;
		for(int vi :vv[iid]){
			sum += vi;
			if(sum>0)ans[cnt] += sum;
			MAX =max(MAX,cnt);
			cnt++;
		}
	}
	ll aa = 0;
	for(int i=1;i<=MAX;i++)
		aa = max(aa,ans[i]);
	printf("%lld\n",aa);
}
