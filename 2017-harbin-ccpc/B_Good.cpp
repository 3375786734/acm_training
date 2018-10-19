/*
 *思路见Note
 *首先求有多少个区间的第k大比x大
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
typedef long long ll;
int N,K;
ll M;
int a[maxn],tmp[maxn],sz;
bool check(int key,int k,ll m){
	ll ans=0;
	int cnt=0,pos=1;
	for(int i = 1; i<=N; i++){
		if(i>1&&a[i-1]>=key)cnt--;
		while(pos<=N && cnt<k){
			if(a[pos]>=key)cnt++;
			pos++;
		}
		if(cnt<k)break;
		ans+=(N-(pos-1)+1);
	}
	//printf("at %d %lld\n",key,ans);	
	if(ans<m)return true;
	else return false;
}
int bsrch(int l,int r)
{
	//printf("here %d %d\n",l,r);
	while(l<=r){
		int mid=(l+r)/2;
		if(check(tmp[mid],K,M))
			r=mid-1;
		else l=mid+1;
	}
	return tmp[r];
}
int main()
{
	int T;
	//freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		sz=0;
		scanf("%d%d%lld",&N,&K,&M);
		for(int i = 1; i <= N; i++){
			scanf("%d",&a[i]);
			tmp[sz++]=a[i];
		}
		sort(tmp,tmp+sz);
		sz=unique(tmp,tmp+sz)-tmp;
		printf("%d\n",bsrch(0,sz-1));
	}
}
