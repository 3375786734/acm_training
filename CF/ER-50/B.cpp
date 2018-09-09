#include <bits/stdc++.h>
using namespace std;

int main()
{
	int Q;
	scanf("%d",&Q);
	long long  n,m,k,ans,res,r2;
	for(int i=1;i<=Q;i++){
		ans=0;
		scanf("%I64d%I64d%I64d",&n,&m,&k);
		ans=min(n,m);
		res=max(n,m)-ans;
		r2=k-res-ans;
		if(ans+res>k)printf("-1\n");
		else{
			if(r2%2==1&&res%2==0)printf("%I64d\n",k-2);
			else if(r2%2==1&&res%2==1)printf("%I64d\n",k-1);
			else if(r2%2==0&&res%2==1)printf("%I64d\n",k-1);
			else printf("%I64d\n",k);
		}
	}
}
