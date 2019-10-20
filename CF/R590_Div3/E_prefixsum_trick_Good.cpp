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
const int maxn = 2e5+100;
//const double esp=1e-6
int a[maxn],pre[maxn],ans,res[maxn],cnt[maxn];
int N,M;
int Abs(int a){return a>0?a:-a;}
vector<int> vv[maxn];
int main()
{
	scanf("%d%d",&N,&M);
	for(int i = 0;i<M;i++)scanf("%d",&a[i]);
	for(int i=0;i<M-1;i++)ans+= Abs(a[i]-a[i+1]); 
	int mm,MM;
	for(int i=0;i<M-1;i++){
		mm = min(a[i],a[i+1]);MM = max(a[i],a[i+1]);
		if(a[i+1]!=a[i])
		  vv[a[i]].pb(a[i+1]),vv[a[i+1]].pb(a[i]);
		if(MM-mm <2)continue;
		cnt[mm+1]++;cnt[MM] --;
	}

	for(int i=0;i<N;i++)cnt[i+1] += cnt[i];
	for(int i=1;i<=N;i++){
		for(vector<int>::iterator it = vv[i].begin();it!= vv[i].end();it++){
			res[i] -= Abs(*it-i);
			res[i] += *it + ((*it)<i);
		}
	}
	for(int i = 1;i<=N;i++){
		printf("%d%c",ans-cnt[i] +res[i] ,i==N?'\n':' ');
	}
}

