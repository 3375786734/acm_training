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
const int maxn =6e5+10; 
int a[maxn],sz,N;
bool check(ll v)
{
	int cur = N,mm = 1;sz = 0;
	while(v>0&&cur>0){
		if(v>cur)a[sz++] = cur,v-=cur,cur--;
		else a[sz++] = v,v =0;
	}
	return (v==0);
}
int main()
{
	scanf("%d",&N);
	ll sum  = (ll)(N+1)*N/2;
	//in fact there are only two case i=0 or i=1  based on the strategy above
	for(int i=0;i<2*N;i++){
		if((i+sum)%2==0&&check((i+sum)/2)){
			printf("%d\n%d ",i,sz);
			for(int i=0;i<sz;i++)
				printf("%d%c",a[i],i==sz-1?'\n':' ');
			break;
		}
	}
}
