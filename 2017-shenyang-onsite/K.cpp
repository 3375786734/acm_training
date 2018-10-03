#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
int a[maxn],N;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++)scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<N;i++)ans+=a[i+1]-a[i]-1;
		printf("%d\n",max(ans-(a[2]-a[1]),ans-(a[N]-a[N-1]))+1);
	}
}
