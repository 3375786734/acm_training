#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int N,a[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		a[1]=1;a[2]=N%2==0?N/2+1:N/2+2;
		for(int i=3;i<=N;i++)a[i]=a[i-2]+1;
		for(int i=1;i<=N;i++)
			printf("%d%c",a[i],i==N?'\n':' ');
	}
}
