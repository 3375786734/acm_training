/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;
//const double esp=1e-6;
const int mod=1e9+7;
int N,M,K;
ll qpow(ll a,ll n){
  	ll ans=1;
	while(n){
		if(n&1)ans = ans*a%mod;
		n >>= 1;a = a*a%mod;
	}
	return ans;
}
ll aa(ll n,ll m){
	if(m>n||m<0)return 0;
	ll ans=1,sum=1;
	for(int i=1;i<=m;i++){
		ans=ans*(n-i+1)%mod*qpow(i,mod-2)%mod;
		sum = (sum+ans) %mod;
		//printf("sum %lld\n",sum);
	}
	return sum;
}
int main()
{
	int  T,cas=1;
	scanf("%d",&T);
	//init();
	while(T--)
	{
		scanf("%d%d",&N,&K);
		ll ans=0;
		if(N>=K)ans=(qpow(2,N)-aa(N,K-1)+mod)%mod;
		printf("Case #%d: %lld\n",cas++,ans);
	}
}
