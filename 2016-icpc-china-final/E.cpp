#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=3e5+100;
double k[maxn],vv[maxn];
int N;
double get_input()
{
	char c;
	double a,b;
	cin>>a>>c>>b;
	return b/a;
}
bool check(int mid){
	double ss=0;
	for(int i=1;i<=mid;i++)
		ss+=(k[i]+1);
	//printf("here %d\n",mid);
	for(int i=1;i<=mid;i++)
		vv[i]  = N*(k[i]+1)/ss;
	/*
	rep(i,1,mid)
		printf("%lf\n",vv[i]);
	*/
	for(int i=1;i<=mid;i++)
		if(vv[i]*(k[i]+1.0)<=N)return true;
	return false;
}
int solve()
{
	int l=2,r=N;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid))r=mid-1;
		else l = mid+1;
	}
	if(r<=1)return 0;
	else return r;
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d",&N);
		rep(i,1,N)
			k[i]=get_input();
		sort(k+1,k+1+N,[&](double a,double b){return a>b;});
		printf("%d\n",solve());
	}
}
