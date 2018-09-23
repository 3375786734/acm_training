#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	int l=min(N,M),r=max(N,M);
	if(l>=3){
		if(N%2==0&&M%2==0)printf("%I64d\n",1ll*M*N);
		else if(N%2==0||M%2==0)printf("%I64d\n",1ll*M*N-2);
		else printf("%I64d\n",1ll*N*M-1);
	}
	else{
		ll ans=0;
		if(l==1){
			if(r%6<=3)ans=r/6*6;
			else ans=r/6*6+r%6-3;
			printf("%I64d\n",ans);
		}
		if(l==2){
			if(r%4<=2)ans=r/4*4*2;
			else ans=(r/4*4+(r%4-2))*2ll;
			printf("%I64d\n",ans);
		}
	}
}
