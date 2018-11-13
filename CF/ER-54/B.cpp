/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const int maxn=;
//const double esp=1e-6

ll get_prim(ll N)
{
	for(ll i =3;i*i<=N;i++)
		if(N%i==0)return i;
	return N;
}
int main()
{
	ll N;
	scanf("%lld",&N);
	if(N%2==0){
		printf("%lld\n",N/2);
	}
	else{
		printf("%lld\n",(N-get_prim(N))/2+1);
	}
}

