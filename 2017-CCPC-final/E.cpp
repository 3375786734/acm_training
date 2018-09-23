//按题目要求取整
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int a[maxn],N;
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		int sum=0;
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			sum+=a[i]+ceil(0.1*a[i]);
		}
		printf("Case #%d: %d\n",cas++,sum);
	}
}
