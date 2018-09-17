#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
typedef vector<int >::iterator VI;
typedef pair<ll,int> PP;

typedef set<PP>::iterator SI;
const int maxn=3e5;
/*
struct cmp{
	bool operator()(PP a,PP b){
		return a.first>b.first;
	}
};
*/
set<PP> sn;
ll a[maxn];
int zz[maxn],ss[maxn];
int main()
{
	int N,cnt=0,sz=0;
	scanf("%d",&N);
	rep(i,1,N)scanf("%lld",&a[i]);
	rep(i,1,N){
		if(a[i]>0)ss[sz++]=i;
		if(a[i]==0)zz[cnt++]=i;
		if(a[i]<0)sn.insert(PP(a[i],i));
	}
	for(SI si=sn.begin();si!=sn.end();si++){
		SI tmp=si;
		if(++si!=sn.end()){
			printf("1 %d %d\n",tmp->second,si->second);
			ss[sz++]=si->second;
//			ss.insert(PP((tmp->first)*(si->first),si->second));
		}
		else {
			if(cnt>0)printf("1 %d %d\n",tmp->second,zz[0]);
			else if(sz>0)printf("2 %d\n",tmp->second);
			break;
		}
	}
	for(int i=0;i<cnt-1;i++)
		printf("1 %d %d\n",zz[i],zz[cnt-1]);
	if(sz>0&&cnt-1>=0)printf("2 %d\n",zz[cnt-1]);
	for(int i=0;i<sz-1;i++)
		printf("1 %d %d\n",ss[i],ss[sz-1]);
}
