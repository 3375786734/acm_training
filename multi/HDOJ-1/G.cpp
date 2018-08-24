#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+100;
int a[maxn],vis[maxn];
int main()
{
	a[1]=a[2]=1;
	rep(i,3,100)a[i]=a[i-a[i-1]]+a[i-1-a[i-2]];
	rep(i,1,100)printf("%d\n",a[i]);
    rep(i,1,100)
		if(vis[a[i]]==0){
			printf("ps%d num %d\n",i,a[i]);vis[a[i]]=1;
		}
}
