#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long  N,K;
	scanf("%I64d%I64d",&N,&K);
	if(K==(K/N)*N)printf("%I64d\n",K/N);
	else printf("%I64d\n",K/N+1);
}
