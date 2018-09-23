#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T,zhi,zhang,K,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&zhi,&zhang,&K);
		printf("Case #%d: ",cas++);
		if(zhi>zhang)printf("%d\n",K);
		else{
			printf("%d\n",min(K,11*zhi*K/(11*zhang+2*zhi)));
		}
	}
}
