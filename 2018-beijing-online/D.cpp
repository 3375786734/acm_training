#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
ll a[maxn],b[maxn];
int N,C;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&C);
		for(int i=1;i<=N;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=N;i++)
			scanf("%lld",&b[i]);
		ll cur=C,sum=0,mm=1e9;
		for(int i=1;i<=N;i++){
			cur=cur+a[i]-b[i];
			mm=min(cur,mm);
		}
		if(cur<0)printf("-1\n");
		else{
			if(mm>=0)printf("1\n");
			else{
				int ans=2;
				for(int i=2;i<=N;i++){
					ll dd=(a[i-1]-b[i-1]);
					mm-=dd;
					mm=min(mm,cur);
					if(mm>=0){
						ans=i;
						break;
					}
				}
				printf("%d\n",ans);
			}
		}
	}
}
