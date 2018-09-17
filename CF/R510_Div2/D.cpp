#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef vector<int >::iterator VI;
typedef set<int>::iterator SI;
ll N,T,a[maxn];
int lowbit(int x){
	return x&(-x);
}
int add(int a,int x){
	for(int i=x;i<=N;i+=lowbit(i))
		bit[i]+=x;
}
int get(int x){
	ll ans=1;
	for(int i=x;i>0;i-=lowbit(i))
		ans+=bit[i];
	return ans;
}

int main()
{
	scanf("%lld%lld",&N,&T);
	rep(i,1,N)scanf("%lld",&a[i]);
	rep(i,1,N)sum[i]=sum[i-1]+a[i];
	rep(i,1,N){
		
	}
}
