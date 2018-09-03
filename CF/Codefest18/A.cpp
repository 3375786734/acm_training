#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	int ans=floor(log2(1.0*N)),res=N-(1<<ans-1);
	printf("%d\n",res==0?ans:ans+1);
}
