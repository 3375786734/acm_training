#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int a[maxn];
int main()
{
	int N,s;
	scanf("%d%d",&N,&s);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+N);
	int mid=(N+1)/2,ans=a[mid]>s?a[mid]-s:s-a[mid];
//	printf("ans %d\n",s);
		if(a[mid]>s){
			for(int i=1;i<mid;i++)
				if(a[i]>s)ans+=a[i]-s;
		}
		else if(a[mid]<s){
			for(int i=mid+1;i<=N;i++)
				if(a[i]<s)ans+=s-a[i];
		}
	printf("%d\n",ans);
}
