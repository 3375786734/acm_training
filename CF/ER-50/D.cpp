#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+100;
int a[maxn],b[maxn];
long long s1[maxn],s2[maxn];
int main()
{
	int N,M;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=N;i++)s1[i]=s1[i-1]+a[i];
	scanf("%d",&M);
	for(int i=1;i<=M;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=M;i++)s2[i]=s2[i-1]+b[i];
	if(s1[N]!=s2[M])printf("-1\n");
	else{
		int ans=N;
		for(int i=1;i<=N;i++){
			int ps=lower_bound(s2+1,s2+1+M,s1[i])-s2;
			if(s2[ps]!=s1[i])ans--;
		}
		printf("%d\n",ans);
	}
}
