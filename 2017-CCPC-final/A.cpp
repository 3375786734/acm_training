#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int d[maxn],N;
void init()
{
	d[1]=0;d[2]=1;
	for(int i=3;i<=20;i++)
		d[i]=(i-1)*(d[i-1]+d[i-2]);
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
//	init();
	while(T--){
		int ans=0;
		scanf("%d",&N);
		/*
		for(int i=1;i<=N;i++){
			printf("d[%d] %d\n",i,d[i]);
		}
		*/
		printf("Case #%d: %d\n",cas++,N-1);
	}
}
